PREFIX = /usr/local

obj = kbdlight.o
bin = kbdlight

$(bin): $(obj)
	$(CXX) -ggdb -std=c++0x -o $@ $(obj) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) $(bin)

.PHONY: install
install:
	install -Dm 4755 $(bin) $(DESTDIR)$(PREFIX)/bin/$(bin)

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(bin)
