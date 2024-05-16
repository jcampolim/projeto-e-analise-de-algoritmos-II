#include <stdio.h>
#define MAX 100

void recursivo(char x[], char y[], int m, int n, int i, int j, int tam, int *maior) {
    if(i == m || j == n) {
        if(tam > *maior) {
            *maior = tam;
        }
        return;
    }

    if(x[i] == y[j]) {
        recursivo(x, y, m, n, i + 1, j + 1, tam + 1, maior);
    } else {
        recursivo(x, y, m, n, i + 1, j, tam, maior);
        recursivo(x, y, m, n, i, j + 1, tam, maior);
    }
}

int topDown(char x[], char y[], int m, int n, int i, int j, int memo[][MAX]) {
    if(i == m || j == n) {
        return 0;
    }

    if(memo[i][j] != -1) {
        return memo[i][j];
    }

    if(x[i] == y[j]) {
        memo[i][j] = 1 + topDown(x, y, m, n, i + 1, j + 1, memo);
    } else {
        int aux1 = topDown(x, y, m, n, i + 1, j, memo);
        int aux2 = topDown(x, y, m, n, i, j + 1, memo);

        if(aux1 > aux2) {
            memo[i][j] = aux1;
        } else {
            memo[i][j] = aux2;
        }
    }

    return memo[i][j];
}

int bottomUp(char x[], char y[], int m, int n, char b[][MAX]) {
    int c[m][n];

    for(int i = 0; i < m; i++) {
        c[i][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        c[0][i] = 0;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            } else {
                if(c[i][j - 1] > c[i - 1][j]) {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'l';
                } else {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'u';
                }
            }
        }
    }

    return c[m -1][n - 1];
}

void recuperaSequencia(char b[][MAX], char x[], int i, int j) {
    if(i <= 0 && j <= 0) {
        return;
    } 
    
    if(b[i][j] == 'd') {
        recuperaSequencia(b, x, i - 1, j - 1);
        printf("%c ", x[i - 1]);
    } else {
        if(b[i][j] == 'u') {
            recuperaSequencia(b, x, i - 1, j);
        } else {
            recuperaSequencia(b, x, i, j - 1);
        }
    }
}

int main() {
    char x[] = {'a', 'b', 'c', 'b', 'd', 'a', 'y'}, y[] = {'b', 'd', 'c', 'a', 'b', 'a'};
    int m = sizeof(x)/sizeof(x[0]) + 1, n = sizeof(y)/ sizeof(y[0]) + 1;

    char b[MAX][MAX];
    int maior = 0, memo[MAX][MAX];

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            memo[i][j] = -1;
        }
    }

    recursivo(x, y, m, n, 0, 0, 0, &maior);
    printf("Solucao recursiva: %d\n", maior);
    printf("Solucao top-down: %d\n", topDown(x, y, m - 1, n - 1, 0, 0, memo));
    printf("Solucao bottom-up: %d\n", bottomUp(x, y, m, n, b));
    recuperaSequencia(b, x, n, m);
    
    return 0;
}