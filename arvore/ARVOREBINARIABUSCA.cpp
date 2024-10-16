
#include <iostream>
#include <queue>  // Biblioteca necessária para a nova função
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"

using namespace std;

TipoCelula *Raiz;
int Contador;

void ArvoreBinariaBusca_Construtor() {
    Raiz = NULL;
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor() {
    ArvoreBinariaBusca_Destrutor(Raiz);
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_Destrutor(Raiz->Esq);
        ArvoreBinariaBusca_Destrutor(Raiz->Dir);
        delete Raiz;
        Raiz = NULL;
    }
}

bool ArvoreBinariaBusca_Vazia() {
    return Raiz == NULL;
}

int ArvoreBinariaBusca_Tamanho() {
    return Contador;
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento) {
    return ArvoreBinariaBusca_Inserir(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz) {
    if (Raiz == NULL) {
        if ((Raiz = new TipoCelula) == NULL)
            return false;
        Raiz->Item = Elemento;
        Raiz->Esq = Raiz->Dir = NULL;
        Contador++;
        return true;
    } else if (Elemento < Raiz->Item) {
        return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Esq);
    } else if (Elemento > Raiz->Item) {
        return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Dir);
    }
    return false;
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento) {
    return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz) {
    if (Raiz == NULL) return false;
    if (Elemento < Raiz->Item) {
        return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Esq);
    } else if (Elemento > Raiz->Item) {
        return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Dir);
    }
    return true;
}

void ArvoreBinariaBusca_Percurso(int modo) {
    switch (modo) {
        case 1: ArvoreBinariaBusca_PreOrdem(Raiz); break;
        case 2: ArvoreBinariaBusca_EmOrdem(Raiz); break;
        case 3: ArvoreBinariaBusca_PosOrdem(Raiz); break;
        default: cout << "Ordem desconhecida"; break;
    }
    cout << endl << endl;
    system("pause");
}

void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_EmOrdem(Raiz->Esq);
        cout << Raiz->Item << " ";
        ArvoreBinariaBusca_EmOrdem(Raiz->Dir);
    }
}

void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        cout << Raiz->Item << " ";
        ArvoreBinariaBusca_PreOrdem(Raiz->Esq);
        ArvoreBinariaBusca_PreOrdem(Raiz->Dir);
    }
}

void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_PosOrdem(Raiz->Esq);
        ArvoreBinariaBusca_PosOrdem(Raiz->Dir);
        cout << Raiz->Item << " ";
    }
}

// Nova função: Imprimir todos os nodos de um dado nível
void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {
    if (Raiz == NULL) {
        cout << "Arvore vazia." << endl;
        return;
    }

    queue<TipoCelula*> fila;
    queue<int> niveis;

    fila.push(Raiz);
    niveis.push(0);

    bool encontrou = false;

    while (!fila.empty()) {
        TipoCelula* atual = fila.front();
        int nivelAtual = niveis.front();
        fila.pop();
        niveis.pop();

        if (nivelAtual == nivel) {
            cout << atual->Item << " ";
            encontrou = true;
        }

        if (atual->Esq != NULL) {
            fila.push(atual->Esq);
            niveis.push(nivelAtual + 1);
        }

        if (atual->Dir != NULL) {
            fila.push(atual->Dir);
            niveis.push(nivelAtual + 1);
        }
    }

    if (!encontrou) {
        cout << "Nivel " << nivel << " nao encontrado." << endl;
    }

    cout << endl;
}
