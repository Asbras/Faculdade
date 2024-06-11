#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void menu(int *op) {
	printf("* * * * *  M E N U  * * * * *\n\n");
	printf("\n1 - Inserir");
	printf("\n2 - Remover");
	printf("\n3 - Imprimir");
	printf("\n9 - Sair");
	printf("\n\nDigite a sua opção: ");
	scanf("%d", op);
}

void inserir(int *fim, int fila[]) {
	int elemento;
	printf("* * * * * I N S E R I R * * * * *\n\n");
	if (*fim<(MAX-1)) {
		printf("\nDigite o numero que deseha inserir na fila: ");
		scanf("%d", &elemento);
		(*fim)++;
		fila[*fim] = elemento;
		printf("\nElemento inserido com sucesso!!\n");
	} else {
		printf("\nImpossível inserir. Fila cheia\n\n");
	}
}

void remover(int *fim, int fila[]) {
	printf("\nO elemento removido é: %d\n",fila[0]);
	if (*fim>=0) {
		for (int i=0; i < MAX; i++) {
			fila[i]=fila[i+1];
		}
		(*fim)--;
		printf("\nElemento removido com sucesso!\n");
	} else {
		printf("\nImpossível remover. Fila vazia\n\n");
	}
}

void imprimir(int fila[], int fim) {
    printf("* * * * *  F I L A  * * * * *\n\n");
    if (fim >= 0) {
        for (int i = 0; i <= fim; i++) {
            printf("\t%d", fila[i]);
        }
    } else {
        printf("\nFila vazia\n");
    }
    printf("\n\n");
}

int main(void) {
	int fila[MAX], op, fim=-1;

	do {
		menu(&op);
		switch (op) {
			case 1:
				system("clear");
				inserir(&fim,fila);
				break;
			case 2:
				system("clear");
				remover(&fim,fila);
				break;
			case 3:
				system("clear");
				imprimir(fila,fim);
				break;
		}
		getchar();
		getchar();
		system("clear");
	}while (op != 9);
}
