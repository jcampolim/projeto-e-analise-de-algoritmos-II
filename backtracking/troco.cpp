#include <stdio.h>

void trocoBacktracking(int moedas[], int qtdeMoedas, int moedasTroco[], int troco, int qtdeTroco, int melhor[], int *qtdeMelhor) {
    if(troco == 0 && qtdeTroco <= *qtdeMelhor) {
        *qtdeMelhor = qtdeTroco;
        for(int i = 0; i < *qtdeMelhor; i++) {
            melhor[i] = moedasTroco[i];
        }
    } else {
        for(int i = 0; i < qtdeMoedas; i++) {
            if(troco >= moedas[i]) {
                moedasTroco[qtdeTroco] = moedas[i];
                trocoBacktracking(moedas, qtdeMoedas, moedasTroco, (troco - moedas[i]), (qtdeTroco + 1), melhor, qtdeMelhor);
                moedasTroco[qtdeTroco] = 0;
            }
        }
    }
}

int main() {
    int moedas[] = {1, 4, 6}, troco = 8;
    int qtdeMoedas = sizeof(moedas)/sizeof(moedas[0]);

    int moedasTroco[troco], melhor[troco];
    int qtdeMelhor = troco + 1;

    trocoBacktracking(moedas, qtdeMoedas, moedasTroco, troco, 0, melhor, &qtdeMelhor);
    for(int i = 0; i < qtdeMelhor; i++) {
        printf("%d ", melhor[i]);
    }
    printf("\n");

    return 0;
}