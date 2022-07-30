
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
 * For example, if the preorder traversal is 11 7 4 20 18 23 30, the BST is
 *      11
 *     /  \
 *    /    \
 *   7     20
 *  /     /  \
 * 4     /    \
 *      18    23
 *              \
 *              30
 * and the answer is 20 - 18 = 2.
 *
 * Any efficient solution, such as one that runs in O(n) or O(n log n), should
 * pass the autotests, but the following are some extra challenges:
 *   - Solve the problem using O(h) additional space, where h is the height
 *     of the BST. Hint: consider performing an inorder traversal of the BST.
 *   - Solve the problem using O(1) additional space. Hint: think about what
 *     functionality the provided bstree_node struct offers.
 * Additional space refers to any space allocated between the time that the
 * function bstree_difference is called and the time it returns.
 * 
 * Input:
 *   - bstree: a pointer to the root of the BST, see bstree.h for more info.
 * Output:
 *   - int: the minimum difference between any two values in the BST.
 */

int bstree_difference(bstree t) {
	return 7;
}
