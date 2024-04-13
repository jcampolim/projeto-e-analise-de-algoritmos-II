#include <stdio.h>

void print(float m[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%.2f ", m[i]);
    }
    printf("\n");
}

void troca(int m[], int j) {
    int aux = m[j];
    m[j] = m[j + 1];
    m[j + 1] = aux;
}

void bubbleSort(int valor[], int peso[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if((valor[j]/peso[j]) < (valor[j + 1]/peso[j + 1])) {
                troca(valor, j);
                troca(peso, j);
            }
        }
    }
}

void mochilaGuloso(int valor[], int peso[], float x[], int n, int p) {
    bubbleSort(valor, peso, n);

    int i = 0;
    while(i <= n && p > 0) {
        if(peso[i] <= p) {
            x[i] = 1;
            p = p - peso[i];
            i++;
        } else {
            x[i] = p / (peso[i] * 1.0);
            p = 0;
        }
    }   
}

int main() {
    int valor[] = {60, 100, 120}, peso[] = {10, 20, 30}, p = 50;
    int n = sizeof(valor)/sizeof(valor[0]);

    float x[n];

    mochilaGuloso(valor, peso, x, n, p);

    print(x, n);

    return 0;
}