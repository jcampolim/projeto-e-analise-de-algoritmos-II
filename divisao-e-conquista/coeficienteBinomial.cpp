// Júlia Campolim de Oste - 10408802

#include <stdio.h>

int coeficienteBinomial(int n, int m) {
    if(n == m || m == 0) {
        return 1;
    } else {
        return coeficienteBinomial(n-1, m) + coeficienteBinomial(n-1, m-1);
    }
}

int main() {
    printf("coeficiente binomial %d", coeficienteBinomial(5, 2));
    return 0;
}