all: linkedlist

linkedlist.o: linkedlist.c linkedlist.h
	gcc -Wall -pedantic -std=gnu99 -g -c linkedlist.c -o linkedlist.o

linkedlist:linkedlist.o linkedlist_test.c
	gcc -Wall -pedantic -std=gnu99 -g -pthread linkedlist_test.c linkedlist.o -o linkedlist
