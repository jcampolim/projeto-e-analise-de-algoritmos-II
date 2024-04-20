#include <stdio.h>

typedef struct {
    int ativ;
    int inicio;
    int final;
} Atividade;

void bubble_sort(Atividade s[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(s[j].final > s[j + 1].final) {
                Atividade aux = s[j];
                s[j] = s[j + 1];
                s[j + 1] = aux;
            }
        }
    }
}

int seleciona_atividades_guloso(Atividade s[], int n, int a[]) {
    bubble_sort(s, n);
    a[0] = s[0].ativ;
    int j = 1, atividades = 1;

    for(int i = 1; i < n; i++) {
        if(s[i].inicio >= s[j].final) {
            a[atividades] = s[i].ativ;
            j = i;
            atividades++;
        }
    }

    return atividades;
}

int main() {
    Atividade s[11];

    int n = 11, a[n];
    for(int i = 0; i < n; i++) {
        s[i].ativ = i + 1;
    }

    s[0].inicio = 1;
    s[0].final = 4;

    s[1].inicio = 3;
    s[1].final = 5;

    s[2].inicio = 0;
    s[2].final = 6;

    s[3].inicio = 5;
    s[3].final = 7;

    s[4].inicio = 3;
    s[4].final = 8;

    s[5].inicio = 5;
    s[5].final = 9;

    s[6].inicio = 6;
    s[6].final = 10;

    s[7].inicio = 8;
    s[7].final = 11;

    s[8].inicio = 8;
    s[8].final = 12;

    s[9].inicio = 2;
    s[9].final = 13;

    s[10].inicio = 12;
    s[10].final = 14;

    int atividades = seleciona_atividades_guloso(s, n, a);
    for(int i = 0; i < atividades; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}