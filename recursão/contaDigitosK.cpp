#include <stdio.h>

int digito(int n, int k) {
  if (n == 0) {
    return 0;
  } else {
    if (n % 10 == k) {
      return 1 + digito(n / 10, k);
    } else {
      return 0 + digito(n / 10, k);
    }
  }
}

int main() {
  int n = 291122267, k = 2;

  printf("%d", digito(n, k));

  return 0;
}