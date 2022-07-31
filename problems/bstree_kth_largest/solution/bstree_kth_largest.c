
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

// Declare any helper functions you need here.
// ...

bstree *kthlargest_helper(bstree *t, int *k) {
    if (t == NULL) return NULL;
    bstree *r = kthlargest_helper(t->right, k);
    if (r != NULL) return r;

    (*k)--;

    if (*k == 0) return t;

    return kthlargest_helper(t->left, k);
}

/**
 * Determine the kth largest value in the bstree t. The definition of the bstree struct can be found in
 * bstree.h.
 *
 * Input:
 *  Pointer to the root of a bstree t, a positive integer k.
 * Output:
 *  The value of the kth largest element in t.
 */
int kthlargest(bstree *t, int k) {
    return kthlargest_helper(t, &k)->value;
}

