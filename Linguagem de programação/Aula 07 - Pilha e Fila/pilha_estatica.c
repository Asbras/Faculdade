#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void limpar_tela() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

int main() {
	int pilha[MAX];
	int topo=-1, op, elemento;

	do {
		limpar_tela();
		printf("* * * * *  M E N U  * * * * *");
		printf("\n1 - Push");
		printf("\n2 - Pop");
		printf("\n3 - Imprimir");
		printf("\n9 - Sair");
		printf("\n\nDigite a sua opcao: ");
		scanf("%d",&op);
		limpar_tela();

		switch (op) {
			case 1:
				if (topo<MAX-1) {
					printf("Digite um número para inserir na pilha: ");
					scanf("%d",&elemento);
					topo++;
					pilha[topo]=elemento;
					printf("\nElemento inserido com sucesso!!\n");
				} else {
					printf("\nImpossível inserir...\nA pilha está cheia");
				}
				getchar();
				getchar();
				limpar_tela();
				break;
			case 2:
				if (topo<MAX-1) {
					topo--;
					printf("\nElemento removido com sucesso!!");
				} else {
					printf("Impossivel remover...\nA pilha está vazia");
				}
				getchar();
				getchar();
				limpar_tela();
				break;
			case 3:
				printf("* * * * *  P I L H A  * * * * *\n\n");
				for (int i=topo; i>=0; i--) {
					printf("\n%d",pilha[i]);
				}
				printf("\n\n");
				getchar();
				getchar();
				break;
		}
	
	}while (op!=9);
	return 0;
}
