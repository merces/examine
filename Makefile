all:
	gcc -O2 -Wall -o examine examine.c -lm

install:
	install -m 0755 examine /usr/local/bin/examine
	ln -s /usr/local/bin/examine /usr/local/bin/x

uninstall:
	rm -f /usr/local/bin/examine
	rm -f /usr/local/bin/x

clean:
	rm -f examine
