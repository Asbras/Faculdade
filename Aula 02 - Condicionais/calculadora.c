/****************************************V************************
  Autor: Leonardo Carnio Della Torre                            
  Data:                                                         
  Nome do programa: Calculadora usando switch/case              
  Disciplina: Linguagem de Programação                          
  Professor: Fernando Marco Perez Ramos                         
  Descrição: Implemente uma calculadora com 4 operações usando  
  switch case. O usuário deverá entrar com os valores do operan-
  dos e da operação que o programa deverá fornecer o resultado  
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
void soma(float a, float b) {
    printf("%.2f + %.2f = %.2f\n", a, b, a+b);
}

void subtracao(float a, float b) {
    printf("%.2f - %.2f = %.2f\n", a, b, a-b);
}

void multiplicacao(float a, float b) {
    printf("%.2f x %.2f = %.2f\n", a, b, a+b);
}

void divisao(float a, float b) {
    printf("%.2f / %.2f = %.2f\n", a, b, a+b);
}

void menu(int *opt) {
    printf("* * * * *  MENU  * * * * *\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("Digite a opção: ");
    scanf("%d", opt);
}

int main() {
    float a, b;
    int opt;

    system("clear");
    menu(&opt);
    system("clear");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);
    printf("\nDigite o segundo número: ");
    scanf("%f", &b);
    system("clear");
    switch (opt) {
        case 1: // Adição
            soma(a,b);
            break;
        case 2: // Subtração
            subtracao(a,b);
            break;
        case 3: // Multiplicação
            multiplicacao(a,b);
            break;
        case 4:
            if (b != 0) {
                divisao(a,b);
            } else {
                printf("Não existe divisão por zero");
            }
            break;
    }
}
