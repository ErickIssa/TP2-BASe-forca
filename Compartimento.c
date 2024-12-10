#include "Compartimento.h"
#include <stdio.h>
#include <stdlib.h>
void inicializarListaComp(ListaRochas* lista) {
    lista->tamanho = 0;
}


void insere_Rocha(ListaRochas* lista, float valor, float peso, int usada) {
    if (lista->tamanho >= MAX) {
        printf("Tamanho Max da lista\n");
        return;
    }
    RochaIndv novaRocha = {valor, peso, usada};
    lista->vetor[lista->tamanho] = novaRocha;
    lista->tamanho++;
    return;
}


void remove_Rocha(ListaRochas* lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Sem rocha\n");
        return;
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->vetor[i] = lista->vetor[i + 1];
    }
    lista->tamanho--;
    return;
}

void ImprimeCompartimento(ListaRochas* lista) {
    if (lista->tamanho == 0) {
        printf("Vazia\n");
        return;
    }
    printf("Lista de Rochas:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Rocha Indice:%d  Valor: %.2f  Peso: %.2f\n", i, lista->vetor[i].valorRocha, lista->vetor[i].pesoRocha);
    }
}