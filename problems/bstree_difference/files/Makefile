
CC = gcc
CFLAGS = -O2 -Wall -g

all: test_bstree_difference

test_bstree_difference: test_bstree_difference.c bstree_difference.c bstree.c
	$(CC) $(CFLAGS) -o test_bstree_difference test_bstree_difference.c bstree_difference.c bstree.c

clean:
	rm -f test_bstree_difference
