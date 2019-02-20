CC=gcc
CFLAGS=-I.
DEPS = global.h scanner.h stack.h printer.h rpn.h util.h tokenTable.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

interpreter: main.o stack.o scanner.o printer.o rpn.o tokenTable.o
	$(CC) -o interpreter main.o scanner.o stack.o printer.o rpn.o tokenTable.o

clean:
	-rm -f main.o scanner.o stack.o printer.o rpn.o tokenTable.o
	-rm -f interpreter
