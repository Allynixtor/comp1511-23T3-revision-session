#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exact_price_or_not.h"


// Declare any helper functions you need here.
// ...

/*
 * Complete the 'sumCoins' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER price
 *  2. INTEGER_ARRAY coins
 */

int sumCoins(int price, int coins_count, int *coins) {
    // TODO: Implement a working solution here.
    // ...
    int i = 0;
    while (i < coins_count) {
        int j = 1;
        while (j < coins_count) {
            int k = 2;            
            while (k < coins_count) {
                if (coins[i] + coins[j] + coins[k] == price && i != j && j != k && k != i) {
                    // printf("%d %d %d", i, j, k);
                    // printf("%d %d %d", coins[i], coins[j], coins[k]);
                    return 1;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return 0;
}
