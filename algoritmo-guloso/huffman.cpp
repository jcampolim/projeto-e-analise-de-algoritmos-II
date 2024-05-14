#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AsciiTable 256

// Nó para implementar a árvore de Huffman
typedef struct Node {
  int frequency;
  char c = '\0';
  Node *left = NULL;
  Node *right = NULL;
} Node;

// Implementação da estrutura de dados lista encadeada
// Classe nó da lista
typedef struct LinkedListNode {
  Node *node;
  LinkedListNode *next = NULL;
} LinkedListNode;

// Classe lista encadeada
typedef struct LinkedList {
  LinkedListNode *head;
  int size = 0;
} LinkedList;

// Insere um nó na lista
void push(LinkedList *q, Node *node) {
  LinkedListNode *newNode = new LinkedListNode;

  newNode->node = node;
  if (q->head != NULL) {
    newNode->next = q->head;
  }

  q->head = newNode;
  q->size = q->size + 1;
}

// Busca um nó da lista pela posição
Node *get(LinkedList *q, int i) {
  LinkedListNode *aux = q->head;

  for (int j = 0; j < i; j++) {
    aux = aux->next;
  }

  return aux->node;
}

// Remove um nó da lista pela posição
void remove(LinkedList *q, int i) {
  LinkedListNode *aux = q->head;

  if (i == 0) {
    q->head = aux->next;
    aux = NULL;
  } else {
    LinkedListNode *prev = NULL;
    for (int j = 0; j < i; j++) {
      prev = aux;
      aux = aux->next;
    }

    prev->next = aux->next;
    aux = NULL;
  }

  q->size = q->size - 1;
}

// Retorna o tamanho da lista
int size(LinkedList *q) { return q->size; }
// Fim da implementação da lista encadeada

// Exibe os nós da árvore de Huffman em ordem (apagar depois)
void printInOrder(Node *root) {
  if (root == NULL)
    return;

  printInOrder(root->left);
  printf("%d ", root->frequency);
  printInOrder(root->right);
}

// Pega o menor nó da lista encadeada
Node *getMin(LinkedList *q) {
  Node *min = get(q, 0);
  int pos = 0;
  for (int i = 1; i < size(q); i++) {
    if (get(q, i)->frequency < min->frequency) {
      min = get(q, i);
      pos = i;
    }
  }

  remove(q, pos);
  return min;
}

// Algoritmo da árvore de Huffman
Node *huffman(LinkedList *q) {
  while (size(q) > 1) {
    Node *x = getMin(q);
    Node *y = getMin(q);

    Node *z = new Node;
    z->left = x;
    z->right = y;
    z->frequency = (x->frequency + y->frequency);

    push(q, z);
  }
  return getMin(q);
}

// Função para escrever no arquivo (char)
void writeFile(char c) {
  FILE *file = fopen("arquivo.txt", "a");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  fputc(c, file);
  fclose(file);
}

// Função para escrever no arquivo ("bin")
void writeBin(char code[]) {
  FILE *file = fopen("binario.txt", "a");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  int i = 0;
  while (code[i] == '0' || code[i] == '1') {
    char c = code[i];
    fputc(c, file);
    i++;
  }

  fclose(file);
}

// Função para ler o arquivo ("bin")
void readBin(Node *root) {
  FILE *file = fopen("binario.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  char c;
  Node *aux = root;

  while ((c = fgetc(file)) != EOF) {

    if (c == '0') {
      aux = aux->left;

      if (aux->c != '\0') {
        writeFile(aux->c);
        aux = root;
      }
    } else {
      aux = aux->right;

      if (aux->c != '\0') {
        writeFile(aux->c);
        aux = root;
      }
    }
  }

  fclose(file);
}

// Percorre a árvore com um algoritmo backtracking para encontrar o código de
// cada char
bool findCode(Node *root, char c, char code[], int i) {
  if (root->c == c) {
    return true;
  }

  if (root->left != NULL) {
    code[i] = '0';
    if (findCode(root->left, c, code, i + 1)) {
      return true;
    }
  }

  if (root->right != NULL) {
    code[i] = '1';
    if (findCode(root->right, c, code, i + 1)) {
      return true;
    }
  }

  code[i] = '\0';
  return false;
}

void readFile(Node *root) {
  FILE *file = fopen("arquivo.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  char c;
  while ((c = fgetc(file)) != EOF) {
    char code[AsciiTable];
    findCode(root, c, code, 0);

    writeBin(code);
  }

  fclose(file);
}

// Função para ler o arquivo (char)
void getFrequency(LinkedList *q) {
  FILE *file = fopen("arquivo.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  int frequency[AsciiTable] = {0};
  char c;
  while ((c = fgetc(file)) != EOF) {
    int i = (int)c;
    frequency[i]++;
  }

  fclose(file);

  for (int i = 0; i < AsciiTable; i++) {
    if (frequency[i] > 0) {
      Node *aux = new Node;

      aux->frequency = frequency[i];
      aux->c = (char)i;
      aux->left = NULL;
      aux->right = NULL;

      push(q, aux);
    }
  }
}

int main() {
  LinkedList *q = new LinkedList();
  Node *root = NULL;

  int opcao = 0;
  bool hasHuffman = false;

  while (opcao != 4) {
    printf("#######################################################\n");
    printf(" 1 - Ler arquivo de texto\n");
    printf(" 2 - Transformar arquivo de texto em binário\n");
    printf(" 3 - Transformar binário em arquivo de texto\n");
    printf(" 4 - Sair\n");
    printf("######################################################\n");

    printf("\nDigite a opção desejada: ");
    std::cin >> opcao;

    if (opcao == 1) {
      getFrequency(q);
      root = huffman(q);

      hasHuffman = true;

      printf("\nArquivo lido com sucesso!\n\n");
    } else if (opcao == 2) {
      if (hasHuffman) {
        readFile(root);
        printf("\nArquivo binário gerado com sucesso!\n\n");
      } else {
       printf("\nÉ necessário ler o arquivo antes.\n\n"); 
      }
    } else if (opcao == 3) {
      if(hasHuffman) {
        readBin(root);
        printf("\nArquivo de texto gerado com sucesso!\n\n");
      } else {
        printf("\nÉ necessário ler o arquivo antes.\n\n"); 
      }
    }
  }

  printf("\nEncerrando o programa...\n");

  return 0;
}