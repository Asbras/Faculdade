// Escreva um programa que calcule a média de N notas digitadas pelo usuario.
// O usuário deverá entrar com o valor de N antes das leituras de notas.
#include <stdio.h>

int main(int argc, char *argv[])
{
    float nota, soma_notas = 0, media_notas = 0;
    int quantidade_notas;
    printf("Digite a quantidade de notas que voce quer calcular\n");
    scanf("%d", &quantidade_notas);
    for (int i = 0; i < quantidade_notas; i++) {
        printf("Digite o valor da nota %d:\n", i+1);
        scanf("%f", &nota);
        soma_notas += nota;
    }
    media_notas = soma_notas / quantidade_notas;
    printf("Media: %.2f\n", media_notas);
    return 0;
}

