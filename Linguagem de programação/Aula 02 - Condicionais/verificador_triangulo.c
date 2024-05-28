/****************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 27/05/2024
  Nome do programa: Verificador de Idade
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa em C que leia três valores correspondentes aos lados de um triângulo. O programa deve 
  verificar se esses valores podem formar um triângulo. Caso possam, deve determinar o tipo de triângulo formado:

    - Equilátero: todos os lados iguais
    - Isósceles: dois lados iguais
    - Escaleno: todos os lados diferentes
  *************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int forma_triangulo(float a, float b, float c) {
    if (a+b>c && a+c>b && b+c> a) {
        return 1;
    } else {
        return 0;
    }
}

void tipo_triangulo(float a, float b, float c) {
    if (a == b && a == c ) { // Verificar se o triangulo é Equilátero
        printf("O triangulo é equilátero\n");
    } else if (a != b && b != c) { // Verificar se o triangulo é Escaleno
        printf("O triangulo é Escaleno\n");
    } else { // Caso o triangulo nao seja equilátero ou escaleno ele é Isóceles
        printf("O triangulo é Isóceles\n");
    }
}
int main() {
    float lado1, lado2, lado3;

    // Receber as medidas digitadas pelo usuário
    printf("Digite o tamanho do primeiro lado: ");
    scanf("%f", &lado1);
    printf("Digite o tamanho do segundo lado: ");
    scanf("%f", &lado2);
    printf("Digite o tamanho do terceiro lado: ");
    scanf("%f", &lado3);
    // limpar a tela
    system("clear || cls");

    // testar se as medidas digitadas formam um triangulo
    if (forma_triangulo(lado1,lado2,lado3)) {
        tipo_triangulo(lado1,lado2,lado3); // Classificar o triangulo de acordo com os valores digitados pelo usuário
    } else {
        printf("As medidas não formam um triangulo\n");
    }

    return 0;
}
