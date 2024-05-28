
/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data:
  Nome do programa: Calculadora de IMC
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva um programa que pede ao usuário para inserir um número inteiro positivo e calcula o fatorial desse número
  usando um laço de repetição. O programa deve então exibir o resultado.

 *****************************************************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void calcular_fatorial(int numero, long unsigned int *fatorial) {
    // Laço de repetição para calcular o fatorial do número digitado
    for (int i=1; i<=numero;i++) {
        *fatorial *= i;
    }
}

void pause() {
    while (getchar() != '\n');
    printf("Aperte Enter para continuar...");
    getchar();
    system("clear || cls");
}

int main() {
    long unsigned int fatorial=1;
    int numero;

    system("clear || cls");
    // Receber número do usuário para calcular o fatorial
    printf("Digite um número inteiro para calcular o fatorial: ");


    // Validar a entrada para que seja digitado um número inteiro positivo
    while (scanf("%d", &numero) != 1 || numero < 0) {
        while (getchar() != '\n');
        printf("Entrada inválida. Digite um número inteiro positivo: ");
     }

    // Limpar tela
    system("clear || cls");

    // Caso o número digitado seja 0 o fatorial é 1
    if (numero == 0) {
        printf("Fatorial: 1\n");
    } else { // Caso seja maior que 1
        // Calcular o fatorial do número digitado
        calcular_fatorial(numero, &fatorial);
        // Imprimir o valor do fatorial
        printf("Fatorial: %ld\n", fatorial);
    }
    // Pausar o programa para o usuario ver o resultado antes de limpar a tela apos o usuario pressinar Enter
    pause();
    return 0;
}
