/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 28/05/2024
  Nome do programa: SomaDosDigitos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva um programa em C que pede ao usuário para inserir um número inteiro positivo e, em seguida, imprime todos os números
  primos menores ou iguais a esse número. Um número primo é um número maior que 1 que só é divisível por 1 e por ele mesmo.
 *****************************************************************************************************************************************/
/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 28/05/2024
  Nome do programa: SomaDosDigitos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva um programa em C que pede ao usuário para inserir um número inteiro positivo e, em seguida, imprime todos os números
  primos menores ou iguais a esse número. Um número primo é um número maior que 1 que só é divisível por 1 e por ele mesmo.
 *****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void pause() {
    while (getchar() != '\n');
    printf("\nAperte Enter para continuar...");
    getchar();
    system("clear || cls");
}

// Função para testar se o número é primo
void eh_primo(int n) {
    int divisores = 0;

    // Testar se o número é divisivel só por 1 e por ele mesmo
    for (int i = 1;i <= n;i++) {
        if (n % i == 0) {
            divisores++;
        }
    }

    // Se o número só tiver 2 divisores, significa que ele é primo
    if (divisores == 2) {
        printf("%d\t", n);
    }
}

int main() {
    int numero;

    // Limpar tela
    system("clear || cls");

    // Solicitar o número que usuário deseja
    printf("Digite um numero inteiro e positivo: ");

    // Validar a entrada para que seja aceito somente numeros positivos
    while (scanf("%d", &numero) != 1 || numero < 0) {
        while (getchar() != '\n');
        printf("Entrada inválida. Digite um número inteiro positivo: ");
    }

    // Limpar tela
    system("clear || cls");

    // Descobrir todos os números primos menores ou igual ao numero digitado pelo usuário
    printf("Os números primos menores ou iguais a %d:\n", numero);
    for (int i = 1;i <= numero;i++) {
        eh_primo(i);
    }
    printf("\n");

    // Pausar o programa para que o usuário possa ver o resultado
    pause();

    return 0;
}
