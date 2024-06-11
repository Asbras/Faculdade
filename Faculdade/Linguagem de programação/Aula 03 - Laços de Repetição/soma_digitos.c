/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 
  Nome do programa: Soma dos digitos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva um programa que pede ao usuário para inserir um número inteiro positivo e calcula a soma dos dígitos desse número
  usando um laço de repetição. O programa deve então exibir o resultado.
 *****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void pause() {
    while (getchar() != '\n');
    printf("Aperte Enter para continuar...");
    getchar();
    system("clear || cls");
}

int main() {
    int numero, digito, soma_digitos=0;

    // Limpar a tela
    system("clear || cls");

    // Receber o numero que o usuario deseja somar os digitos
    printf("Digite um numero inteiro e positivo: ");

    // validar a entrada do valor do usuário para que o número nao seja menor que zero nem um character
    while (scanf("%d", &numero) != 1 || numero < 0) {
        while (getchar() != '\n');
        printf("Valor inválido.\nDigite um número inteiro e positivo: ");
    }

    // Limpar a tela
    system("clear || cls");
    while (numero != 0) {
        digito = numero % 10;
        soma_digitos += digito;
        numero /= 10;
    }
    // Imprimir a soma dos digitos na tela 
    printf("A soma dos digitos é %d\n", soma_digitos);
    // pausar a execução do programa até que o usuário pressione a tecla Enter para visualizar o resultado
    pause();

    return 0;
}
