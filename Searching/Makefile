all: searching

searching.o: StaticSearching.c searching.h
	gcc -Wall -pedantic -std=gnu99 -g -c StaticSearching.c -o searching.o

bst.o: BinarySearchTree.c searching.h
	gcc -Wall -pedantic -std=gnu99 -g -c BinarySearchTree.c -o bst.o

avl.o: AVLTree.c searching.h
	gcc -Wall -pedantic -std=gnu99 -g -c AVLTree.c -o avl.o

searching:searching.o bst.o avl.o searching_test.c
	gcc -Wall -pedantic -std=gnu99 -g -pthread searching_test.c searching.o bst.o avl.o -o searching
