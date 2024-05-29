/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 29/05/2024
  Nome do programa: operações matrizes
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa em C que leia uma matriz de inteiros 3x3 e, em seguida, realize as seguintes operações:
        1.Soma dos Elementos:
            Calcule a soma de todos os elementos da matriz.
        2.Transposta da Matriz:
            Crie a matriz transposta (troque as linhas pelas colunas).
        3.Soma das Linhas e Colunas:
            Calcule a soma dos elementos de cada linha e de cada coluna da matriz original.
        4.Diagonal Principal e Secundária:
            Calcule a soma dos elementos da diagonal principal (de cima à esquerda até baixo à direita) e da diagonal secundária.
 *****************************************************************************************************************************************/

#include <stdio.h>
#define MAX 3

int carregar(int matriz[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("\nDigite um valor posição [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    return 0;
}

void soma_elementos(int matriz[][MAX], int *soma_elementos) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            *soma_elementos += matriz[i][j];
        }
    }
}

void soma_linhas(int matriz[][MAX], int *soma_linha_1, int *soma_linha_2, int *soma_linha_3) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (j == 0) {
                *soma_linha_1 += matriz[i][j];
            }
            if (j == 1) {
                *soma_linha_2 += matriz[i][j];
            }
            if (j == 2) {
                *soma_linha_3 += matriz[i][j];
            }
        }
    }
}

void soma_colunas(int matriz[][MAX], int *soma_coluna_1, int *soma_coluna_2, int *soma_coluna_3) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == 0) {
                *soma_coluna_1 += matriz[j][i];
            }
            if (i == 1) {
                *soma_coluna_2 += matriz[j][i];
            }
            if (i == 2) {
                *soma_coluna_3 += matriz[j][i];
            }
        }
    }
}

void soma_diagona_principal(int matriz[][MAX], int *soma_diagonal_principal) {
    for (int i = 0; i < MAX; i++) {
        *soma_diagonal_principal += matriz[i][i];
    }
}

void soma_diagonal_secundaria(int matriz[][MAX], int *soma_diagonal_secundaria) {
    for (int i = 0; i < MAX; i++) {
        *soma_diagonal_secundaria += matriz[i][MAX - 1 - i];
    }
}

void matriz_transposta(int matriz[][MAX], int matriz_transposta[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matriz_transposta[j][i] = matriz[i][j];
        }
    }
}

void imprimir(int matriz[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
    int diagonal_principal = 0, diagonal_secundaria = 0, soma_linha_1 = 0, soma_linha_2 = 0, soma_linha_3 = 0, soma_dos_elemento = 0;
    int soma_coluna_1 = 0, soma_coluna_2 = 0, soma_coluna_3 = 0;
    int transposta[MAX][MAX];
    int matriz[MAX][MAX] = {1,2,3,4,5,6,7,8,9};

    soma_elementos(matriz, &soma_dos_elemento);
    soma_linhas(matriz, &soma_linha_1, &soma_linha_2, &soma_linha_3);
    soma_colunas(matriz, &soma_coluna_1, &soma_coluna_2, &soma_coluna_3);
    soma_diagona_principal(matriz, &diagonal_principal);
    soma_diagonal_secundaria(matriz, &diagonal_secundaria);
    matriz_transposta(matriz, transposta);

    printf("Soma de todos os elementos: %d\n\n", soma_dos_elemento);
    printf("Matriz Transposta:\n");
    imprimir(transposta);
    printf("Soma das linhas\nLinha 1: %d\nLinha 2: %d\nLinha 3: %d\n\n", soma_linha_1, soma_linha_2, soma_linha_3);
    printf("Soma das colunas\nColuna 1: %d\nColuna 2: %d\nColuna 3: %d\n\n", soma_coluna_1, soma_coluna_2, soma_coluna_3);
    printf("Soma da diagonal principal: %d\n", diagonal_principal);
    printf("Soma da diagonal secundária: %d\n", diagonal_secundaria);

    return 0;
}

