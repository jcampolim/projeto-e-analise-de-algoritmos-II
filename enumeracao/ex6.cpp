#include <stdio.h>

int maiorSubsequencia(int v[], int n) {
    int maior = 1, cont = 1;

    for(int i = 1; i < n; i++) {
        if(v[i] > v[i-1]) {
            cont++;
        } else {
            if(cont > maior) {
                maior = cont;
            }
            cont = 1;
        }
    }

    return maior;
}

int main() {
    int v[] = {10, 8, 7, 5, 2};
    int n = sizeof(v)/sizeof(v[0]);

    printf("O tamanho da maior subsequencia crescente é: %d\n", maiorSubsequencia(v, n));

    return 0;
}