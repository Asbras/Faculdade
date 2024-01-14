/**************************************************************
 * Nome do programa: Programa de Cópia de vetor invertido      *
 * Data: 07 de janeiro de 2024                                 *
 * Autor: Leonardo Carnio Della Torre                          *                 
 * Disciplina: Linguagem de Programação                        *  
 * Professor: Fernando Marco Perez Campos                      *
 * Descrição: Esse programa recebe um vetor de tamano MAX, e   *
 *            copia para outro vetor e inverte os valores do   *
 *            do primeiro vetor.                               *
 ***************************************************************/


#include <iostream>
#define MAX 3

int main () {
    int vetor1[MAX], vetor2[MAX];

    // Receber valores do usuário
    for (int i = 0; i < MAX; i++) {
        std::cout << "Digite um valor: " << std::endl;
        std::cin >> vetor1[i];
    }
    
    // Copiar e inverter os valores do vetor1
    for (int i = 0; i < MAX; i++) {
        vetor2[i] = -vetor1[i]; 
    }

    // Imprimir vetor2 para o usuário
    std::cout << "* * * IMPRIMINDO VETOR COM VALORES INVERTIDOS * * *" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "[" << vetor2[i] << "]\t";
    }

    std::cout << std::endl;

    return 0;
}
