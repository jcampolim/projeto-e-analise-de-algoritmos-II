#include <stdio.h>

int horner(int c[], int x, int n) {
    if(n == 0) {
        return c[0];
    }

    return (horner(c, x, n - 1) * x) + c[n];
}

int main() {
    int c[] = {4, 5, 2, 5};
    int n = (sizeof(c)/sizeof(c[0])) - 1, x = 10;

    printf("%d", horner(c, x, n));

    return 0;
}