/****************************************V************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Calculadora usando switch/case              |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Implemente uma calculadora com 4 operações usando  | 
 | switch case. O usuário deverá entrar com os valores do operan-|
 | dos e da operação que o programa deverá fornecer o resultado  |
 ****************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    float a, b;
    char operador;

    // Escanear o valor da operação
    printf("Qual operação voce deseja fazer?\n");
    scanf("%c", &operador);

    // Escanear o valor dos operandos
    printf("Digite os valores que deseja calcular:\n");
    scanf("%f %f", &a, &b);

    // Estrutura para decidir qual operção o usuário deseja
    switch (operador) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", a, b, (a+b)); // Imprimir soma dos números digitados
            printf("DEBUGPRINT[2]: 1- calculadora.c:30 (after printf(%.2f + %.2f = %.2fn, a, b, (a+b))…)\n");
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", a, b, (a-b)); // Imprimir subtração dos números digitados
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", a, b, (a*b)); // Imprimir a multiplicação dos números digitados
            break;
        case '/':
            if (b != 0) {
                printf("%.2f / %.2f = %.2f\n", a, b, (a/b)); // Imprimir a divisão dos números digitados
            }else {
                printf("Impossível dividir por zero!!!\n"); // Avisar o usuário que divisão por zero não é possivel
            }
            break;
        default:
            printf("Operação inválida\n");
    }
    return 0;
}

