
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

// Declare any helper functions you need here.
// ...

/**
 * Determines the minimum difference between any two values in the given
 * binary search tree. You may assume that the BST has at least two nodes.
 * The testing code reads the preorder traversal of the BST from stdin.
 * 
 * Input:
 *   - bstree: a pointer to the root of the BST, see bstree.h for more info.
 * Output:
 *   - int: the minimum difference between any two values in the BST.
 */
bstree *kthlargest_helper(bstree *t, int *k) {
    if (t == NULL) return NULL;
    bstree *r = kthlargest_helper(t->right, k);
    if (r != NULL) return r;

    (*k)--;

    if (*k == 0) return t;

    return kthlargest_helper(t->left, k);
}

int kthlargest(bstree *t, int k) {
    return kthlargest_helper(t, &k)->value;
}

