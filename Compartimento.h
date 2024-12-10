#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "Rocha.h"
#define MAX 100

typedef struct {
    RochaIndv vetor[MAX];
    int tamanho; // Indica o número atual de elementos na lista
} ListaRochas;

void inicializarListaComp(ListaRochas* lista);
void insere_Rocha(ListaRochas* lista, float valor, float peso, int usada);
void remove_Rocha(ListaRochas* lista, int indice);
void ImprimeCompartimento(ListaRochas* lista);

#endif