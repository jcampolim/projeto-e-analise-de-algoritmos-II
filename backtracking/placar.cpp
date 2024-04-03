#include <stdio.h>

 

void placar(int m, int n, char p[], int i) {

    if(m == 0 && n == 0) {

        for(int j = 0; j < i; j++) {

            printf("%c", p[j]);

        }

        printf(" ");

    } else {

        if(m > 0) {

            p[i] = 'A';

            placar(m-1, n, p, i+1);

        }

        if(n > 0) {

            p[i] = 'B';

            placar(m, n-1, p, i+1);

        }

    }

}

 

int main() {

    int m = 3, n = 2;

    char p[m+n];

   

    placar(m, n, p, 0);

 

    return 0;

}