// Júlia Campolim de Oste - 10408802

#include <stdio.h>

int bitonicArray(int v[], int i, int f) {
    if(i == f) {
        return v[i];
    }

    int meio = (i + f) / 2;
    int maior = v[meio], aux = v[meio];

    if(v[meio] > v[meio + 1]) {
        aux = bitonicArray(v, i, meio);
    } else {
        aux = bitonicArray(v, meio + 1, f);
    }

    if(maior < aux) {
        return aux;
    }

    return maior;
}

int main() {
    int v[] = {2, 5, 7, 8, 3};
    int n = 5;

    printf("maior elemento: %d\n", bitonicArray(v, 0, n - 1));
    return 0;
}