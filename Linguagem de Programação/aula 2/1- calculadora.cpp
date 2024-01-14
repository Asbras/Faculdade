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

#include <iostream>

int main(int argc, char *argv[])
{
    float a, b;
    char operador;

    // Escanear o valor da operação
    std::cout << "Qual operação voce deseja? (+, -, /, *)" << std::endl;
    std::cin >> operador;
    // Escanear o valor dos operandos
    std::cout << "Digite o valor de a e de b" << std::endl;
    std::cin >> a >> b;

    // Estrutura para decidir qual operção o usuário deseja
    switch (operador) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", a, b, (a+b)); // Imprimir soma dos números digitados
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

