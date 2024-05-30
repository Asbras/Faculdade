/****************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 27/05/2024
  Nome do programa: Verificador de Triangulos
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

// Função para checar se as medidas digitadas pelo usuário fomam um triangulo
int forma_triangulo(float a, float b, float c) {
    if (a+b>c && a+c>b && b+c> a) {
        return 1;
    } else {
        return 0;
    }
}
// Função para classificar o triangulo
void tipo_triangulo(float a, float b, float c) {
    if (a == b && a == c ) { // Verificar se o triangulo é Equilátero
        printf("O triangulo é equilátero\n");
    } else if (a != b && b != c) { // Verificar se o triangulo é Escaleno
        printf("O triangulo é Escaleno\n");
    } else { // Caso o triangulo nao seja equilátero ou escaleno ele é Isóceles
        printf("O triangulo é Isóceles\n");
    }
}

void pause() {
    while (getchar()!='\n');
    printf("\nPressione Enter para continuar...");
    getchar();
    system("clear || cls");
}

int main() {
    float lado1, lado2, lado3;

    system("clear || cls");
    // Receber as medidas do primeiro lado
    printf("Digite o tamanho do primeiro lado: ");
    scanf("%f", &lado1);

    // Validar a entrada do primeiro lado com valores maiores que zero
    while (lado1<=0) {
        printf("Valor inválido. Digite o tamanho maior do que zero para primeiro lado: ");
        scanf("%f", &lado1);
    }

    // limpar a tela
    system("clear || cls");

    // Receber as medidas do segundo lado
    printf("Digite o tamanho do segundo lado: ");
    scanf("%f", &lado2);

    // Validar a entrada do segundo lado com valores maiores que zero
    while (lado2<=0) {
        printf("Valor inválido. Digite o tamanho maior do que zero para segundo lado: ");
        scanf("%f", &lado2);
    }

    // limpar a tela
    system("clear || cls");

    // Receber as medidas do terceiro lado
    printf("Digite o tamanho do terceiro lado: ");
    scanf("%f", &lado3);

    // Validar a entrada do terceiro lado com valores maiores que zero
    while (lado3<=0) {
        printf("Valor inválido...\n Digite o tamanho maior do que zero para terceiro lado: ");
        scanf("%f", &lado3);
    }

    // limpar a tela
    system("clear || cls");

    // testar se as medidas digitadas formam um triangulo
    if (forma_triangulo(lado1,lado2,lado3)) {
        tipo_triangulo(lado1,lado2,lado3); // Classificar o triangulo de acordo com os valores digitados pelo usuário
    } else {
        printf("As medidas não formam um triangulo\n");
    }
    pause();

    return 0;
}
