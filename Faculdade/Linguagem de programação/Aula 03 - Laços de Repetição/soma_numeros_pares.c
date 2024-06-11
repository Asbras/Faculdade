/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data:
  Nome do programa: Soma de numeros pares
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva um programa em C que solicita ao usuário que insira um número inteiro positivo e, em seguida, imprime a soma de todos
  os números pares de 1 até o número inserido pelo usuário.

 *****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void pause() {
    while (getchar() !='\n');
    printf("Aperte Enter para continuar...");
    getchar();
    system("clear || cls");
}

int main() {
    int numero, soma_dos_pares=0;

    // Limpar a tela
    system("clear || cls");

    // Receber o numero do usuário
    printf("Digite um número inteiro e positivo: ");
    // Validar a entrada
    while (scanf("%d", &numero) != 1 && numero < 0) {
        printf("Entrada invalida. Digite um número inteiro e positivo: ");
    }

    // Limpar a tela
    system("clear || cls");

    // Calcular a soma dos numeros pares até o número digitado pelo usuário
    for (int i=2; i<= numero;i+=2) {
        soma_dos_pares += i;
    }

    // Imprimir a soma dos numeros pares
    printf("Soma dos números pares: %d\n", soma_dos_pares);

    // Pausar o programa para o usuário ver a resposta e esperar o usuário apertar Enter
    pause();

    return 0;
}
