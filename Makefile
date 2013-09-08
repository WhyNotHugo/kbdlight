all:
	gcc kbdlight.c -o kbdlight
clean:
	rm kbdlight
install:
	install -Dm 4755 kbdlight ${DESTDIR}/usr/bin/kbdlight
