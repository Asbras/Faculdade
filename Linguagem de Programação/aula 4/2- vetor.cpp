/***************************************************************
 * Nome do programa: Programa de Cópia de vetor invertido      *
 * Data: 07 de janeiro de 2024                                 *
 * Autor: Leonardo Carnio Della Torre                          *                 
 * Disciplina: Linguagem de Programação                        *  
 * Professor: Fernando Marco Perez Campos                      *
 * Descrição: Esse programa recebe um vetor de tamano MAX, e   *
 *            copia para outro vetor e inverte os valores do   *
 *            do primeiro vetor.                               *
 ***************************************************************/


#include <iostream>
#define MAX 3

int main () {
    int vetor1[MAX], vetor2[MAX];

    // Ler um vetor de MAX posições
    for (int i = 0; i < MAX; i++) {
        printf("Digite o valor %d:\n", i+1);
        scanf("%d", &vetor1[i]);
    }

    // Fazer uma cópia dos valores do vetor1 para o vetor2
    for (int i = 0; i < MAX; i++) {
        vetor2[i] = -vetor1[i]; 
    }
    printf("Vetor 1:\n");
    // Imprimir vetor1
    for (int i = 0; i < MAX; i++) {
        printf("%d\t", vetor1[i]);
    }
    
    printf("\nVetor 2:\n");
    // Imprimir vetor2
    for (int i = 0; i < MAX; i++) {
        printf("%d\t", vetor2[i]);
    }
    printf("\n");

    return 0;
}
