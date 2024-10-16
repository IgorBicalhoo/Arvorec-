
#include <iostream>
#include "ArvoreBinariaBusca.h"

using namespace std;

//igor bicalho nogueira de paula


int main() {
    ArvoreBinariaBusca_Construtor();

    // Inserindo elementos na árvore
    ArvoreBinariaBusca_Inserir(10);
    ArvoreBinariaBusca_Inserir(5);
    ArvoreBinariaBusca_Inserir(15);
    ArvoreBinariaBusca_Inserir(3);
    ArvoreBinariaBusca_Inserir(7);
    ArvoreBinariaBusca_Inserir(20);

    // Imprimir nodos de um nível específico
    cout << "Nodos no nivel 2: ";
    ArvoreBinariaBusca_Imprimir_Por_Nivel(2);

    ArvoreBinariaBusca_Destrutor();
    return 0;
}
