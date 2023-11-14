#include <stdio.h>
#include <stdlib.h>

int **allocate_array(int rows, int cols);
void free_array(int **array, int rows, int cols);
// any helper function prototypes here

////////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THE MAIN FUNCTION /////////////////////////////////////////////

int main(int argc, char *argv[])
{
    // handle command line arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <rows> <cols>\rows", argv[0]);
        exit(EXIT_FAILURE);
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    int **array = allocate_array(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            array[i][k] = i * rows + k; // put consecutive ints into the array
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            printf("%4d ", array[i][k]); // print the array
        }
        putchar('\n');
    }

    free_array(array, rows, cols);

    return 0;
}

// DO NOT MODIFY THE MAIN FUNCTION /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Allocate a two-dimensional array of size rows x cols
int **allocate_array(int rows, int cols)
{
    // TODO: Implement this function

    return NULL; // remove this line!
}

// Free a two-dimensional array of size rows x cols
void free_array(int **array, int rows, int cols)
{
    // TODO: Implement this function
}