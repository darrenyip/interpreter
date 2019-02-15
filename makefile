CC=gcc
CFLAGS=-I.
DEPS = global.h scanner.h stack.h printer.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

interpreter: main.o stack.o scanner.o printer.o
	$(CC) -o interpreter main.o scanner.o stack.o printer.o

clean:
	-rm -f main.o scanner.o stack.o printer.o
	-rm -f interpreter
