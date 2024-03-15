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

void printMaze(char maze[][MAXN], int n, int m) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            printf("%c", maze[i][j]);
        }
    }
}

void solveMaze(char maze[][MAXN], char solution[], int n, int m, int steps) {
    maze[1][1] = 'E';
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(maze[i][j] == 'x') {
                maze[i][j] = '.';
            }
        }
    }

    int i = 1, j = 2;
    for(int k = 0; k < steps; k++) {
        if(solution[k] == 'R') j++;
        else if(solution[k] == 'L') j--;
        else if(solution[k] == 'D') i++;
        else if(solution[k] == 'U') i--;
        else printf("a");
        
        maze[i][j] = 'o';
    }
}

void findPath(char maze[][MAXN], char testingPath[], char solution[], int n, int m, int i, int j, int steps) {
    if(maze[i][j] == 'S') {
        printf("%d\n", steps);
        for(int k = 0; k <= steps; k++) {
            solution[k] = testingPath[k];
        }

        return;
    } else {
        if((i > 0 && j > 0) && (i < n && j < m)) {
            maze[i][j] = 'x';
            if(maze[i][j+1] != '#' && maze[i][j+1] != 'x') {
                steps++;
                testingPath[steps] = 'R';
                findPath(maze, testingPath, solution, n, m, i, j+1, steps);
            }
            if(maze[i][j-1] != '#' && maze[i][j-1] != 'x') {
                steps++;
                testingPath[steps] = 'L';
                findPath(maze, testingPath, solution, n, m, i, j-1, steps);
            }
            if(maze[i+1][j] != '#' && maze[i+1][j] != 'x') {
                steps++;
                testingPath[steps] = 'D';
                findPath(maze, testingPath, solution, n, m, i+1, j, steps);
            }
            if(maze[i-1][j] != '#' && maze[i-1][j] != 'x') {
                steps++;
                testingPath[steps] = 'U';
                findPath(maze, testingPath, solution, n, m, i-1, j, steps);
            }

            return;
        }
    }
}

int main() {
    int n, m;    
    char maze[MAXN][MAXN];

    readFile(maze, &n, &m);
    char testingPaths[n*m], solution[n*m];

    findPath(maze, testingPaths, solution, n, m, 1, 1, 0);

    solveMaze(maze, solution, n, m, 50);

    printMaze(maze, n, m);

    return 0;
}