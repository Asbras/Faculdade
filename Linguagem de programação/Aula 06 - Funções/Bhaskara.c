/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data: 24/05/2024                                              |
 | Nome do programa: Calculadora de raizes de parabola
 | Disciplina: Linguagem de programação                          | 
 | Professor: Fernando Marco Perez Campos                        |
 | Descrição:  Escreva um programa que leia os valores de A, B   |
 | e C de uma função de segundo grau e retorne o delta, as raízes|
 | e os vértices. Utilize obrigatoriamente funções (delta, x1,   |
 | x2, vx, vy).                                                  |
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular delta
double calcularDelta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

// Função para calcular raiz 1
double calcularRaiz1(double a, double b, double delta) {
    return (-b + sqrt(delta)) / (2 * a);
}

// Função para calcular raiz 2
double calcularRaiz2(double a, double b, double delta) {
    return (-b - sqrt(delta)) / (2 * a);
}

// Função para calcular o vértice de X
double calcularVx(double a, double b) {
    return -b / (2 * a);
}

// Função para calcular o vértice de Y
double calcularVy(double a, double delta) {
    return -delta / (4 * a);
}

int main() {
    double a, b, c, delta, raiz1, raiz2, vx, vy;

    // Receber os coeficientes da equação quadrática
    system("clear");
    printf("Digite os coeficientes a, b e c da função quadrática ax² + bx + c:\n\n");

    // Loop para garantir que 'a' seja diferente de zero
    do {
        printf("Digite o valor de a (O valor deve ser diferente de 0): ");
        scanf("%lf", &a);
    } while (a == 0);

    printf("\nDigite o valor de b: ");
    scanf("%lf", &b);
    printf("\nDigite o valor de c: ");
    scanf("%lf", &c);

    system("clear");

    // Calcular o valor de Delta
    delta = calcularDelta(a, b, c);

    if (delta >= 0) {
        raiz1 = calcularRaiz1(a, b, delta);
        raiz2 = calcularRaiz2(a, b, delta);
        vx = calcularVx(a, b);
        vy = calcularVy(a, delta);

        printf("Delta = %.2lf\n\n", delta);

        if (delta > 0) {
            printf("Raízes reais:\n\nR1 = %.2lf\nR2 = %.2lf\n\n", raiz1, raiz2);
        } else {
            printf("Raíz única (duplicada):\n\nR = %.2lf\n\n", raiz1);
        }

        printf("Vértices:\n\nVx = %.2lf\nVy = %.2lf\n\n", vx, vy);
    } else {
        printf("O delta é negativo...\nA equação não possui raízes reais.\n");
    }

    printf("Pressione qualquer tecla para sair...");
    getchar();
    getchar();
    system("clear");
    return 0;
}
