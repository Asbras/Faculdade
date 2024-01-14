/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa:                                             |
 | Disciplina:                                                   | 
 | Professor:                                                    |
 | Descrição: O programa permite ao usuário interagir com uma ma-|
 | matriz quadrada de ordem MAX, com as seguintes opções:        |  
 |                                                               |  
 | [OK] a. Carga da matriz                                       |
 | [OK] b. Mostrar matriz                                        |
 | [OK] c. Calcular somatória das temperaturas                   |
 | [OK] d. Calcula média das temperaturas                        |
 | [OK] e. Calcula maior e menor temperatura                     |
 | [OK] f. Calcular maior temperatura da diagonal principal      |
 | [OK] g. Calcular media das temperatura da diagonal principal  |
 | [OK] h. Calcula a difereça das temperaturas da diagonal prin- |
 |      cipal com a diagonal secundária.                         |
 | [OK] i. Calcula a maior temperatura das linhas pares da matriz|
 ****************************************************************/

#include <cstdlib>
#include <iostream>
#define MAX 2  // Define o tamanho da matriz como MAX x MAX



void limpar_tela() {
    system("cls||clear"); 
}


// Carrega valores na matriz
void carga_dados(float dados[MAX][MAX]){
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            std::cout << "Digite um valor: " << std::endl;
            std::cin >> dados[i][j];  // Armazena o valor inserido pelo usuário
        }
    }
}

// Imprime os valores da matriz
void imprimir_dados(float dados[MAX][MAX]){
    std::cout << "* * * IMPRIMINDO TEMPERATURAS * * *\n";
    // Itera sobre cada elemento da matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            std::cout << dados[i][j] << " °C\t";  // Imprime cada valor seguido de "°C"
        }
        std::cout << "\n";  // Quebra de linha após cada linha da matriz
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
    float maior = -99999999999;  // Valor inicial muito baixo
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

float diferenca_ds_dp(float dados[MAX][MAX]){
    float total_dp = 0, total_ds = 0;

    // Acumular todas as temperaturas na diagonal principal e secundária
    for (int i = 0; i < MAX; i++) {
        total_dp += dados[i][i];
        total_ds += dados[i][MAX-i-1];
    }
    return (total_dp - total_ds);
}

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
    float dados[MAX][MAX];

    limpar_tela();
    // Carrega dados na matriz com valores inseridos pelo usuário
    carga_dados(dados);
    limpar_tela();
    
    // Imprime a matriz de dados
    imprimir_dados(dados);

    // Calcula e imprime a soma total das temperaturas
    std::cout << "\n\nSoma total das temperaturas: " << somatorio_dados(dados) << " °C" << std::endl;

    // Calcula e imprime a média das temperaturas
    std::cout << "Média das temperaturas: " << media_dados(dados) << " °C"<< std::endl;

    // Encontra e imprime a maior temperatura registrada
    std::cout << "Maior temperatura registrada: " << maior_valor(dados) << " °C" << std::endl;

    // Encontra e imprime a menor temperatura registrada
    std::cout << "Menor temperatura registrada: " << menor_valor(dados) << " °C"<< std::endl;

    // Encontra e imprime a maior temperatura na diagonal principal da matriz
    std::cout << "Maior temperatura na diagonal principal: " << maior_valor_diagonal_principal(dados) << " °C" << std::endl;

    // Calcula e imprime a média das temperaturas na diagonal principal
    std::cout << "Média das temperaturas na diagonal principal: " << media_diagonal_principal_dados(dados) << " °C" << std::endl;

    // Calcula e imprime a diferença entre as temperaturas da diagonal principal e diagonal secundaria
    std::cout << "A diferença das temperaturas na diagonal principal e diagonal secundária: " << diferenca_ds_dp(dados) << " °C" << std::endl;

    // Calcula e imprime a soma das temperaturas das linhas pares
    std::cout << "A soma das temperaturas nas linhas pares: " << somatorio_linhas_pares(dados) << " °C" << std::endl;

    return 0;
}
