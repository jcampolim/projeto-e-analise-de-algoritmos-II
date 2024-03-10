#include <stdio.h>

#define MAXN 50

void readFile(char maze[][MAXN], int *n, int *m) {
    FILE* file = fopen("entrada.txt", "r");

    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }

    int a, b;
    fscanf(file, "%d %d", &a, &b);

    *n = a;
    *m = b;
    
    for(int i = 0; i <= *n; i++) {
        for(int j = 0; j <= *m; j++) {
            maze[i][j] = fgetc(file);
        }
    }

    fclose(file);
}

int main() {
    int n, m;    
    char maze[MAXN][MAXN];

    readFile(maze, &n, &m);
    printf("%d %d\n", n, m);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            printf("%c", maze[i][j]);
        }
    }


    return 0;
}