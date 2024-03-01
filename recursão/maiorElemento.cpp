#include <stdio.h>

int maiorElemento(int v[], int n) {
  if (n == 0) {
    return v[n];
  }

  int maior = maiorElemento(v, n - 1);
  if (maior < v[n]) {
    maior = v[n];
  }

  return maior;
}

int heapMaximo(int v[], int i, int n) {
    int maior = v[i-1];

    if((2*i) - 1 < n) {
        int esq = heapMaximo(v, 2*i, n);
        if(esq > maior) {
            maior = esq;
        }
    }
        
    if((2*i) < n) {
        int dir = heapMaximo(v, (2*i)+1, n);
        if(dir > maior) {
            maior = dir;
        }
    }

    return maior;
}

int divisao(int v[], int i, int f) {
  if(i == f) {
    return v[i];
  }

  int meio = (i + f) / 2;

  int direita = divisao(v, i, meio);
  int esquerda = divisao(v, meio + 1, f);

  if(direita > esquerda) {
    return direita;
  } else {
    return esquerda;
  }
}

int main() {
  int v[] = {1, 5, 8, 7, 6, 4, 2};
  int n = 7;

  printf("maior elemento: %d\n", maiorElemento(v, n - 1));
  printf("heap maximo %d\n", heapMaximo(v, 1, n));
  printf("divisão e conquista %d", divisao(v, 0, n-1));

  return 0;
}