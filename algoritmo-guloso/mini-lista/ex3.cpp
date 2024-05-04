#include <stdio.h>

int calcVidas(int salas[], int n) {
    int soma = salas[0], somaAtual = 0;

    for(int i = 1; i < n; i++) {
        somaAtual += salas[i];

        if(soma < somaAtual) {
            soma = somaAtual;
        }

        if(somaAtual < 0) {
            somaAtual = 0;
        } 
    }
    
    return soma;
}

int main() {
    int n;
    scanf("%d", &n);

    int salas[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &salas[i]);
    }

    printf("%d\n", calcVidas(salas, n));

    return 0;
}