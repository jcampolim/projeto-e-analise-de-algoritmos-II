#include <stdio.h>

#define MAXN 8

void printTabuleiro(int n, int tabuleiro[][MAXN]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool cavalo(int n, int tabuleiro[][MAXN], int line, int column, int i, int x[], int y[]) {
    if(i == (n * n)) {
        printTabuleiro(n, tabuleiro);
        return true;
    } else {
        int l, c;
        for(int k = 0; k < 8; k++) {
            l = line + x[k];
            c = column + y[k];

            if((l >= 0 && l < n) && (c >= 0 && c < n)) {
                if(tabuleiro[l][c] == -1) {
                    tabuleiro[l][c] = i;

                    bool aux = cavalo(n, tabuleiro, l, c, i + 1, x, y);
                    if(aux) {
                        return true;
                    } else {
                        tabuleiro[l][c] = -1;
                    }
                }
            }
        }
        return false;
    }
}

int main() {
    int n = 8, tabuleiro[MAXN][MAXN];

    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tabuleiro[i][j] = -1;
        }
    }

    tabuleiro[0][0] = 0;

    cavalo(n, tabuleiro, 0, 0, 1, x, y);

    return 0;
}