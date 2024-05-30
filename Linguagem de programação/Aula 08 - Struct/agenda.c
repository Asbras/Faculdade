
/*******************************************************************************************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 28/05/2024
  Nome do programa: Agenda
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramo
  Descrição: Implemente uma agenda com os dados: nome e telefone em uma fila utilizando struct.

 *****************************************************************************************************************************************/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcpy e strlen
#define MAX 5

typedef struct SAgenda {
    char nome[50];
    char telefone[20];
} TAgenda;

// Função para parar o programa até o usuário pressionar Enter
void pause() {
    printf("\n\nAperte Enter para continuar...");
    while (getchar() != '\n');
    system("clear || cls");
}

void menu(int *opt) {
    printf("* * * * *  M E N U  * * * * *\n");
    printf("\n1 - Cadastrar");
    printf("\n2 - Remover");
    printf("\n3 - Listar");
    printf("\n9 - Sair");
    printf("\nDigite a opção desejada: ");
    scanf("%d", opt);
    getchar(); // Limpar o '\n' deixado pelo scanf
}

void cadastrar(TAgenda *agenda, int *fim) {
    system("clear || cls"); // Limpar a tela no início da função
    printf("* * * * *  I N S E R I R  * * * * *\n\n");
    if (*fim < MAX - 1) {
        (*fim)++;
        printf("\nDigite o nome: ");
        fgets(agenda[*fim].nome, sizeof(agenda[*fim].nome), stdin);
        size_t len = strlen(agenda[*fim].nome);
        if (len > 0 && agenda[*fim].nome[len - 1] == '\n') {
            agenda[*fim].nome[len - 1] = '\0';
        }

        printf("\nDigite o Telefone: ");
        fgets(agenda[*fim].telefone, sizeof(agenda[*fim].telefone), stdin);
        len = strlen(agenda[*fim].telefone);
        if (len > 0 && agenda[*fim].telefone[len - 1] == '\n') {
            agenda[*fim].telefone[len - 1] = '\0';
        }

        printf("\n\nCadastro realizado com sucesso!\n");
    } else {
        printf("\nImpossível inserir\nLista cheia!\n");
    }
}

void remover(TAgenda *agenda, int *fim) {
    system("clear || cls"); // Limpar a tela no início da função
    printf("* * * * *  R E M O V E R  * * * * *\n\n");
    if (*fim >= 0) {
        (*fim)--;
        printf("Remoção realizada com sucesso!\n");
    } else {
        printf("\nImpossível remover\nLista vazia!\n");
    }
}

void listar(TAgenda *agenda, int *fim) {
    system("clear || cls"); // Limpar a tela no início da função
    printf("* * * * *  L I S T A R  * * * * *\n\n");
    if (*fim >= 0) {
        for (int i = *fim; i >= 0; i--) {
            printf("\n%d - Nome: %s", i, agenda[i].nome);
            printf("\n%d - Telefone: %s\n\n", i, agenda[i].telefone);
        }
    } else {
        printf("\nA agenda está vazia.\n");
    }
}

int main() {
    // Habilitar o uso de acentos
    setlocale(LC_ALL, "");

    TAgenda agenda[MAX];
    int fim = -1, opt;

    do {
	system("clear || cls");
	menu(&opt);
        switch (opt) {
            case 1:
                cadastrar(agenda, &fim);
                pause();
                break;
            case 2:
                remover(agenda, &fim);
                pause();
                break;
            case 3:
                listar(agenda, &fim);
                pause();
                break;
        }
    } while (opt != 9);
    return 0;
}
