#include <stdio.h>
#include <stdlib.h>

void somaAdjacentes(int s[], int n, int *maior) {
    int soma = 0;
    for(int i = 1; i < n; i++) {
        soma += abs(s[i-1] - s[i]);
    }

    if(*maior < soma) {
        *maior = soma;
    }
}

void permutacoes(int v[], int s[], int usados[], int i, int n, int *maior) {
  if(i == n) {
    somaAdjacentes(s, n, maior);
  } else {
    for(int j = 0; j < n; j++) {
      if(usados[j] == 0) {
        s[i] = v[j];
        usados[j] = 1;

        permutacoes(v, s, usados, i+1, n, maior);
        usados[j] = 0;
      }            
    }
  }
}

int main() {
    int v[] = {4, 2, 1, 5};
    int n = sizeof(v)/sizeof(v[0]), maior = 0;

    int s[n], usados[n];
    for(int i = 0; i < n; i++) {
      usados[i] = 0;
    }

    permutacoes(v, s, usados, 0, n, &maior);
    printf("\n%d\n", maior);
    return 0;
}