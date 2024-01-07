/***************************************************************
 * Nome do programa: Programa de Análise de Temperaturas       *
 * Data: 07 de janeiro de 2024                                 *
 * Autor: Leonardo Carnio Della Torre                          *                 
 * Disciplina: Linguagem de Programação                        *  
 * Professor: Fernando Marco Perez Campos                      *
 * Descrição: Este programa solicita ao usuário que insira     *
 *            10 valores de temperatura, verifica se cada      *
 *            temperatura é quente ou fria e exibe os          *
 *            resultados na tela.                              * 
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

// Função para checar se a temperatura é quente ou fria
void quente_ou_frio(float T){
    T >= 20 ? printf("QUENTE\n") : printf("FRIO\n");
}


// Função para limpar a tela
void limpar_tela() {
#ifdef _WIN32
    system("cls"); // Limpar a tela no windows
#else
    system("clear"); // Limpar tela no Linux
#endif
}

int main(int argc, char *argv[])
{
    float temperaturas[TAMANHO]; // Declarar vetor de temperaturas

    limpar_tela(); // Limpar tella

    // Receber 10 temperaturas
    for (int i = 0; i < TAMANHO; i++) { 
        printf("Digite o valor da temperatura %d:\n", i+1);
        scanf("%f", &temperaturas[i]);
    }
    limpar_tela(); // Limpar tela

    // Imprimir na tela as 10 temperaturas
    for (int i = 0; i < TAMANHO; i++) {
        printf("Temperatura %d: %.2f °C\t", i+1, temperaturas[i]);
        quente_ou_frio(temperaturas[i]); // Checar se temperatura é maior ou menor que 20
    }
    return 0;
}
