#include <stdio.h>
#include <stdlib.h>

#define MAXN 4

void printSudoku(int sudoku[][MAXN]) {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValid(int sudoku[][MAXN], int i, int j, int n) {
    for(int k = 0; k < MAXN; k++) {
        if(sudoku[i][k] == n || sudoku[k][j] == n) {
            return false;
        }
    }

    return true;
}

void solveSudoku(int sudoku[][MAXN], int i, int j) {
    if(j == MAXN) {
        i++;
        j = 0;
    }
    if(i == MAXN) {
        printSudoku(sudoku);
    } else if(sudoku[i][j] > 0) {
        solveSudoku(sudoku, i, ++j);
    } else {
        for(int k = 1; k <= MAXN; k++) {
            if(sudoku[i][j] == 0) {
                if(isValid(sudoku, i, j, k)) {
                    sudoku[i][j] = k;
                    solveSudoku(sudoku, i, ++j);
                    sudoku[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int sudoku[][MAXN] = {{0, 2, 0, 0}, 
                          {1, 0, 0, 3},
                          {0, 0, 0, 0}, 
                          {0, 1, 0, 0}};

    solveSudoku(sudoku, 0, 0);

    return 0;
}