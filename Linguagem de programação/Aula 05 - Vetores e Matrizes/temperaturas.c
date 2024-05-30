/**************************************************************
 * Nome do programa: Verificador de temperaturas
 * Data: 07 de janeiro de 2024                                 *
 * Autor: Leonardo Carnio Della Torre                          *                 
 * Disciplina: Linguagem de Programação                        *  
 * Professor: Fernando Marco Perez Campos                      *
 * Descrição: Esse programa recebe um vetor de tamanho MAX, e  *
 *            copia para outro vetor e inverte os valores do   *
 *            do primeiro vetor.                               *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 2  // Define o tamanho da matriz como MAX x MAX

// Função para limpar a tela
void limpar_tela() {
    system("cls||clear"); 
}

// Carrega valores na matriz
void carga_dados(float dados[MAX][MAX]){
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("Digite um valor: \n");
            scanf("%f", &dados[i][j]);  // Armazena o valor inserido pelo usuário
        }
    }
}

// Imprime os valores da matriz
void imprimir_dados(float dados[MAX][MAX]){
    printf("* * * IMPRIMINDO TEMPERATURAS * * *\n");
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%.2f °C\t", dados[i][j]);  // Imprime cada valor seguido de "°C"
        }
        printf("\n");  // Quebra de linha após cada linha da matriz
    }
}

// Calcula a soma dos valores da matriz
float somatorio_dados(float dados[MAX][MAX]){
    float total = 0;  // Inicializa total
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            total += dados[i][j];  // Adiciona valor ao total
        }
    }
    return total;  // Retorna o total
}

// Calcula a média dos valores da matriz
float media_dados(float dados[MAX][MAX]){
    float media = 0;  // Inicializa média
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            media += dados[i][j];  // Adiciona valor à média
        }       
    }
    return media / (MAX * MAX);  // Retorna a média dos valores
}

// Encontra o maior valor na matriz
float maior_valor(float dados[MAX][MAX]){
    float maior = -999999999;  // Valor inicial muito baixo para garantir comparação
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (dados[i][j] > maior) maior = dados[i][j];  // Atualiza maior se necessário
        }       
    }
    return maior;  // Retorna o maior valor encontrado
}

// Encontra o menor valor na matriz
float menor_valor(float dados[MAX][MAX]){
    float menor = 999999999;  // Valor inicial muito alto para garantir comparação
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (dados[i][j] < menor) menor = dados[i][j];  // Atualiza menor se necessário
        }       
    }
    return menor;  // Retorna o menor valor encontrado
}

// Encontra o maior valor na diagonal principal da matriz
float maior_valor_diagonal_principal(float dados[MAX][MAX]){
    float maior = -999999999;  // Valor inicial muito baixo
    // Itera apenas sobre a diagonal principal
    for (int i = 0; i < MAX; i++) {
        if (dados[i][i] > maior) maior = dados[i][i];  // Atualiza maior se necessário
    }
    return maior;  // Retorna o maior valor da diagonal principal
}

// Calcula a média dos valores na diagonal principal da matriz
float media_diagonal_principal_dados(float dados[MAX][MAX]){
    float total = 0;  // Inicializa total
    // Itera apenas sobre a diagonal principal
    for (int i = 0; i < MAX; i++) {
        total += dados[i][i];  // Adiciona valor ao total
    }
    return total / MAX;  // Retorna a média da diagonal principal
}

// Calcula a diferença entre as somas das diagonais principal e secundária
float diferenca_ds_dp(float dados[MAX][MAX]){
    float total_dp = 0, total_ds = 0;

    // Acumular todas as temperaturas na diagonal principal e secundária
    for (int i = 0; i < MAX; i++) {
        total_dp += dados[i][i];
        total_ds += dados[i][MAX-i-1];
    }
    return (total_dp - total_ds);
}

// Calcula a soma das temperaturas das linhas pares
float somatorio_linhas_pares(float dados[MAX][MAX]){
    float total = 0;

    for (int i = 0; i < MAX; i+=2) {
        for (int j = 0; j < MAX; j++) {
            total += dados[i][j]; 
        }
    }

    return total;
}

int main () {
    float dados[MAX][MAX];  // Declara matriz de dados

    limpar_tela();
    // Carrega dados na matriz com valores inseridos pelo usuário
    carga_dados(dados);
    limpar_tela();
    
    // Imprime a matriz de dados
    imprimir_dados(dados);

    // Calcula e imprime a soma total das temperaturas
    printf("\n\nSoma total das temperaturas: %.2f °C\n", somatorio_dados(dados));

    // Calcula e imprime a média das temperaturas
    printf("Média das temperaturas: %.2f °C\n", media_dados(dados));

    // Encontra e imprime a maior temperatura registrada
    printf("Maior temperatura registrada: %.2f °C\n", maior_valor(dados));

    // Encontra e imprime a menor temperatura registrada
    printf("Menor temperatura registrada: %.2f °C\n", menor_valor(dados));

    // Encontra e imprime a maior temperatura na diagonal principal da matriz
    printf("Maior temperatura na diagonal principal: %.2f °C\n", maior_valor_diagonal_principal(dados));

    // Calcula e imprime a média das temperaturas na diagonal principal
    printf("Média das temperaturas na diagonal principal: %.2f °C\n", media_diagonal_principal_dados(dados));

    // Calcula e imprime a diferença entre as temperaturas da diagonal principal e diagonal secundaria
    printf("A diferença das temperaturas na diagonal principal e diagonal secundária: %.2f °C\n", diferenca_ds_dp(dados));

    // Calcula e imprime a soma das temperaturas das linhas pares
    printf("A soma das temperaturas nas linhas pares: %.2f °C\n", somatorio_linhas_pares(dados));

    return 0;
}

