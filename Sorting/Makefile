all: sorting

sorting.o: sorting.c sorting.h
	gcc -Wall -pedantic -std=gnu99 -g -c sorting.c -o sorting.o

sorting:sorting.o sorting_test.c
	gcc -Wall -pedantic -std=gnu99 -g -pthread sorting_test.c sorting.o -o sorting
