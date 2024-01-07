#include <stdio.h>
#define TAMANHO 10


int main(int argc, char *argv[])
{

    float temperatura[TAMANHO];
    // Ler 10 temperaturas do usuário
    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o valor da temperatura %d:\n", i+1);
        scanf("%f", &temperatura[i]);
    }
    // imprimir na tela as 10 temperaturas
    for (int i = 0; i < TAMANHO; i++) {
        printf("Temperatura %d: %.2f °C\n", i+1, temperatura[i]);
    }
    return 0;
}
