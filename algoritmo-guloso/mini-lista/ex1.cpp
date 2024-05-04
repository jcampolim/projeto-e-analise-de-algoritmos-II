#include <stdio.h>

int somaFatorial(int n) {
    int fatoriais[n];
    int f = 1, i = 2, j =0;

    while(f <= n) {
        fatoriais[j] = f;
        f = f * i;
        i = i + 1;
        j = j + 1;
    }
    
    int soma = 0, cont = 0;

    while(soma != n) {
        if(soma + fatoriais[j] <= n) {
            soma = soma + fatoriais[j];
            cont = cont + 1;
        } else {
            j = j - 1;
        }
    }

    return cont;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", somaFatorial(n));

    return 0;
}