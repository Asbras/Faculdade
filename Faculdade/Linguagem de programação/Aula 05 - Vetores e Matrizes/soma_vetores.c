/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 29/05/2024
  Nome do programa: Soma de vetores
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa em C que realize a soma de dois vetores e armazene o resultado em um terceiro vetor. Os vetores devem ter o mesmo tamanho, que será fornecido pelo usuário. O programa deve seguir as seguintes etapas:

    1.Solicitar ao usuário o tamanho dos vetores.
    2.Solicitar ao usuário os elementos do primeiro vetor.
    3.Solicitar ao usuário os elementos do segundo vetor.
    4.Calcular a soma de cada par de elementos correspondentes nos dois vetores e armazenar o resultado em um terceiro vetor.
    4.Imprimir o terceiro vetor, que conterá a soma dos elementos.
 *****************************************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>


void ler_vetor(float v[], int tamanho) {
        for (int i=0; i<tamanho; i++) {
        printf("Digite o valor %d: ", i+1);
        while (scanf("%f", &v[i]) != 1) {
            printf("valor inválido... Digite um valor %d", i+1);
            fflush(stdin);
        }
    }
}

void somar_vetores(float v1[], float v2[], float soma[], int tamanho) {
    for (int i=0; i<tamanho; i++) {
        soma[i] = v1[i] + v2[i];
    }
}

void imprimir_vetor(float v[], int tamanho) {

    for (int i = 0; i<tamanho; i++) {
        printf("[%.2f] ", v[i]);
    }
    printf("\n\n");
}

int main() {
    int tamanho;

    system("clear");
    printf("Digite o tamanho dos vetores que voce deseja: ");
    while (scanf("%d", &tamanho) != 1 || tamanho <=0) {
        printf("Tamanho inválido, por favor, digite um valor positivo para o tamanho: ");
        fflush(stdin);
    }
    system("clear");

    float vetor1[tamanho], vetor2[tamanho], soma[tamanho];

    ler_vetor(vetor1,tamanho);
    system("clear");
    ler_vetor(vetor2,tamanho);
    system("clear");

    printf("* * * * * PRIMEIRO VETOR * * * * *\n\n");
    imprimir_vetor(vetor1,tamanho);
    printf("* * * * * SEGUNDO VETOR * * * * *\n\n");
    imprimir_vetor(vetor2,tamanho);
    somar_vetores(vetor1,vetor2,soma,tamanho);
    printf("* * * * * SOMA  DOS VETORES * * * * *\n\n");
    imprimir_vetor(soma,tamanho);
    printf("\n\nPressione Enter para sair...");
    while (getchar() != '\n');
    getchar();
    system("clear");

    return 0;
}
