#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int peso;
    int valor;
} Item;

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int recursivo(Item itens[], int n, int capacidade) {
    if(n < 0 || capacidade <= 0) {
        return 0;
    }

    if(itens[n].peso > capacidade) {
        return recursivo(itens, n - 1, capacidade);
    } else {
        return max(recursivo(itens, n - 1, capacidade), recursivo(itens, n - 1, capacidade - itens[n].peso) + itens[n].valor);
    }
}

int topDown(Item itens[], int memo[][MAX], int n, int capacidade) {
    if(n < 0 || capacidade <= 0) {
        return 0;
    }

    if(memo[n][capacidade] != -1) {
        return memo[n][capacidade];
    }

    if(itens[n].peso > capacidade) {
        memo[n][capacidade] = topDown(itens, memo, n - 1, capacidade);
    } else {
        memo[n][capacidade] = max(topDown(itens, memo, n - 1, capacidade), topDown(itens, memo, n - 1, capacidade - itens[n].peso) + itens[n].valor);
    }

    return memo[n][capacidade];
}

int bottomUp(Item itens[], int memo[][MAX], int n, int capacidade) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= capacidade; j++) {
            if(itens[i].peso > j) {
                memo[i][j] = memo[i - 1][j];
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - itens[i].peso] + itens[i].valor);            
            }
        }
    }

    return memo[n][capacidade];
}

int main() {
    int pesos[] = {3, 2, 4, 1}, valores[] = {8, 3, 9, 6};
    int capacidade = 5, n = sizeof(pesos)/sizeof(pesos[0]);

    Item itens[n];
    int memo[n + 1][MAX];

    for(int i = 0; i < n; i++) {
        itens[i].id = i + 1;
        itens[i].peso = pesos[i];
        itens[i].valor = valores[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacidade; j++) {
            memo[i][j] = -1;
        }
    }

    printf("Solucao backtracking: %d\n", recursivo(itens, n, capacidade));
    printf("Solucao top-down: %d\n", topDown(itens, memo, n, capacidade));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacidade; j++) {
            memo[i][j] = 0;
        }
    }

    printf("Solucao bottom-up: %d\n", bottomUp(itens, memo, n, capacidade));

    return 0;
}