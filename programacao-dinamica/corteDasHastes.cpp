#include <stdio.h>
#define INF -999999999

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int recursivo(int preco[], int n) {
    if(n == 0) {
        return 0;
    }

    int q = 0;

    for(int i = 1; i <= n; i++) {
        q = max(q, preco[i] + recursivo(preco, n - i));
    }

    return q;
}

int topDown(int p[], int n, int r[]) {
    if(r[n] >= 0) {
        return r[n];
    }

    if(n == 0) {
        return 0;
    }

    int q = INF;

    for(int i = 1; i <= n; i++) {
        q = max(q, p[i] + topDown(p, n - i, r));
    }

    r[n] = q;
    return q;
}

int bottomUp(int p[], int n) {
    int r[n];
    for(int i = 0; i < n; i++) {
        r[i] = 0;
    }

    for(int j = 1; j < n; j++) {
        int q = INF;
        for(int i = 1; i <= j; i++) {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }

    return r[n - 1];
}

int main() {
    int preco[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = sizeof(preco)/sizeof(preco[0]);

    int r[n];
    for(int i = 0; i < n; i++) {
        r[i] = -1;
    }

    printf("Solucao recursiva: %d\n", recursivo(preco, n - 1));
    printf("Solucao top-down: %d\n", topDown(preco, n - 1, r));
    printf("Solucao bottom-up: %d\n", bottomUp(preco, n));

    return 0;
}