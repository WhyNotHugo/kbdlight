#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
    printf("Usage: kbdlight [up|down|off|max]\n");
    exit(0);
}

int main(int argc, char* argv[]) {
  int current, next;
  FILE *file;

  if (argc != 2) {
    usage();
  }

  file = fopen("/sys/class/leds/smc::kbd_backlight/brightness", "r");
  fscanf(file, "%d", &current);
  fclose(file);

  if (!strcmp(argv[1], "up"))
    next = current + 16;
  else if (!strcmp(argv[1], "down"))
    next = current - 16;
  else if (!strcmp(argv[1], "off"))
    next = 0;
  else if (!strcmp(argv[1], "max"))
    next = 255;
  else
    usage();

  file = fopen("/sys/class/leds/smc::kbd_backlight/brightness", "w");
  fprintf(file, "%d", next);
  fclose(file);
  return 0;
}
