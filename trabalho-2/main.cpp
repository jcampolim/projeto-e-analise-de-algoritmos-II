#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 70

void getFirstLine(int *n, int *k) {
  FILE* file = fopen("entrada.txt", "r");

  if(file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  
  int a, b;
  fscanf(file, "%d %d", &a, &b);

  *n = a;
  *k = b;

  fclose(file);
}

void readFile(int n, int k, char buildings[][MAX], int* distance[]) {
  FILE* file = fopen("entrada.txt", "r");

  if(file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  char s[MAX];
  fgets(s, MAX, file);

  for(int i = 0; i < n; i++) {
    fgets(s, MAX, file);
    strcpy(buildings[i], s);
  }

  int m, u, v, d;
  
  fscanf(file, "%d", &m);

  for(int i = 0; i < m; i++) {
    fscanf(file, "%d %d %d", &u, &v, &d);
    distance[u-1][v-1] = d;
    distance[v-1][u-1] = d;
  }

  fclose(file);
}

void writeOutput(int k, char buildings[][MAX], int centers[]) {
  FILE* file = fopen("saida.txt", "w");

  if(file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  for(int i = 0; i < k; i++) {
    fprintf(file, "%s", buildings[centers[i] - 1]);
  }

  fclose(file);
}

bool isCenter(int k, int b, int centers[]) {
  for(int i = 0; i < k; i++) {
    if(centers[i] == b) {
      return true;
    }
  }

  return false;
}

void selectCenters(int n, int k, int* distance[], int centers[]) {
  centers[0] = 1;
  int newCenter = 0;
  
  for(int i = 1; i < k; i++) {
    int maxDistance = 0;
    
    for(int j = 1; j <= n; j++) {
      
      if(!isCenter(k, j, centers)) {
        int minDistance = 100000;
        
        for(int k = 0; k < i; k++) {
          if(minDistance > distance[j - 1][centers[k] - 1]) {
            minDistance = distance[j - 1][centers[k] - 1];
          }
        }

        if(maxDistance < minDistance) {
          maxDistance = minDistance;
          newCenter = j;
        }
      }
    }
    centers[i] = newCenter;
    newCenter = 0;
  }
}

int main() {
  int n, k;

  getFirstLine(&n, &k);
  
  char buildings[n][MAX];
  int* distance[n], centers[k];

  for(int i = 0; i < n; i++) {
    distance[i] = (int*)malloc(n * sizeof(int));
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      distance[i][j] = 0;
    }
  }

  readFile(n, k, buildings, distance);
  selectCenters(n, k, distance, centers);

  writeOutput(k, buildings, centers);

  for(int i = 0; i < k; i++) {
    printf("%s", buildings[centers[i] - 1]);
  }
  
  return 0;
}