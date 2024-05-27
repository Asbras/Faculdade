/**************************************************************
 * Nome do programa: Programa de Cópia de vetor invertido      *
 * Data: 07 de janeiro de 2024                                 *
 * Autor: Leonardo Carnio Della Torre                          *                 
 * Disciplina: Linguagem de Programação                        *  
 * Professor: Fernando Marco Perez Campos                      *
 * Descrição: Esse programa recebe um vetor de tamanho MAX, e  *
 *            copia para outro vetor e inverte os valores do   *
 *            do primeiro vetor.                               *
 ***************************************************************/

#include <stdio.h>
#define MAX 3

int main() {
    int vetor1[MAX], vetor2[MAX];  // Declaração de dois vetores de tamanho MAX

    // Receber valores do usuário
    for (int i = 0; i < MAX; i++) {
        printf("Digite um valor: \n");
        scanf("%d", &vetor1[i]);
    }
    
    // Copiar e inverter os valores do vetor1 para vetor2
    for (int i = 0; i < MAX; i++) {
        vetor2[i] = vetor1[MAX - 1 - i]; 
    }

    // Imprimir vetor2 para o usuário
    printf("* * * IMPRIMINDO VETOR COM VALORES INVERTIDOS * * *\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]\t", vetor2[i]);
    }

    printf("\n");

    return 0;
}

