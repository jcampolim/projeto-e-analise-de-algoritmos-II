#include <stdio.h>

#define MAX 100
#define INF 999999999

int recursivo(int p[], int m[][MAX], int i, int j) {
    if(i == j) {
        return 0;
    }

    m[i][j] = INF;

    for(int k = i; k < j; k++) {
        int q = recursivo(p, m, i, k) + recursivo(p, m, k + 1, j) 
            + (p[i - 1] * p[k] * p[j]);

        if(q < m[i][j]) {
            m[i][j] = q;
        } 
    }

    return m[i][j];
}

int topDown(int p[], int m[][MAX], int s[][MAX], int n) {
    
}

int bottomUp(int p[], int m[][MAX], int s[][MAX], int n) {
    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for(int l = 2; l < n; l++) {
        for(int i = 1; i < (n - l + 1); i++) {
            int j = i + l - 1;
            m[i][j] = INF;

            for(int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);

                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

void imprimeParentesesOtimos(int s[][MAX], int i, int j) {
    if(i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        imprimeParentesesOtimos(s, i, s[i][j]);
        printf(" x ");
        imprimeParentesesOtimos(s, s[i][j] + 1, j);
        printf(")");
    }
}

int maximizaOperacoes(int p[], int m[][MAX], int s[][MAX], int n) {
    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for(int l = 2; l < n; l++) {
        for(int i = 1; i < (n - l + 1); i++) {
            int j = i + l - 1;
            m[i][j] = 0;

            for(int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);

                if(q > m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int p[] = {30, 35, 15, 5, 10, 20};
    int n = sizeof(p)/sizeof(p[0]);
    int m1[MAX][MAX], m2[MAX][MAX], s[MAX][MAX];

    printf("Solucao recursiva: %d\n", recursivo(p, m1, 1, n - 1));
    printf("Solucao programacao dinamica: %d\n", bottomUp(p, m2, s, n));
    imprimeParentesesOtimos(s, 1, n - 1);
    printf("\n");
    printf("Solucao com multiplicacoes maximizadas: %d\n", maximizaOperacoes(p, m2, s, n));
    imprimeParentesesOtimos(s, 1, n - 1);

    return 0;
}