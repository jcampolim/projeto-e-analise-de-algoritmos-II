#include <stdio.h>

float potencia(int x, int n) {
  if (n == 1) {
    return x;
  } else {
    return x * potencia(x, n - 1);
  }
}

float fatorial(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * fatorial(n - 1);
  }
}

float somatoria(int x, int n) {
  if (n == 0) {
    return 1;
  } else {
    return ((potencia(x, n)) / fatorial(n)) + somatoria(x, n - 1);
  }
}

int main() {
  int x = 3, n = 4;
  printf("%f", somatoria(x, n));

  return 0;
}