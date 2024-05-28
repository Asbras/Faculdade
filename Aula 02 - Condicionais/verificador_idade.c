/***************************************************************
  Autor: Leonardo Carnio Della Torre
  Data: 27/05/2024
  Nome do programa: Verificador de Idade
  Disciplina: Linguagem de Programação
  Professor: Fernando Marco Perez Ramos
  Descrição: Leia a idade de uma pessoa e informe se ela é 
  menor de idade (menos de 18 anos), maior de idade (18 anos ou 
  mais), ou idosa (65 anos ou mais). 
 ***************************************************************/

#include <stdlib.h>
#include <stdio.h>

// Função para verificar a faixa etária com base na idade do usuário
void verificar(int idade) {
    if (idade < 18) {
        printf("Você é menor de idade\n");
    } else if (idade >= 18 && idade < 65) {
        printf("Você é maior de idade\n");
    } else {
        printf("Você é idoso(a)\n");
    }
}

int main() {
    int idade;

    // Limpar tela
    system("clear || cls");

    // Solicitar ao usuario que insira a idade
    printf("Digite a sua idade: ");
    
    // Ler a idade digitada pelo usuário
    scanf("%d", &idade);

    // Chamada da função para determinar a faixa etária
    verificar(idade);

    // Limpar o buffer do teclado
    while (getchar()!='\n');

    // Espera o usuário pressionar Enter antes de limpar a tela
    printf("Pressione Enter para continuar...");
    getchar();

    // Limpar a tela
    system("clear || cls");

    return 0;
}
