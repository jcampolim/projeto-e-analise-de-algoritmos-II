#include <stdio.h>

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int recursiva(int i, int s[]) {
    if(i == 0) {
        return 1;
    } else {
        int maior = 1;
        for(int j = 0; j < i; j++) {
            if(s[j] < s[i]) {
                maior = max(maior, recursiva(j, s) + 1);
            }
        }
        return maior;
    }
}

int recursivaLIS(int n, int s[]) {
    int maior = 1;
    for(int i = 0; i < n; i++) {
        maior = max(maior, recursiva(i, s));
    }
    return maior;
}

int topDown(int i, int s[], int l[]) {
    if(l[i] != -1) {
        return l[i];
    } else if(l[i] == 0) {
        return l[i] = 1;
    } else {
        int maior = 1;
        for(int j = 0; j < i; j++) {
            if(s[j] < s[i]) {
                maior = max(maior, topDown(j, s, l) + 1);
            }
        }
        return l[i] = maior;
    }
}

int topDownLIS(int n, int s[]) {
    int l[n], maior = 1;

    for(int i = 0; i < n; i++) {
        l[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        maior = max(maior, topDown(i, s, l));
    }
    return maior;
}

int bottomUpLIS(int n, int s[]) {
    int l[n], maior = 0;

    for(int i = 0; i < n; i++) {
        l[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(s[j] < s[i]) {
                l[i] = max(l[i], l[j] + 1);
            }
        }
        maior = max(maior, l[i]);
    }
    return maior;
}

int main() {
    int s[] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = sizeof(s)/sizeof(s[0]);

    printf("Subsequencia crescente mais longa\n\n");

    printf("Solucao recursiva: %d\n", recursivaLIS(n, s));
    printf("Solucao top-down: %d\n", topDownLIS(n, s));
    printf("Solucao bottom-up: %d\n", bottomUpLIS(n, s));

    return 0;
}