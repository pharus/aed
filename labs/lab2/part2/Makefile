CC=gcc
CFLAGS=-g -Wall -ansi -pedantic

newWords: main.o list.o words.o utils.o
	$(CC) $(CFLAGS) -o newWords main.o list.o words.o utils.o

main.o: main.c list.h words.h utils.h
	$(CC) -c $(CFLAGS) main.c

list.o: list.c list.h words.h utils.h defs.h
	$(CC) -c $(CFLAGS) list.c

words.o: words.c words.h utils.h
	$(CC) -c $(CFLAGS) words.c

utils.o: utils.c utils.h
	$(CC) -c $(CFLAGS) utils.c

clean::
	rm -f *.o core a.out newWords *~



