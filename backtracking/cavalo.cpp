#include <stdio.h>

#define MAXN 8

void printTabuleiro(int n, int tabuleiro[][MAXN]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void cavalo(int n, int tabuleiro[][MAXN], int line, int column, int i) {
    if(n == n*n) {
        printTabuleiro(n, tabuleiro);
    } else {
        // 8 recursões
    }
}

int main() {
    int n = 8, tabuleiro[MAXN][MAXN];
    cavalo(n, tabuleiro, 0, 0, 0);

    return 0;
}