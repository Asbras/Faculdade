/******************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: O valor está contido?                       |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Escreva um programa em C/c++ que receba um valor e | 
 | verifique se ele está ou nao contido em algum dos intervalos: |
 |                                                               |
 |      a. [7,10[                                                |
 |      b. [28,30]                                               |
 |      c. ]35,40[ ou [90,100]                                   |
 |      d. 100 ou [200,300] ou ]500,600]                         |
 ****************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int valor; // Variável para armazenar o valor digitado pelo usuário
    bool esta_contido = false; // Variável para rastrear se o valor está contido em algum intervalo

    // Loop principal para solicitar ao usuário que insira um valor válido
    while (true) {
        printf("Digite um valor:\n");
        if (scanf("%d", &valor) == 1) {
            break; // Sai do loop se a entrada for válida
        } else {
            printf("Entrada inválida. Por favor, digite um valor numérico.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
        }
    }

    // Verifica se o valor está contido em cada intervalo e imprime uma mensagem correspondente
    if (valor >= 7 && valor < 10) {
        printf("O valor digitado está entre [7,10[\n");
        esta_contido = true;
    }

    if (valor >= 28 && valor <= 30) {
        printf("O valor digitado está entre [28,30]\n");
        esta_contido = true;
    }

    if ((valor > 35 && valor <= 40) || (valor >= 90 && valor <= 100)) {
        printf("O valor digitado está entre ]35,40] ou entre [90,100]\n");
        esta_contido = true;
    }

    if ((valor == 100) || (valor >= 200 && valor <= 300) || (valor > 500 && valor <= 600)) {
        printf("O valor digitado é 100 ou está entre [200,300] ou entre ]500,600]\n");
        esta_contido = true;
    }

    // Se o valor não estiver contido em nenhum intervalo, imprime uma mensagem correspondente
    if (!esta_contido) {
        printf("O valor nao esta contido em nenhum intervalo\n");
    }

    return 0;
}
