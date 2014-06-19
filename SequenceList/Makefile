all: sqlist

sqlist.o: sqlist.c sqlist.h
	gcc -Wall -pedantic -std=gnu99 -g -c sqlist.c -o sqlist.o

sqlist:sqlist.o sqlist_test.c
	gcc -Wall -pedantic -std=gnu99 -g -pthread sqlist_test.c sqlist.o -o sqlist
