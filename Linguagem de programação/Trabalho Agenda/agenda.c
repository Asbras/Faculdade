/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 08/06/2022
  Nome do programa: Agenda de contatos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: uma agenda de contatos em C que permite ao usuário inserir, remover, procurar e mostrar contatos. Cada contato tem campos para nome, endereço e telefone. A agenda armazena os contatos em uma lista ligada ordenada alfabeticamente pelo nome. O programa inclui um menu de opções que permite ao usuário:

    1. Inserir um novo contato na lista.
    2. Remover um contato da lista pelo nome.
    3. Procurar um contato pelo nome e exibir seus detalhes.
    4. Mostrar todos os contatos da agenda em ordem alfabética.
 *****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para pausar a execução até que o usuário pressione Enter
void pausar() {
	printf("\n\nAperte Enter para continuar...");
	while (getchar() != '\n');
	system("clear || cls");  // Limpa a tela (compatível com Unix e Windows)
}

// Estrutura para armazenar os dados de um contato
typedef struct {
	char nome[50];
	char endereco[50];
	char telefone[50];
} Contato;

// Estrutura para a agenda, que é uma lista encadeada de contatos
typedef struct Agenda {
	Contato contato;
	struct Agenda *prox;
} Agenda;

// Função para criar uma nova agenda (inicialmente vazia)
Agenda *criar_agenda() {
	return NULL;
}

// Função para inserir um contato na agenda em ordem alfabética
Agenda *inserir_agenda(Agenda *agenda, Contato contato) {
	printf("* * * * * I N S E R I R * * * * *\n\n");
	// Cria um novo nó para o contato
	Agenda *novo = (Agenda *)malloc(sizeof(Agenda));
	strcpy(novo->contato.nome, contato.nome);
	strcpy(novo->contato.endereco, contato.endereco);
	strcpy(novo->contato.telefone, contato.telefone);
	novo->prox = NULL;

	// Insere no início se a agenda estiver vazia ou se o novo contato for menor que o primeiro
	if (agenda == NULL || strcasecmp(contato.nome, agenda->contato.nome) < 0) {
		novo->prox = agenda;
		return novo;
	}

	// Encontra a posição correta para inserir o novo contato
	Agenda *atual = agenda;
	while (atual->prox != NULL && strcasecmp(contato.nome, atual->prox->contato.nome) > 0) {
		atual = atual->prox;
	}
	novo->prox = atual->prox;
	atual->prox = novo;
	return agenda;
}

// Função para remover um contato da agenda pelo nome
Agenda *remover_agenda(Agenda *agenda, char nome[50]) {
	printf("* * * * * R E M O V E R * * * * *\n\n");
	// Se a agenda estiver vazia
	if (agenda == NULL) {
		return NULL;
	}

	// Se o contato a ser removido estiver no início da lista
	if (strcasecmp(agenda->contato.nome, nome) == 0) {
		Agenda *aux = agenda;
		agenda = agenda->prox;
		free(aux);
		return agenda;
	}

	// Encontra o contato a ser removido
	Agenda *atual = agenda;
	while (atual->prox != NULL && strcasecmp(atual->prox->contato.nome, nome) != 0) {
		atual = atual->prox;
	}

	// Remove o contato se encontrado
	if (atual->prox != NULL) {
		Agenda *aux = atual->prox;
		atual->prox = aux->prox;
		free(aux);
	}

	return agenda;
}

// Função para procurar um contato na agenda pelo nome
Agenda *procurar_agenda(Agenda *agenda, char nome[50]) {
	printf("* * * * * P R O C U R A R * * * * *\n\n");
	Agenda *aux = agenda;
	while (aux != NULL) {
		if (strcasecmp(aux->contato.nome, nome) == 0) {
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}

// Função para mostrar todos os contatos da agenda
void mostrar_agenda(Agenda *agenda) {
	printf("* * * * * I M P R I M I N D O * * * * *\n\n");
	Agenda *aux = agenda;
	while (aux != NULL) {
		printf("Nome: %s\n", aux->contato.nome);
		printf("Endereco: %s\n", aux->contato.endereco);
		printf("Telefone: %s\n\n", aux->contato.telefone);
		aux = aux->prox;
	}
}

// Função para exibir o menu de opções
void menu() {
	printf("1. Inserir contato\n");
	printf("2. Remover contato\n");
	printf("3. Procurar contato\n");
	printf("4. Mostrar agenda\n");
	printf("5. Sair\n\n");
}

int main() {
	Agenda *agenda = criar_agenda(); // Cria uma nova agenda vazia
	int opcao; // Variável para armazenar a escolha do usuário

	system("clear || cls"); // Limpa a tela (compatível com Unix e Windows)
	do {
		menu(); // Exibe o menu de opções
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
		getchar();  // Consome o '\n' deixado pelo scanf para evitar problemas com fgets
		system("clear || cls"); // Limpa a tela após cada entrada

		switch (opcao) { // Executa a ação com base na opção escolhida
			case 1: { // Inserir contato
				Contato contato;
				printf("Nome: ");
				fgets(contato.nome, 50, stdin); // Lê o nome do contato
				contato.nome[strcspn(contato.nome, "\n")] = '\0';  // Remove o '\n' do final da string

				printf("Endereco: ");
				fgets(contato.endereco, 50, stdin); // Lê o endereço do contato
				contato.endereco[strcspn(contato.endereco, "\n")] = '\0';  // Remove o '\n' do final da string

				printf("Telefone: ");
				fgets(contato.telefone, 50, stdin); // Lê o telefone do contato
				contato.telefone[strcspn(contato.telefone, "\n")] = '\0';  // Remove o '\n' do final da string

				agenda = inserir_agenda(agenda, contato); // Insere o contato na agenda em ordem alfabética
				pausar(); // Pausa até que o usuário pressione Enter
				break;
			}
			case 2: { // Remover contato
				char nome[50];
				printf("Nome do contato a ser removido: ");
				fgets(nome, 50, stdin); // Lê o nome do contato a ser removido
				nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' do final da string

				agenda = remover_agenda(agenda, nome); // Remove o contato da agenda
				pausar(); // Pausa até que o usuário pressione Enter
				break;
			}
			case 3: { // Procurar contato
				char nomeProcurado[50];
				printf("Nome do contato a ser procurado: ");
				fgets(nomeProcurado, 50, stdin); // Lê o nome do contato a ser procurado
				nomeProcurado[strcspn(nomeProcurado, "\n")] = '\0';  // Remove o '\n' do final da string

				Agenda *aux = procurar_agenda(agenda, nomeProcurado); // Procura o contato na agenda
				if (aux != NULL) { // Se o contato for encontrado
					printf("Nome: %s\n", aux->contato.nome);
					printf("Endereco: %s\n", aux->contato.endereco);
					printf("Telefone: %s\n", aux->contato.telefone);
				} else { // Se o contato não for encontrado
					printf("Contato nao encontrado\n");
				}
				pausar(); // Pausa até que o usuário pressione Enter
				break;
			}
			case 4: // Mostrar todos os contatos
				mostrar_agenda(agenda); // Exibe todos os contatos na agenda
				pausar(); // Pausa até que o usuário pressione Enter
				break;
			case 5: // Sair
				printf("Saindo...\n");
				pausar(); // Pausa até que o usuário pressione Enter antes de sair
				break;
			default: // Opção inválida
				printf("Opcao invalida\n");
				pausar(); // Pausa até que o usuário pressione Enter
				break;
		}
	} while (opcao != 5); // Continua exibindo o menu até que o usuário escolha a opção de sair

	return 0; // Retorna 0 para indicar que o programa terminou corretamente
}

