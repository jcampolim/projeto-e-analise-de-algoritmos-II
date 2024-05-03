#include <stdio.h>

int recursivo(int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return recursivo(n - 1) + recursivo(n - 2);
    }
}

int topDown(int n, int memo[]) {
    if(memo[n] != -1) {
        return memo[n];
    } else if(n == 0 || n == 1) {
        memo[n] = n;
    } else {
        memo[n] = topDown(n - 1, memo) + topDown(n - 2, memo);
    }
    return memo[n];
}

int bottomUp(int n, int tab[]) {
    tab[0] = 0;
    tab[1] = 1;

    for(int i = 2; i <= n; i++) {
        tab[i] = tab[i - 1] + tab[i - 2];
    }

    return tab[n];
}

int main() {
    int n = 6;
    int fibonacci[n];

    printf("Fibonacci de %d: \n\n", n);
    printf("Solucao recursiva: %d\n\n", recursivo(n));

    int memo[n + 1];
    for(int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    printf("Solucao top-down: %d\n", topDown(n, memo));
    printf("Vetor resultante: ");
    for(int i = 0; i <= n; i++) {
        printf("%d ", memo[i]);
    }

    printf("\n\n");

    int tab[n + 1];
    printf("Solucao bottom-up: %d\n", bottomUp(n, tab));
    printf("Vetor resultante: ");
    for(int i = 0; i <= n; i++) {
        printf("%d ", tab[i]);
    }

    return 0;
}