#include <stdio.h>
#include <stdbool.h>

bool verificaSubsequencia(int r[], int s[], int tamR, int tamS) {
    if(tamR > tamS) {
        int j = 0;
        for(int i = 0; i < tamR; i++) {
            if(r[i] == s[j]) {
                j++;
                if(j == tamS) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int r[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, s[] = {1, 8, 7};
    int tamR = sizeof(r)/sizeof(r[0]);
    int tamS = sizeof(s)/sizeof(s[0]);


    bool resultado = verificaSubsequencia(r, s, tamR, tamS);

    if(resultado) {
        printf("S é uma subsequencia de R.");
    } else {
        printf("S não é uma subsequencia de R.");
    }

    return 0;
}