#include <stdio.h>

void mostraSequencia(int v[], int s[], int i, int nv, int ns) {
    if(ns == i) {
        for(int j = 0; j < ns; j++) {
            printf("%d", s[j]);
        }
        printf(" ");
    } else {
        for(int j = 0; j < nv; j++) {
            s[i] = v[j];
            mostraSequencia(v, s, i+1, nv, ns);
        }
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6};
    int ns = 3;
    int s[ns], nv = sizeof(v)/sizeof(v[0]);

    mostraSequencia(v, s, 0, nv, ns);
    return 0;
}