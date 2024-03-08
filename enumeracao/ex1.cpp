#include <stdio.h>
#include <stdbool.h>

bool verificaLexicograficamente(int r[], int s[], int tamR, int tamS) {
    int menor = tamR;
    if(menor > tamS) menor = tamS;

    for(int i = 0; i < menor; i++) {
        if(r[i] > s[i]) {
            return false;
        }
    }

    if(tamR > tamS) return false;
        return true;
    }

int main() {
    int r[] = {1, 3, 6}, s[] = {1, 3, 5, 7};
    int tamR = sizeof(r)/sizeof(r[0]);
    int tamS = sizeof(s)/sizeof(s[0]);

    bool resultado = verificaLexicograficamente(r, s, tamR, tamS);
    if(resultado) {
        printf("A sequencia R é menor que a sequencia S.");
    } else {
        printf("A sequencia R não é menor que a sequencia S.");
    }
}