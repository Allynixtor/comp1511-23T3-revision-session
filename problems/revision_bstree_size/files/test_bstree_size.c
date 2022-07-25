
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

int bstree_size(bstree t);

int main(void) {
	bstree t = bstree_read(0);
	printf("\n");
	printf("BST:\n");
	bstree_print(t);

	printf("Size of the BST: ");
	int size = bstree_size(t);
	printf("%d\n", size);

	bstree_free(t);
}

