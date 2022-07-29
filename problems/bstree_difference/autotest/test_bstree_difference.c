
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

int bstree_difference(bstree t);

int main(void) {
	bstree t = bstree_read(0);
	int size = bstree_difference(t);
	printf("%d\n", size);
	bstree_free(t);
}
