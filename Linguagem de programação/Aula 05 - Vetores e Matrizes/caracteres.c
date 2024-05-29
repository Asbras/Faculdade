/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 29/05/1992
  Nome do programa: Comparar matriz de caracteres
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa em C/C++ que carregue duas  matrizes de caracteres de ordem 4X4 e depois retorne as posições de elementos
  repetidos nas duas matrizes que compartilham a mesma posição
 *****************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

// Função para ler uma matriz de caracteres do usuário
void ler_matriz(char matriz[][MAX], int num) {
    printf("Digite os elementos da matriz %d:\n", num);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("Digite o caractere na posição [%d][%d]: ", i, j);
            // Use " %c" para consumir caracteres em branco anteriores
            scanf(" %c", &matriz[i][j]);
        }
    }
}

// Função para comparar duas matrizes e imprimir as posições dos elementos repetidos
void comparar_matriz(char m1[][MAX], char m2[][MAX]) {
    printf("Elementos repetidos nas matrizes:\n\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (m1[i][j] == m2[i][j]) {
                printf("Elemento %c repetido na posição: [%d][%d]\n", m1[i][j], i, j);
            }
        }
    }
    printf("\n");
}

// Função para pausar o programa até o usuário pressionar Enter
void pause() {
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n'); // Aguarda até que Enter seja pressionado
    getchar();
}

int main() {
    char matriz1[MAX][MAX];
    char matriz2[MAX][MAX];

    system("clear || cls"); // Limpa a tela no início do programa
    ler_matriz(matriz1, 1); // Lê a primeira matriz
    system("clear || cls");
    ler_matriz(matriz2, 2); // Lê a segunda matriz
    system("clear || cls");
    comparar_matriz(matriz1, matriz2); // Compara as matrizes e imprime os elementos repetidos
    pause(); // Pausa o programa até o usuário pressionar Enter
    system("clear || cls"); // Limpa a tela no final do programa

    return 0;
}

