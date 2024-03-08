#include <stdio.h>

int verificaLexicograficamente(int r[], int s[], int tamR, int tamS) {
    int menor = tamR;
    if(menor > tamS) menor = tamS;

    for(int i = 0; i < menor; i++) {
        if(r[i] > s[i]) {
            return -1;
        } else if(r[i] < s[i]) {
              return 1;
        }
     }

    if(tamR > tamS) return -1;
    if(tamR < tamS) return 1;
    return 0;
}

int main() {
    int r[] = {1, 3, 5, 7}, s[] = {1, 3, 5, 7};
    int tamR = sizeof(r)/sizeof(r[0]);
    int tamS = sizeof(s)/sizeof(s[0]);

    int resultado = verificaLexicograficamente(r, s, tamR, tamS);
    if(resultado == 1) {
        printf("A sequencia R é menor que a sequencia S.");
    } else if(resultado == 0) {
        printf("As sequencias R e S são iguais.");
    } else {
        printf("A sequencia R é maior que a sequencia S.");
    }

    return 0;
}