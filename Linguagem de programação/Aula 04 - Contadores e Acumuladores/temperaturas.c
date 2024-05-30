/***************************************************************
 * Nome do programa: Programa de Análise de Temperaturas
 * Data: 07 de janeiro de 2024
 * Autor: Leonardo Carnio Della Torre
 * Disciplina: Linguagem de Programação
 * Professor: Fernando Marco Perez Campos
 * Descrição: Este programa solicita ao usuário que insira
 *            10 valores de temperatura, verifica se cada
 *            temperatura é quente ou fria e exibe os
 *            resultados na tela. Ele também calcula a média,
 *            a maior e a menor temperatura digitada.
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE 10

// Função para checar se a temperatura é quente ou fria
void quente_ou_frio(float T){
    T >= 20 ? printf("QUENTE\n") : printf("FRIO\n");
}

// Função para calcular menor temperatura
float menor_temperatura(float* t){
    float temperatura_min = 999999999.9;

    for (int i = 0; i < QUANTIDADE; i++) {
        if (t[i] < temperatura_min) {
            temperatura_min = t[i];
        }
    }
    return temperatura_min;
}

// Função para calcular maior temperatura
float maior_tempertura(float* t){
    float temperatura_max = -9999999;

    for (int i = 0; i < QUANTIDADE; i++) {
        if (t[i] > temperatura_max) {
            temperatura_max = t[i];
        }
    }
    return temperatura_max;
}

// Função para limpar a tela
void limpar_tela() {
#ifdef _WIN32
    system("cls"); // Limpar a tela no windows
#else
    system("clear"); // Limpar tela no Linux
#endif
}

int main()
{
    float temperaturas[QUANTIDADE]; // Declarar vetor de temperaturas
    float temperatura_min,temperatura_max, media_temperatura = 0, total_temperatura = 0;

    limpar_tela(); // Limpar tella

    // Receber 10 temperaturas
    for (int i = 0; i < QUANTIDADE; i++) { 
        printf("Digite o valor da temperatura %d:\n", i+1);
        scanf("%f", &temperaturas[i]);
        total_temperatura += temperaturas[i];
    }
    limpar_tela(); // Limpar tela
    media_temperatura = total_temperatura / QUANTIDADE; // calcular media


    // Imprimir na tela as 10 temperaturas
    for (int i = 0; i < QUANTIDADE; i++) {
        printf("Temperatura %d: %.2f °C\t", i+1, temperaturas[i]);
        quente_ou_frio(temperaturas[i]); // Checar se temperatura é maior ou menor que 20
    }
    printf("\n");
    temperatura_min = menor_temperatura(temperaturas);
    temperatura_max = maior_tempertura(temperaturas);

    printf("Temperatura Máxima: %.1f °C\tTemperatura Mínima: %.1f °C\tMedia das temperaturas: %.1f °C\n", temperatura_max, temperatura_min, media_temperatura);
    return 0;
}

