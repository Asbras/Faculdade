// Escreva um algoritmo que implemente uma calculadora com quatro operações usando switch case.
// O usuário deverá entrar com os valores do operandos e da operação e o programa deverá fornecer
// o resultado.
#include <stdio.h>
int main(int argc, char *argv[])
{
    float a, b;
    char operador;
    printf("Qual operação voce deseja fazer?\n");
    scanf("%c", &operador);
    printf("Digite os valores que deseja calcular:\n");
    scanf("%f %f", &a, &b);
    switch (operador) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", a, b, (a+b));
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", a, b, (a-b));
            break;
        case '*':
            printf("%.2f - %.2f = %.2f\n", a, b, (a*b));
            break;
        case '/':
            if (b != 0) {
                printf("%.2f - %.2f = %.2f\n", a, b, (a/b));
            }else {
                printf("Impossível dividir por zero!!!\n");
            }
            break;
        default:
            printf("Operação inválida\n");

    }
    return 0;
}
