#include <stdio.h>

int potencia(int x, int n) {
  if (n == 1) {
    return x;
  } else {
    return x * potencia(x, n - 1);
  }
}

int main() {
  int x = 2, n = 3;
  printf("%d ^ %d = %d", x, n, potencia(x, n));

  return 0;
}