/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Calculadora de IMC                          |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Escreva um programa em C/C++ que receba o peso e a |
 | altura de N pessoas e calcule:                                |
 |                                                               |
 |  1- Maior peso [ok] 2- Menor peso [ok] 3- Maior altura [ok]   |
 |  4- Menor altura [ok] 5- Maior IMC [ok] 6- Menor IMC [ok]     |
 |  7- Média pesos [ok] 8- Média alturas [ok] 9- Média IMCs [ok] |
 |                                                               |
 | Atenção: o Usuário deverá informar se deseja parar ou conti-  |
 | nuar                                                          |
 ****************************************************************/ 

#include <stdio.h>

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
        printf("Digite o seu peso:\n");
        scanf("%f", &peso);

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
