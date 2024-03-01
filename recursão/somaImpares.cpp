#include <stdio.h>

int somaImpares(int n) {
  if (n == 1) {
    return 1;
  } else {
    return ((2 * n) - 1) + somaImpares(n - 1);
  }
}

int main() {
  int n = 3;
  printf("n = %d\n", n);
  printf("soma dos impares = %d", somaImpares(n));

  return 0;
}