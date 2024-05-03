#include <stdio.h>

#define INF 99999999

int min(int a, int b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

int topDown(int moedas[], int memo[], int n, int t) {
    if(t == 0) {
        return 0;
    }

    if(t < 0) {
        return INF;
    }

    if(memo[t] != -1) {
        return memo[t];
    }

    int menor = INF;
    for(int i = 0; i < n; i++) {
        menor = min(menor, topDown(moedas, memo, n, t - moedas[i]) + 1);
    }

    return memo[t] = menor;
}

int bottomUp(int moedas[], int n, int t) {
    int troco[t + 1];
    for(int i = 0; i <= t; i++) {
        troco[i] = INF;
    }

    troco[0] = 0;
    for(int i = 1; i <= t; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= moedas[j]) {
                troco[i] = min(troco[i], troco[i - moedas[j]] + 1);
            }
        }
    } 

    return troco[t];
}

int main() {
    int moedas[] = {1, 4, 6}, t = 8;
    int n = sizeof(moedas)/sizeof(moedas[0]);

    int memo[t + 1];
    for(int i = 0; i <= t; i++) {
        memo[i] = -1;
    }

    printf("Solucao top-down: %d\n", topDown(moedas, memo, n, t));
    printf("Solucao bottom-up: %d\n", bottomUp(moedas, n, t));

    return 0;
}