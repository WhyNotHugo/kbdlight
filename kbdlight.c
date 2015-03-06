#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLPATH		"/sys/class/leds/smc::kbd_backlight"
#define BLVALFILE	BLPATH "/brightness"
#define BLMAXFILE	BLPATH "/max_brightness"
#define BLCHANGE	16

void usage() {
    printf("Usage: kbdlight [up [<percentage>]|down [<percentage>]|off|max|get|set <value>]\n");
    exit(0);
}

int main(int argc, char* argv[]) {
  int current, change, next, maxval;
  FILE *file;

  if (argc < 2) {
    usage();
  }

  if(!(file = fopen(BLVALFILE, "r"))) {
    perror("failed to open the keyboard backlight file: " BLVALFILE);
    return 1;
  }
  fscanf(file, "%d", &current);
  fclose(file);

  if((file = fopen(BLMAXFILE, "r"))) {
    fscanf(file, "%d", &maxval);
    fclose(file);
  } else {
    maxval = 255;
  }

  if (!strcmp(argv[1], "up") || !strcmp(argv[1], "down")) {
    if (argv[2]) {
      char *endp;

      change = strtol(argv[2], &endp, 10);

      if (endp == argv[2]) {
        fprintf(stderr, "percentage must be a number from 0 to 100.\n");
        return 1;
      }

      change = change * 0.01 * maxval;
    } else {
      change = BLCHANGE;
    }
  }

  if (!strcmp(argv[1], "up"))
    next = current >= maxval - change ? maxval : current + change;
  else if (!strcmp(argv[1], "down"))
    next = current <= change ? 0 : current - change;
  else if (!strcmp(argv[1], "off"))
    next = 0;
  else if (!strcmp(argv[1], "max"))
    next = 255;
  else if (!strcmp(argv[1], "set")) {
    char *endp;
    if(!argv[2] || (next = strtol(argv[2], &endp, 10), endp == argv[2])) {
      fprintf(stderr, "set must be followed by a number from 0 to %d\n", maxval);
      return 1;
    }
  } else if(!strcmp(argv[1], "get")) {
    printf("%d\n", current);
    return 0;
  } else
    usage();

  if((file = fopen(BLVALFILE, "w"))) {
    fprintf(file, "%d", next);
    fclose(file);
  } else {
    perror("failed to write to the keyboard backlight file: " BLVALFILE);
  }
  return 0;
}
