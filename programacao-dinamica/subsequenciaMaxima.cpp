#include <stdio.h>
#define MAX 100

int recursivo() {

}

int topDown() {
    
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
    if(i < 0 && j < 0) {
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
    char x[] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'}, y[] = {'b', 'd', 'c', 'a', 'b', 'a'};
    int m = sizeof(x)/sizeof(x[0]) + 1, n = sizeof(y)/ sizeof(y[0]) + 1;

    char b[MAX][MAX];

    printf("Solucao bottom-up: %d\n", bottomUp(x, y, m, n, b));
    recuperaSequencia(b, x, n, m);
    return 0;
}