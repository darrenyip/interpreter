CC=gcc
CFLAGS=-I.
DEPS = global.h scanner.h stack.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

interpreter: main.o stack.o scanner.o
	$(CC) -o interpreter main.o scanner.o stack.o

clean:
	-rm -f main.o scanner.o stack.o
	-rm -f interpreter
