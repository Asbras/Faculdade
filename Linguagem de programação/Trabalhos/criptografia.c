/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 10/06/2024
  Nome do programa: 
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Escreva um programa que leia um arquivo texto e após a criptografia do arquivo lido escreva o texto criptografado no mesmo arquivo.
Continue o programa para fazer o contrário (descriptografar um texto gravado em um arquivo).USE O ARQUIVO TEXTO NA PASTA DO PROJETO COM O NOME 
TEXTO.TXT.

	Menu
	1 – Criptografar texto
	2 – Descriptografar texto
	3 – Mostrar texto
	9 - Sair
 *****************************************************************************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void menu(int *op) {
	printf("* * * * *  M E N U  * * * * *\n\n");
	printf("1 - Criptografar Texto\n");
	printf("2 - Descriptografar Texto\n");
	printf("3 - Mostrar Texto\n");
	printf("9 - Sair\n");
	printf("Digite a opção desejada: ");
	scanf("%d", op);
	getchar();
}

void pause() {
	printf("Aperte Enter para continuar...");
	while (getchar() != '\n');
	system("clear || cls");
}

int criar_arquivo(FILE *arquivo) { // Criar um arquivo e escrever meu nome e ciadade onde eu moro
	arquivo = fopen("texto.txt", "w");
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}
	fprintf(arquivo, "Leonardo Carnio Della Torre\nRibeirão Preto\n");
	fclose(arquivo);
	return 0;
}

int criptografar_texto(FILE *arquivo) {
	arquivo = fopen("texto.txt", "r");// Abrir arquivo no modo de leitura

	// Garantir que o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}

	char conteudo[100000]="", linha[1000];
	// Ler o arquvio todo e copiar o conteúdo
	while (fgets(linha, sizeof(linha),arquivo) != NULL) {
		strcat(conteudo, linha);
	}
	fclose(arquivo);
	
	// criptografar o conteudo lido no arquivo com a cifra de Cesar
	for (int i=0; i < strlen(conteudo); i++) {
		if (conteudo[i] != '\n') {
			conteudo[i] += 3;
		}
	}

	arquivo = fopen("texto.txt", "w");// Abrir arquivo no modo de escrita
	
	// Garantir que o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}

	fputs(conteudo, arquivo);
	fclose(arquivo);
	return 0;
}

int descriptografar_texto(FILE *arquivo) {
	arquivo = fopen("texto.txt", "r");// Abrir arquivo no modo de leitura

	// Garantir que o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}

	char conteudo[100000]="", linha[1000];
	// Ler o arquvio todo e copiar o conteúdo
	while (fgets(linha, sizeof(linha),arquivo) != NULL) {
		strcat(conteudo, linha);
	}
	fclose(arquivo);
	
	// descriptografar o conteudo lido no arquivo com a cifra de Cesar
	for (int i=0; i < strlen(conteudo); i++) {
		if (conteudo[i] != '\n') {
			conteudo[i] -= 3;
		}
	}

	arquivo = fopen("texto.txt", "w");// Abrir arquivo no modo de escrita
	
	// Garantir que o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}

	fputs(conteudo, arquivo);
	fclose(arquivo);
	return 0;

}

int mostrar_texto(FILE *arquivo) {
		arquivo = fopen("texto.txt", "r");// Abrir arquivo no modo de leitura

	// Garantir que o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("\nProblema ao abrir o arquivo\n\n");
		return 1;
	}
	char conteudo[100000]="", linha[1000];
	// Ler o arquvio todo e copiar o conteúdo
	while (fgets(linha, sizeof(linha),arquivo) != NULL) {
		strcat(conteudo, linha);
	}
	fclose(arquivo);
	printf("\n%s\n", conteudo);
	return 0;
}

int main(void) {
	FILE *arquivo;
	int op;

	criar_arquivo(arquivo);
	do {
		menu(&op);
		system("clear || cls");
		switch (op) {
			case 1:// Criptografar o texto
				criptografar_texto(arquivo);
				system("clear || cls");
				break;
			case 2:// Descriptografar o texto
				descriptografar_texto(arquivo);
				system("clear || cls");
				break;
			case 3:// Mostrar o texto no terminal
				mostrar_texto(arquivo);
				pause();
				break;
			default:
				printf("\nOpção inválida");
		}
	}while (op != 9);//Repetir até que o usuário digite 9 para sair
}
