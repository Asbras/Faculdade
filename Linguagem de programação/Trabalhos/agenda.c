/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 08/06/2022
  Nome do programa: Agenda de contatos
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: uma agenda de contatos em C que permite ao usuario inserir, remover, procurar e mostrar contatos. Cada contato tem campos para nome, endereço e telefone. A agenda armazena os contatos em uma lista ligada ordenada alfabeticamente pelo nome. O programa inclui um menu de opções que permite ao usuário:

    1. Inserir um novo contato na lista.
    2. Remover um contato da lista pelo nome.
    3. Procurar um contato pelo nome e exibir seus detalhes.
    4. Mostrar todos os contatos da agenda em ordem alfabética.
 *****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura para armazenar os dados de um contato
typedef struct {
	char nome[50];
	char endereco[50];
	char telefone[50];
} Contato;

// Estrutura para a agenda
typedef struct Agenda {
	Contato contato;
	struct Agenda *prox;
} Agenda;

// Função para pausar a execução até que o usuario pressione Enter
void pausar() {
	printf("\n\nAperte Enter para continuar...");
	while (getchar() != '\n');
	system("clear || cls");  // Limpa a tela (compatível com Unix e Windows)
}

// Função para criar uma nova agenda (inicialmente vazia)
Agenda *criar_agenda() {
	return NULL;
}

// Função para inserir um contato na agenda em ordem alfabética
Agenda *inserir_agenda(Agenda *agenda, Contato contato) {
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
	printf("9. Sair\n\n");
}

int main() {
	Agenda *agenda = criar_agenda(); // Cria uma nova agenda vazia
	int opcao; // Variável para armazenar a escolha do usuario

	system("clear || cls"); // Limpa a tela
	do {
		menu(); // Exibe o menu de opções
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao); // Lê a opção escolhida pelo usuario
		getchar();  // Consome o '\n' deixado pelo scanf para evitar problemas com fgets
		system("clear || cls"); // Limpa a tela após cada entrada

		switch (opcao) { // Executa a ação com base na opção escolhida
			case 1: { // Inserir contato
				printf("* * * * * I N S E R I R * * * * *\n\n");
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
				pausar(); // Pausa até que o usuario pressione Enter
				break;
			}
			case 2: { // Remover contato
				char nome[50];
				printf("* * * * * R E M O V E R * * * * *\n\n");
				printf("Nome do contato a ser removido: ");
				fgets(nome, 50, stdin); // Le o nome do contato a ser removido
				nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' do final da string

				agenda = remover_agenda(agenda, nome); // Remove o contato da agenda
				pausar(); // Pausa até que o usuario pressione Enter
				break;
			}
			case 3: { // Procurar contato
				printf("* * * * * P R O C U R A R * * * * *\n\n");
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
				pausar(); // Pausa até que o usuario pressione Enter
				break;
			}
			case 4: // Mostrar todos os contatos
				printf("* * * * * C O N T A T O S * * * * *\n\n");
				mostrar_agenda(agenda); // Exibe todos os contatos na agenda
				pausar(); // Pausa até que o usuario pressione Enter
				break;
			case 9: // Sair
					printf("Saindo...");
				pausar(); // Pausa até que o usuario pressione Enter antes de sair
				break;
			default: // Opção inválida
				printf("Opcao invalida\n");
				pausar(); // Pausa até que o usuario pressione Enter
				break;
		}
	} while (opcao != 9); // Continua exibindo o menu até que o usuario escolha a opção de sair

	return 0;
}

