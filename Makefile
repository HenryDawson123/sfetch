PREFIX ?= /usr

all:
	@echo Run \'make install\' to install sfetch

install:
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@g++ main.cpp -o sfetch
	@mv sfetch $(DESTDIR)$(PREFIX)/bin/sfetch

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/sfetch
