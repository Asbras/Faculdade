// Escreva um programa em C++ que receba um valor e verifique se está no nao em cada um 
// dos seguintes intervalos:
//      a. [7,10[
//      b. [28,30[
//      c. ]35,40] ou [90,100]
//      d. 100 ou [200,300] ou ]500,600[
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
    int valor;
    bool esta_contido = false;
    printf("Digite um valor:\n");
    scanf("%i", &valor);
    if (valor >= 7 && valor < 10) {
        printf("O valor digitado está entre [7,10[\n");
        esta_contido = true;
    }
    if (valor >= 28 && valor < 30) {
        printf("O valor digitado está entre [28,30[\n");
        esta_contido = true;
    }
    if ((valor > 35 && valor <= 40) || (valor >= 90 && valor <= 100)) {
        printf("O valor digitado está entre ]35,40] ou entre [90,100]\n");
        esta_contido = true;
    }
    if ((valor == 100) || (valor >= 200 && valor <= 300) || (valor > 500 && valor < 600)) {
        printf("O valor digitado é 100 ou está entre [200,300] ou entre ]500,600]\n");
        esta_contido = true;
    }
    if (esta_contido == false) {
        printf("O valor nao esta contido em nenhum intervalo\n");
    }
    return 0;
}
