/***************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 27/05/2024
  Nome do programa: Calculadora de Descontos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa em C que leia o valor de uma
  compra e a forma de pagamento escolhida pelo usuário.
  O programa deve calcular e mostrar o valor final a ser pago
  de acordo com a forma de pagamento escolhida, aplicando os
  seguintes descontos:
        À vista (dinheiro ou cheque): 10% de desconto
        Cartão de débito: 5% de desconto
        Cartão de crédito: sem desconto
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Função para limpar a tela
void limpar_tela() {
    while (getchar()!='\n');
    printf("\nPressione Enter para continuar...");
    getchar();
    system("clear || cls");
}

// Função para mostrar as opções de pagamento e receber do usuário a opção escolhida
void forma_pagamento(int *opt) {
    printf("Escolha a forma de pagamento:\n1 - À vista (dinheiro ou cheque)\n2 - Cartão de débito\n3 - Cartão de crédito\nOpção: ");
    scanf("%d", opt);
}

int main() {
    float valor_compra, valor_final;
    int opcao;

    // Limpar tela
    system("clear || cls");

    // Receber do usuário o valor da compra
    printf("Digite o valor da sua compra: ");
    scanf("%f", &valor_compra);

    // Validar a entrada do valor da compra
    while (valor_compra <= 0) {
        printf("Valor inválido, por favor, digite um valor positivo para o valor da compra: ");
        scanf("%f", &valor_compra);
    }
    system("clear || cls");
    // Chamada da função para saber qual o método de pagamento
    forma_pagamento(&opcao);

    // Validar a estrada da opção digitada pelo usuário
    while (opcao < 1 || opcao > 3) {
        printf("Opção inválida, por favor, escolha uma opção válida (1 a 3): ");
        scanf("%d", &opcao);
    }

    switch (opcao) {
        case 1: // À vista
            valor_final = valor_compra * 0.9;
            break;
        case 2: // Cartão de débito
            valor_final = valor_compra * 0.95;
            break;
        case 3: // Cartão de crédito
            valor_final = valor_compra;
            break;
    }
    system("clear || cls");
    // Informar o valor total dependendo do método de pagamento
    printf("Valor final a ser pago: %.2f\n", valor_final);
    limpar_tela();
    return 0;
}
