/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Calculadora de médias                       |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Escreva um programa que calcule a média de N notas |
 | digitadas pelo usuário. O usuario devera informar o valor de N|
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>

void calcularMedia(int quantidadeNotas, float *media) {
    float totalNotas=0.0f, nota;
    for (int i=0;i<quantidadeNotas; i++) {
        printf("Digite a nota %d: ", i+1);
        scanf("%f", &nota);
        totalNotas += nota; // Acumular todas as notas digitadas pelo usuário
    }
    system("clear || cls");
    *media = totalNotas / quantidadeNotas;
}

int main() {
    int quantidadeNotas;
    float media=0.0;

    system("clear || cls"); // Limpar tela

    do { // Ter certeza que o usuário digitará um numero positivo para a quantidade de notas
        printf("Digite a quantidade de notas que voce deseja calcular\n");
        scanf("%d", &quantidadeNotas);
    }while (quantidadeNotas <=0); 

    system("clear || cls");
    calcularMedia(quantidadeNotas,&media); // Chamada da função para calcular a média das notas
    // Imprimir a média que foi calculada
    printf("Media: %.2f\n", media);

    printf("Digite Enter para sair...");
    while (getchar() != '\n');
    getchar();
    system("clear || cls");
    return 0;
}
