
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "bstree.h"

int bstree_difference(bstree t) {
	if (t == NULL) {
		return INT_MAX;
	}
	while (t->left != NULL) {
		t = t->left;
	}
	int prev = t->value;
	int ans = INT_MAX;
	while (true) {
		if (t->right != NULL) {
			t = t->right;
			while (t->left != NULL) {
				t = t->left;
			}
		} else {
			while (true) {
				if (t->parent == NULL) {
					return ans;
				}
				bstree prev_bstree = t;
				t = t->parent;
				if (t->left == prev_bstree) {
					break;
				}
			}
		}
		if (t->value - prev < ans) {
			ans = t->value - prev;
		}
		prev = t->value;
	}
}
