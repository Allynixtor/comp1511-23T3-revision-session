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
 *   - int high: Last index of array
 * Output:
 *   - void
 */

void sort(int *array, int high) {

    //3 cursors - low, curr, high
    //low: First index of unsorted partition
    //High: Last index of unsorted partition
    //curr: index of current unsorted element

    int low = 0;
    int curr = 0;

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

