#include <stdlib.h>
#include <stdio.h>

// Função para calcular o fatorial de maneira recursiva
int fat(int n) {
    if (n==0) {
        return 1;
    } else {
        return n*fat(n-1);
    }
}


int main(void) {
    int n, fatorial=0;

    printf("Digite o número que voce deseja calcular o fatorial: ");
    scanf("%d", &n);
    system("clear");
    fatorial=fat(n);
    printf("fatorial de %d: %d\n", n,fatorial);
    return 0;
}
