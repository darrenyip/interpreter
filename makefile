CC=gcc
CFLAGS=-I.
DEPS = global.h scanner.h stack.h printer.h rpn.h util.h lexer.h tokenLinkedList.h service.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

interpreter: main.o stack.o scanner.o printer.o rpn.o lexer.o tokenLinkedList.o service.o
	$(CC) -o interpreter main.o scanner.o stack.o printer.o rpn.o lexer.o tokenLinkedList.o service.o

clean:
	-rm -f main.o scanner.o stack.o printer.o rpn.o lexer.o tokenLinkedList.o service.o
	-rm -f interpreter
