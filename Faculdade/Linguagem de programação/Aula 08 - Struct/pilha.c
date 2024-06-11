/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 28/05/2024
  Nome do programa: Pilha struct
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Escreva o código que implemente uma pilha estática de números inteiros, utilizando struct.

 *****************************************************************************************************************************************/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Estrutura para a pilha
typedef struct Spilha {
	int elementos[MAX];
	int topo;
}TPilha;

// Função para inicializar a pilha
void inicializar_pilha(TPilha *pilha) {
	pilha->topo = -1;
}

// Função para parar o programa até o usuário pressinar Enter e limpar a tela
void pause() {
    while (getchar() != '\n');
    printf("Aperte Enter para continuar...");
    getchar();
    system("clear || cls");
}

// Função para adicionar um elemento na pilha
int push (TPilha *pilha) {
	printf("* * * * *  P U S H * * * * *\n\n");
	if (pilha->topo < MAX - 1) { // Verificar se a pilha esta cheia
		pilha->topo = pilha->topo + 1;
		printf("\nDigite o elemento a ser inserido: ");
		scanf("%d", &pilha->elementos[pilha->topo]);
		printf("\n\nElemento inserido com sucesso!!\n\n");
		pause();
		return 0;
	} else {
		printf("\nImpossível inserir\nPilha cheia...\n\n");
		pause();
		return 1;
	}
}

// Função para remover um elemento da pilha
int pop(TPilha *pilha) {
	printf("* * * * *  P O P  * * * * *\n\n");
	if (pilha->topo >= 0) { // Verificar se a pilha está vazia
		pilha->topo = pilha->topo - 1; // Decrementar o topo para remover o elemento
		printf("\nElemento removido com sucesso!!\n");
		pause();
		return 0;
	} else {
		printf("\nImpossivel remover\nPilha vazia...\n\n");
		pause();
		return 1;
	}
}

// Função para imprimir os elementos da pilha
void imprimir(TPilha pilha) {
	printf("* * * * *  I M P R E S S Ã O  * * * * * *\n\n");
	if (pilha.topo>=0) { // Verificar se a pilha está vazia
		for (int i=pilha.topo;i>=0;i--) { // Estrutura de repetição para imprimir todos os elementos da pilha
			printf("%d\n", pilha.elementos[i]);
		}
	} else {
		printf("Impossivel imprimir\nPilha está vazia...\n\n");
	}
	pause(); // Pausar o programa para o usuário ver o resultado e limpar a tela
}

// Função para imprimir o menu e receber a opção que o usuario deseja
void menu(int *opt) {
	printf("* * * * *  M E N U  * * * * *\n");
	printf("\n1 - Push");
	printf("\n2 - Pop");
	printf("\n3 - Imprimir");
	printf("\n9 - Sair");
	printf("\nDigite a opção desejada: ");
	scanf("%d", opt);
	system("clear || cls"); // Limpar a tela
}


int main() {
	TPilha pilha;
	int opt;

	// Habilitar o uso de acentos
	setlocale(LC_ALL, "");

	// Inicializar a pilha com o topo=-1
	inicializar_pilha(&pilha);
	do {
		system("clear || cls");
		menu(&opt);
		switch (opt) {
			case 1: // Push
				push(&pilha);
				break;
			case 2: // Pop 
				pop(&pilha);
				break;
			case 3: // Imprimir
				imprimir(pilha);
				break;
		}
	}while (opt != 9); // Condição para decidir se o programa deve continuar rodando ou para sair
}
