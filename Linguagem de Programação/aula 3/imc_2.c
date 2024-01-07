/*
 *Escreva um programa em C/C++ que receba o peso e a altura de N pessoas e calcule:

    Maior peso [ok]
    Menor peso [ok]
    Maior altura [ok]
    Menor altura [ok]
    Maior IMC [ok]
    Menor IMC [ok]
    Média pesos [ok]
    Média alturas [ok]
    Média IMCs [ok]

Atenção: O usuário deverá informar o momento que ele deseja parar de digitar os pesos e alturas durante a execução do laço, ou seja, para cada leitura, pergunte ao usuário se ele deseja digitar os dados de mais uma pessoa.

IMC = Peso/Altura^2
 * */
#include <stdio.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(int argc, char *argv[])
{
    char continuar;
    int total_pessoas = 0;
    float imc, menor_imc = 99999, maior_imc = 0, total_imc = 0, media_imc = 0;
    float peso, menor_peso = 99999, maior_peso = 0, total_peso = 0, media_peso = 0;
    float altura, menor_altura = 99999, maior_altura = 0, total_altura = 0, media_altura = 0;
    
    do {
        // receber altura e peso digitado pelo usuário
        printf("Digite sua altura:\n");
        scanf("%f", &altura);
        limparBuffer(); // Limpa o buffer após a leitura do peso

        printf("Digite o seu peso:\n");
        scanf("%f", &peso);
        limparBuffer(); // Limpa o buffer após a leitura do peso
        
        // Verifica se peso e altura são positivos
        if (peso <= 0 || altura <= 0) {
            printf("Peso e altura devem ser valores positivos.\n");
            continue; // Pula para a próxima iteração do loop
        }

        // calcular IMCs
        imc = peso/(altura * altura);

        // descobrir o maior e menor IMC
        if(maior_imc < imc) maior_imc = imc;
        if(menor_imc > imc) menor_imc = imc;
        // descobrir o maior e menor peso

        if(maior_peso < peso) maior_peso = peso;
        if(menor_peso > peso) menor_peso = peso;
        
        // descobrir maior altura
        if(maior_altura < altura) maior_altura = altura;
        if(menor_altura > altura) menor_altura = altura;
     
        // acumular todos os pesos, alturas e IMCs
        total_imc += imc;
        total_peso += peso;
        total_altura += altura;
        
        // contar quantidade total de pessoas
        total_pessoas++;
        
        // perguntar se o usuário deseja continuar
        printf("Deseja continuar? (S/N)\n");
        scanf(" %c", &continuar);
        limparBuffer();
    } while (continuar != 'N' && continuar != 'n');
    
    // calcular media de altura, peso e IMC
    media_altura = total_altura / total_pessoas;
    media_peso = total_peso / total_pessoas;
    media_imc = total_imc / total_pessoas;
    
    // imprimir na tela os valores calculados
    printf("Maior Peso: %.2f\tMenor Peso: %.2f\n", maior_peso, menor_peso);
    printf("Maior Altura: %.2f\tMenor Altura: %.2f\n", maior_altura, menor_altura);
    printf("Maior IMC: %.2f\tMenor IMC: %.2f\n", maior_imc, menor_imc);
    printf("Média dos Pesos: %.2f\tMédia das Alturas: %.2f\tMédia dos IMCs: %.2f\n", media_peso, media_altura, media_imc);
    
    return 0;
}
