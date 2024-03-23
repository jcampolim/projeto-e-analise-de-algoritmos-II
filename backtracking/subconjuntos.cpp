#include <stdio.h>

void subconjuntos(int v[], int s[], int usados[], int i, int n) {
  
}

int main() {
    int v[] = {1, 2, 3};
    int n = sizeof(v)/sizeof(v[0]);

    int s[n], usados[n];
    for(int i = 0; i < n; i++) {
      usados[i] = 0;
    }

    subconjuntos(v, s, usados, 0, n);
    return 0;
}