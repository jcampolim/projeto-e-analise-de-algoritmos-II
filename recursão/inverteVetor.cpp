#include <stdio.h>

void inverteVetor(int v[], int i, int f) {
  if(i >= f) {
    return;
  } else {
    int aux = v[i];
    v[i] = v[f];
    v[f] = aux;

    inverteVetor(v, i+1, f-1);
  }
}

int main() {
  int v[] = {1, 5, 2, 7, 6, 4, 8};
  int n = 7, i;

  for(i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }	

  printf("\n");
  inverteVetor(v, 0, n-1);

  for(i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }	

  return 0;
}