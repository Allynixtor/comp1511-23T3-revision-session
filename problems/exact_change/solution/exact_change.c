#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    int n;
    scanf("%d", &n);
    int vals[16];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (vals[i] + vals[j] + vals[k] == p) {
                    printf("1\n");
                    return 0;
                }
            }
        }
    } 
    printf("0\n");
}