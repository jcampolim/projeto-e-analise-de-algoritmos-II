#include <stdio.h>
#include <stdbool.h>

bool verificaSegmento(int r[], int s[], int tamR, int tamS) {
    if(tamR > tamS) {
        int i = 0;
        while(i < tamR) {
        if(r[i] == s[0]) {
            int j = i;
            bool ehIgual = true;

            for(int k = 0; k < tamS; k++) {
                if(s[k] != r[j]) {
                    ehIgual = false;
                }

                j++;
            }

            if(ehIgual) return true;
        }
        i++;
        }
    }

    return false;
}

int main() {
    int r[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, s[] = {9};
    int tamR = sizeof(r)/sizeof(r[0]);
    int tamS = sizeof(s)/sizeof(s[0]);

    bool resultado = verificaSegmento(r, s, tamR, tamS);

    if(resultado) {
        printf("O vetor S é segmento do vetor R.");
    } else {
        printf("O vetor S não é segmento do vetor R.");
    }

    return 0;
}