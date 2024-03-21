#include <stdio.h>

void binarios(int n, int b[], int i) {
    if(i == n) {
        for(int j = 0; j < n; j++) {
            printf("%d", b[j]);
        }
        printf(" ");
    } else {
        b[i] = 0;
        binarios(n, b, ++i);
        i--;

        b[i] = 1;
        binarios(n, b, ++i);
        i--;
    }
}

int main() {
    int n = 3;
    int b[n];

    binarios(n, b, 0);

    return 0;
}