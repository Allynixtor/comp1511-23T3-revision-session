#include <stdio.h>
#include <stdlib.h>

int valid_index(int row, int col,
                int max_row, int max_col);
int max_i(int a, int b);

int eval_x(int row, int col, 
           int max_row, int max_col,
           int **town_hall);

void free_all(int **town_hall, int max_row);

int main() {
    int max_row = 0, max_col = 0;
    scanf(" %d %d", &max_row, &max_col);
    int **town_hall = malloc(max_row * sizeof(int*));
    for (int row = 0; row < max_row; ++row) {
        town_hall[row] = malloc(max_col * sizeof(int));
        for (int col = 0; col < max_col; ++col) {
            scanf(" %d", &town_hall[row][col]);
        }
    }
    int global_max = 0;
    int global_row = 0, global_col = 0;
    for (int row = 0; row < max_row; ++row) {
        for (int col = 0; col < max_col; ++col) {
            int local_max = eval_x(row, col, max_row, max_col, town_hall);
            if (max_i(global_max, local_max) == local_max) {
                global_max = local_max;
                global_row = row;
                global_col = col;
            }
        }
    }
    printf("%d %d %d", global_row, global_col, global_max);
    free_all(town_hall, max_row);
    
}

int valid_index(int row, int col,
                int max_row, int max_col) {
    return (0 <= row) && (row < max_row) && (0 <= col) && (col < max_col);
}

int max_i(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int eval_x(int row, int col, 
           int max_row, int max_col,
           int **town_hall) {
    int local_max = 0;
    if (valid_index(row-1, col-1, max_row, max_col)) {
        local_max += town_hall[row-1][col-1];
    }
    if (valid_index(row-1, col+1, max_row, max_col)) {
        local_max += town_hall[row-1][col+1];
    }
    if (valid_index(row+1, col-1, max_row, max_col)) {
        local_max += town_hall[row+1][col-1];
    }
    if (valid_index(row+1, col+1, max_row, max_col)) {
        local_max += town_hall[row+1][col+1];
    }
    return local_max + town_hall[row][col];
}

void free_all(int **town_hall, int max_row) {
    for (int i = 0; i < max_row; ++i) {
        free(town_hall[i]);
    }
    free(town_hall);
}
