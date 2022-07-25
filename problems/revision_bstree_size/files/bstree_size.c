
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

int bstree_size(bstree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + bstree_size(t->left) + bstree_size(t->right);
	}
}

