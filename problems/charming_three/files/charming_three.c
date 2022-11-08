#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort_three(int *x, int *y, int *z);

int main() {
    int x, y, z;
    
    scanf("%d %d %d", &x, &y, &z);
    sort_three(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);

    return 0;
}

/*
    Takes in three float pointers and sorts the values
    they point to in increasing order.
*/
void sort_three(int *x, int *y, int *z) {
    // TODO: Implement this function :)

}
