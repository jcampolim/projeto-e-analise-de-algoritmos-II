#include <stdio.h>

int algoritmo_do_caminhoneiro(int p[], int n, int c, int s[]) {
    int ultima_parada = 0, paradas = 0;
    for(int i = 1; i < n; i++) {
        if((p[i] - ultima_parada) > c) {
            ultima_parada = p[i - 1];
            s[paradas] = i;
            paradas++;
        }
    }

    return paradas;
}

int main() {
    int n = 8, c = 250;
    int p[] = {200, 300, 400, 500, 600, 700, 800, 900}, s[n];

    int paradas = algoritmo_do_caminhoneiro(p, n, c, s);
    for(int i = 0; i < paradas; i++) {
        printf("%d ", s[i]);
    }

    return 0;
}