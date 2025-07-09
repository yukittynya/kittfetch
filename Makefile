CFLAGS = -Werror -O1
CC = clang 
VPATH = src:src/info:build:build/bin

build/bin/kittfetch : main.o distro.o
	mkdir build/bin
	$(CC) $(CFLAGS) $? -o $@

build/main.o : main.c 
	mkdir build
	$(CC) $(CFLAGS) -c $? -o $@

build/distro.o : distro.c 
	$(CC) $(CFLAGS) -c $? -o $@

.PHONY = clean
clean :
	rm -rvf build

.PHONY = run
run : clean kittfetch
	./build/bin/kittfetch
