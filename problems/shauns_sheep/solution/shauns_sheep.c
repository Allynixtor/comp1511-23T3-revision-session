#include <stdio.h>
#include <stdlib.h>

int check_blocked(int *road, int col) {
    int blocked = 0;
    for (int i = -1; i <= 1; ++i) {
        if (road[col+i] == 1) {
            blocked += 1;
        }
    }
    return blocked;
}

int main() {
    int max_col = 0, minutes = 0, blocked = 0;
    scanf(" %d %d", &max_col, &minutes);
    // int road[2][100000] = { 0 };
    // This is an alternative ^
    int **road = malloc(2 * sizeof(int*));
    road[0] = malloc((max_col + 2) * sizeof(int));
    road[1] = malloc((max_col + 2) * sizeof(int));
    for (int i = 0; i < max_col + 2; ++i) {
        road[0][i] = 0;
        road[1][i] = 0;
    }
    for (int i = 0; i < minutes; ++i) {
        int row = 0, col = 0;
        scanf(" %d %d", &row, &col);
        road[row-1][col] = !road[row-1][col];
        int res = check_blocked(road[2 - row], col);
        if (res) {
            if (road[row-1][col]) {
                blocked += res;
            } else {
                blocked -= res;
            }
        }
        if (blocked) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}
