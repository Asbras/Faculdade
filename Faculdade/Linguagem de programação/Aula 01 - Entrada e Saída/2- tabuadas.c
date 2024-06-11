/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Impressora de tabuadas escolhendo valores   |
 | Disciplina: Linguagem de programação                          | 
 | Professor: Fernando Marco Perez Campos                        |
 | Descrição: Escreva um programa em C/C++ que implemente quatro |
 | tabuadas que você escolher ocupando os quatro quadrantes da   |
 | tela fazendo com que o usuário escolha as tabuadas a serem    |
 | impressas.                                                    |
 ****************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num_1, num_2, num_3, num_4;
    printf("Digite os valores que voce deseja imprimir:\n");
    scanf("%i %i %i %i", &num_1, &num_2, &num_3, &num_4);
    printf("\n\n\n");
    printf("%02d x 02 = %02d\t\t\t\t\t\t %02d x 02 = %02d\n", num_1, num_1 * 2, num_2, num_2 * 2);
    printf("%02d x 03 = %02d\t\t\t\t\t\t %02d x 03 = %02d\n", num_1,num_1 * 3, num_2, num_2 * 3);
    printf("%02d x 04 = %02d\t\t\t\t\t\t %02d x 04 = %02d\n", num_1,num_1 * 4, num_2, num_2 * 4);
    printf("%02d x 05 = %02d\t\t\t\t\t\t %02d x 05 = %02d\n", num_1,num_1 * 5, num_2, num_2 * 5);
    printf("%02d x 06 = %02d\t\t\t\t\t\t %02d x 06 = %02d\n", num_1,num_1 * 6, num_2, num_2 * 6);
    printf("%02d x 07 = %02d\t\t\t\t\t\t %02d x 07 = %02d\n", num_1,num_1 * 7, num_2, num_2 * 7);
    printf("%02d x 08 = %02d\t\t\t\t\t\t %02d x 08 = %02d\n", num_1,num_1 * 8, num_2, num_2 * 8);
    printf("%02d x 09 = %02d\t\t\t\t\t\t %02d x 09 = %02d\n", num_1,num_1 * 9, num_2, num_2 * 9);
    printf("%02d x 10 = %02d\t\t\t\t\t\t %02d x 10 = %02d\n", num_1,num_1 * 10, num_2, num_2 * 10);
    printf("\n\n\n");
    printf("%02d x 02 = %02d\t\t\t\t\t\t %02d x 02 = %02d\n", num_3, num_3 * 2, num_4, num_4 * 2);
    printf("%02d x 03 = %02d\t\t\t\t\t\t %02d x 03 = %02d\n", num_3,num_3 * 3, num_4, num_4 * 3);
    printf("%02d x 04 = %02d\t\t\t\t\t\t %02d x 04 = %02d\n", num_3,num_3 * 4, num_4, num_4 * 4);
    printf("%02d x 05 = %02d\t\t\t\t\t\t %02d x 05 = %02d\n", num_3,num_3 * 5, num_4, num_4 * 5);
    printf("%02d x 06 = %02d\t\t\t\t\t\t %02d x 06 = %02d\n", num_3,num_3 * 6, num_4, num_4 * 6);
    printf("%02d x 07 = %02d\t\t\t\t\t\t %02d x 07 = %02d\n", num_3,num_3 * 7, num_4, num_4 * 7);
    printf("%02d x 08 = %02d\t\t\t\t\t\t %02d x 08 = %02d\n", num_3,num_3 * 8, num_4, num_4 * 8);
    printf("%02d x 09 = %02d\t\t\t\t\t\t %02d x 09 = %02d\n", num_3,num_3 * 9, num_4, num_4 * 9);
    printf("%02d x 10 = %02d\t\t\t\t\t\t %02d x 10 = %02d\n", num_3,num_3 * 10, num_4, num_4 * 10);
    return 0;
}

