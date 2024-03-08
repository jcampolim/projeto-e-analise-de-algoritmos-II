#include <stdio.h>

int qtdeSubsequencias(int v[], int n) {
    int cont = 1, iguais = v[0];

    for(int i = 0; i < n; i++) {
        if(v[i] != iguais) {
            iguais = v[i];
            cont++;
        }
    }

    return cont;
}

int main() {
    int v[] = {3, 3, 1, 1, 1, 12, 12, 12, 3, 3};
    int n = sizeof(v)/sizeof(v[0]);

    int qtde = qtdeSubsequencias(v, n);
    printf("A quantidade de subsequencias do vetor V é: %d\n", qtde);

    return 0;
}