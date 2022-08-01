#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"

// Helper function to swap elements `array[i]` and `array[j]` in an array
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * Sorts the array of ints
 *
 * Input:
 *   - int *array: An array of ints
 *   - int size: Number of elements in the array
 * Output:
 *   - void
 */

void sort(int *array, int size) {

    //3 cursors - low, curr, high
    //low: First index of unsorted partition
    //High: Last index of unsorted partition
    //curr: index of current unsorted element

    int low = 0;
    int curr = 0;
    int high = size - 1;

    //Sort until curr cursor passes high cursor, as anything to right of
    //high cursor is guarenteed to be sorted from previous sorts

    while (curr <= high) {

        //Case1: current element is 0
        if (array[curr] == 0)
        {
            swap(array, low, curr);
            low++;
            curr++;
        }
        //Case2: current element is 2
        else if (array[curr] == 2)
        {
            swap(array, curr, high);
            high--;
        }
        //Case3: current element is 1
        else {
            curr++;
        }
    }
}

#Explaination

/*
Aim: We want all the 0's on LHS of the array, and all the 2's on the RHS
of the array. This leaves the remaining 1's to be in the middle of array, 
thus producing a sorted array. 

Methodology:

To keep track of which elements in the array needs to be sorted, we use 
3 cursors: low, curr, and high. 

low: Tracks first index of the unsorted partition of array (initialised to 0)
High: Tracks last index of the unsorted partition of array (intilaised to last index of array)
curr: Tracks index of current unsorted element (initialised to 0)

Initially, the array is assumed to be unsorted. Hence low will be initialised to
the first index 0, high will be initialised to the last index of array, and curr
will be initialised to first index 0 as we sort elements left to right. 

Now, if the current element is 0, then we want it on the LHS of the array.
Since the low cursor points to the first index of the unsorted 
partition (LHS of array), we swap the current element with the element the 
low cursor is pointing to. Now that we know 0 is in the correct side of the "sorted"
array, we decrease the size of the unsorted partition by incrementing the 
low cursor. We also move on to sort the next element in array by incremeting
the curr cursor. 

However, if the current element is 2, then we want it on the RHS of the array.
Since the high cursor points to the last index of the unsorted 
partition (RHS of array), we swap the current element with the element the 
high cursor is pointing to. Now that 2 is in the correct side of the "sorted"
array, we decrease the size of the unsorted partition by decrementing the 
high cursor. However, unlike when our current element was a 0, we don't sort the next
element in the array by incrementing the curr cursor just yet. The reason is because
the element the high cursor was pointing to, now in curr's index, itself is
not guaranteed to be in the correct order.

    For example, if we had the array
    0 1 2 0 0, where low points to 1, curr points to 2, and high points to 0.
    Since the current element is 2, then we need to swap it with the last index in
    the unsorted partition which in this example is the second 0. This results
    in an array of 0 1 0 0 2. But as you can see, the 0 we swapped 2 with, itself
    is not correctly sorted as it comes after 1. So we have to consider sorting
    the new current element of 0, and not the next element in array by incrementing just yet.

Now if the current element is 1, then we don't want to swap it with another element
so its on the LHS or RHS of the array. We want to leave it alone. 
Thus, we just increment the curr cursor to sort the next element in the array.

This process repeats until the curr cursor passes the high cursor, as
anything to the right of the high cursor is guarenteed to be sorted from
previous sorts.  


*/

