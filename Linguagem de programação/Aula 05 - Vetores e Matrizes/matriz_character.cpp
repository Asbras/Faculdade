/*Escreva um programa em C/C++ que carregue duas  matrizes de caracteres de
 * ordem 4X4 e depois retorne as posições de elementos repetidos nas duas
 * matrizes que compartilham a mesma posição
 */

#include <iostream>
#define MAX 4

void carregar(char m[MAX][MAX]){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            std::cout << "Digite um character:\n";
            std::cin >> m[i][j];
        }        
    }
}

void imprimir(char m[MAX][MAX]){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            std::cout << "["<< m[i][j] << "]";
        }
        std::cout << "\n";
    }
}


int main () {
   
    char matriz_1[MAX][MAX] = {
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'}
    };


    imprimir(matriz_1);
    return 0;
}
