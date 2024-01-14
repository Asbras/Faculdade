/*****************************************************************
 | Autor: Leonardo Carnio Della Torre                            |
 | Data:                                                         |
 | Nome do programa: Calculadora de médias                       |
 | Disciplina: Linguagem de Programação                          | 
 | Professor: Fernando Marco Perez Ramos                         |
 | Descrição: Escreva um programa que calcule a média de N notas |
 | digitadas pelo usuário. O usuario devera informar o valor de N|
 ****************************************************************/

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    int quantidade_notas;
    float nota, total_das_notas = 0, media = 0;

    // Receber a quantidade de notas que o usuario deseja digitar
    do {
        std::cout << "Digite a quatidade de notas voce deseja calcular:" << std::endl;
        std::cin >> quantidade_notas;
    } while (quantidade_notas <= 0); 

    // Receber todas a notas que o usuario digitar e acumular todas as notas em total_das_notas
    for (int i = 0; i < quantidade_notas; i++) {
        std::cout << "Digite a nota " << i+1 << ":" << std::endl;
        std::cin >> nota;
        
        total_das_notas += nota;
    }

    // Calcular média 
    media = total_das_notas / quantidade_notas;

    // Exibir ao usuário a média calculadda
    std::cout << "Media da notas: " << std::setprecision(3) << media << std::endl;
    return 0;
}

