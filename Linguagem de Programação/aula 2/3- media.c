/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Calculadora de médias                       |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Escreva um programa que calcule a média de N notas |
 | digitadas pelo usuário. O usuario devera informar o valor de N|
 ****************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    float nota, soma_notas = 0, media_notas = 0;
    int quantidade_notas;
    printf("Digite a quantidade de notas que voce quer calcular\n");
    scanf("%d", &quantidade_notas);
    for (int i = 0; i < quantidade_notas; i++) {
        printf("Digite o valor da nota %d:\n", i+1);
        scanf("%f", &nota);
        soma_notas += nota;
    }
    media_notas = soma_notas / quantidade_notas;
    printf("Media: %.2f\n", media_notas);
    return 0;
}

