#include <stdio.h>

int salto_sapo(int p[], int n, int delta, int u[]) {
    u[0] = p[0];

    int ultima_pos = p[0];
    int saltos = 1;

    for(int i = 1; i <= n; i++) {
        if((p[i] - ultima_pos) > delta) {
            ultima_pos = p[i - 1];
            u[saltos] = p[i - 1];
            saltos++;
        }
    }

    u[saltos] = p[n - 1];

    return saltos + 1;
}

int main() {
    int n = 4, delta = 1;
    int p[] = {1, 2, 3, 4}, u[n];

    int saltos = salto_sapo(p, n, delta, u);

    for(int i = 0; i < saltos; i++) {
        printf("%d ", u[i]);
    }

    return 0;
}