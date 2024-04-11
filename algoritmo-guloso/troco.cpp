#include <stdio.h>
#include <stdlib.h>

bool trocoGuloso(int moedas[], int qtdeMoedas, int troco, int moedasTroco[], int *qtdeTroco) {
    int i = qtdeMoedas - 1;
    while(troco > 0 && i >= 0) {
        if(troco >= moedas[i]) {
            moedasTroco[*qtdeTroco] = moedas[i];
            *qtdeTroco += 1;
            troco = troco - moedas[i];
        } else {
            i--;
        }
    }

    if(troco == 0)  {
        return true;
    } 
    return false;
}

int main() {
    int moedas[] = {2, 4, 6}, troco = 9;
    int qtdeMoedas = sizeof(moedas)/sizeof(moedas[0]);

    int moedasTroco[troco], qtdeTroco = 0;

    if(trocoGuloso(moedas, qtdeMoedas, troco, moedasTroco, &qtdeTroco)) {
        printf("Solucao gulosa: ");
        for(int i = 0; i < qtdeTroco; i++) {
            printf("%d ", moedasTroco[i]);
        }
        printf("\n");
    } else {
        printf("Nao foi possivel encontrar uma solucao gulosa :(\n");
    }
}