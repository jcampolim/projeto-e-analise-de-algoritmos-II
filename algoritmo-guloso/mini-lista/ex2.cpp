#include <stdio.h>

typedef struct {
    int id;
    int chegada;
    int saida;
} Pedido;

void bubbleSort(Pedido pedidos[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(pedidos[j].chegada > pedidos[j + 1].chegada) {
                Pedido aux = pedidos[j];
                pedidos[j] = pedidos[j + 1];
                pedidos[j + 1] = aux;
            }
        }
    }
}

int calcPedidos(Pedido pedidos[], int n) {
    bubbleSort(pedidos, n);
    int a[n];
    a[0] = pedidos[0].id;
    int j = 0, qtde = 1;

    for(int i = 1; i < n; i++) {
        if(pedidos[i].chegada > pedidos[j].saida) {
            a[qtde] = pedidos[i].id;
            j = i;
            qtde++;
        }
    }

    return qtde;
}


int main() {
    int n;
    scanf("%d", &n);

    Pedido pedidos[n];
    for(int i = 0; i < n; i++) {
        int chegada, saida;
        scanf("%d %d", &chegada, &saida);

        pedidos[i].id = i + 1;
        pedidos[i].chegada = chegada;
        pedidos[i].saida = saida;
    }

    printf("%d\n", calcPedidos(pedidos, n));

    return 0;
}