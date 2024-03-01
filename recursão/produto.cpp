#include <stdio.h>

int produto(int a, int b) {
  if (b == 1) {
    return a;
  } else {
    return produto(a, b - 1) + a;
  }
}

int main() {
  int a = 2, b = 9;
  printf("%d * %d = %d", a, b, produto(a, b));

  return 0;
}