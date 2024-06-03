/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 03/06/2024
  Nome do programa: Média de notas.
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Este programa em C calcula a média de um conjunto de notas inseridas pelo usuário. A média é calculada de forma dinâmica, 
  permitindo que o usuário especifique a quantidade de notas a serem consideradas. A funcionalidade principal do programa é dividida em 
  várias etapas, desde a entrada de dados até a saída dos resultados.

 *****************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

float calcular_media(int n, float notas[]) {
	float total_notas=0;

	// Acumular todas a notas no vetor de notas.
	for (int i = 0; i < n; i++) {
		total_notas += notas[i];
	}

	// Retornar a média
	return total_notas/n;
}

int main(void) {
	int quantidade;
	float *vetor_notas, media;

	// Receber a quantidade de notas que o usuário deseja inserir para calcular a nota.
	printf("Digite a quantidade de notas que voce deseja calcular a média: ");
	scanf("%d",&quantidade);

	// Alocar memória necessária para a quantidade de notas escolhidas pelo usuário.
	vetor_notas = (float *) malloc(quantidade*sizeof(float));
	// Garantir que a alocação de memória foi alocada com sucesso, caso não tenha sido, sucasse aboratar o programa.
	if (vetor_notas==NULL) {
		printf("Memória insuficiente.\n");
		return 1;	
	}

	// Receber as notas digitadas pelo usuário.
	for (int i=0; i < quantidade; i++) {
		printf("Digite a nota %d: ", i+1);
		scanf("%f", &vetor_notas[i]);
	}

	// Calcular a média.
	media = calcular_media(quantidade, vetor_notas);

	// Imprimir a média para o usuário.
	printf("Media = %.2f", media);

	// Liberar memória.
	free(vetor_notas);
	return 0;
}


