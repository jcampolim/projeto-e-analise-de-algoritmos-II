#include <stdio.h>

void permutacoes(int v[], int s[], int usados[], int i, int n) {
  if(i == n) {
    for(int i = 0; i < n; i++) {
      printf("%d", s[i]);
    }
    printf(" ");
  } else {
    for(int j = 0; j < n; j++) {
      if(usados[j] == 0) {
        s[i] = v[j];
        usados[j] = 1;

        permutacoes(v, s, usados, i+1, n);
        usados[j] = 0;
      }            
    }
  }
}

int main() {
  int v[] = {1, 2, 3};
    int n = sizeof(v)/sizeof(v[0]);

    int s[n], usados[n];
    for(int i = 0; i < n; i++) {
      usados[i] = 0;
  }

    permutacoes(v, s, usados, 0, n);
    return 0;
}