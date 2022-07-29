
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "bstree.h"

void dfs(bstree t, int **upto) {
    if (t == NULL) {
        return;
    }
    **upto = t->value;
    *upto += 1;
    dfs(t->left, upto);
    dfs(t->right, upto);
}

int comp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int bstree_difference(bstree t) {
	int *arr = malloc(MAX_BST_SIZE * sizeof(int));
    int *end = arr;
    dfs(t, &end);
    qsort(arr, end - arr, sizeof(int), comp);
    int ans = INT_MAX;
    for (int *i = arr; i + 1 != end; i++) {
        int diff = *(i+1) - *i;
        if (diff < ans) {
            ans = diff;
        }
    }
    return ans;
}
