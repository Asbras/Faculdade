#include <stdio.h>

void limpar_tela() {
#ifdef _WIN32
    system("cls"); // Limpar a tela no windows
#else
    system("clear"); // Limpar tela no Linux
#endif
}

