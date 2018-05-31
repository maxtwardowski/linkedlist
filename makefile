
all: llist

llist: llist.o
	gcc -g $^ -o $@ -lm -std="c99"

.c.o:
	gcc -g -std=c99 -c -D_REENTRANT $<

llist.o: llist.c

.PHONY: clean

clean:
	-rm llist llist.o

run:
	./llist
