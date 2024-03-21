// Erika Borges Piaui - 10403716
// Júlia Campolim de Oste - 10408802

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Lê as dimensões da matriz no arquivo e salva nas variáveis n e m
void getFileSize(int *n, int *m) {
    FILE* file = fopen("entrada.txt", "r");

    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }

    int a, b;
    fscanf(file, "%d %d", &a, &b);

    *n = a;
    *m = b;

    fclose(file);
}

// Lê o conteúdo do arquivo e coloca cada char do labirinto em uma matriz
void getFileContent(char** maze, int n, int m) {
    FILE* file = fopen("entrada.txt", "r");

    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }

    char linha[m];

    fscanf(file, "%s", linha);
    fscanf(file, "%s", linha);

    for(int i = 0; i < n; i++) {
        fscanf(file, "%s", linha);
        for (int j = 0; j < m; ++j) {
            maze[i][j] = linha[j];
        }
    }

    fclose(file);
}

// Exibe na tela a matriz que contém o labirinto
void printMaze(char** maze, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Algoritmo backtracking que encontra o caminho para solucionar o labirinto
bool findPath(char** maze, int n, int m, int i, int j) {
    if(maze[i][j] == 'S') {
        return true;
    } else {
        if((i >= 0 && j >= 0) && (i < n && j < m)) {
            if (maze[i][j] == '.'){
               maze[i][j] = 'o';

               if(maze[i][j+1] == '.' || maze[i][j+1] == 'S') {
                   if (findPath(maze, n, m, i, j+1)) 
                       return true;
               }          

               if(maze[i][j-1] == '.' || maze[i][j-1] == 'S') {
                   if(findPath(maze, n, m, i, j-1))
                       return true;
               }

               if(maze[i+1][j] == '.' || maze[i+1][j] == 'S') {
                  if(findPath(maze, n, m, i+1, j))
                     return true;
               }

               if(maze[i-1][j] == '.' || maze[i-1][j] == 'S') {
                 if (findPath(maze, n, m, i-1, j))
                    return true;
               }

               maze[i][j] = '.';
           }
        }
    }
    return false;
}

int main() {
    int n, m;
    getFileSize(&n, &m);

    char** maze = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i< n; i++) {
        maze[i] = (char *)malloc(m * sizeof(char));
    }

    getFileContent(maze, n, m);

    printMaze(maze, n, m);

    bool isPossible = findPath(maze, n, m, 1, 1);
    if(isPossible) {
        printMaze(maze, n, m);  
    } else {
        printf("Não foi possível encontrar a saida do labirinto :(\n");
    }

    free(maze);
    return 0;
}