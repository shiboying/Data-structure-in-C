all: searching

searching.o: StaticSearching.c searching.h
	gcc -Wall -pedantic -std=gnu99 -g -c StaticSearching.c -o searching.o

bst.o: BinarySearchTree.c searching.h
	gcc -Wall -pedantic -std=gnu99 -g -c BinarySearchTree.c -o bst.o

searching:searching.o bst.o searching_test.c
	gcc -Wall -pedantic -std=gnu99 -g -pthread searching_test.c searching.o bst.o -o searching
