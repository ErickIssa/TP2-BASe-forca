#ifndef LISTASONDAS_H
#define LISTASONDAS_H

#include "SondaEspacial.h"

typedef SondaMarte Tsonda;
typedef struct Celula* apontador;

typedef struct Celula {
    Tsonda chaveSonda;
    struct Celula* pProxSonda;
}celulaSonda;

typedef struct{
    celulaSonda itemSonda;
    apontador primaSonda, ultSonda;
}listaSonda;

void iniciaListaSonda(listaSonda* pLista);
void insereSonda(listaSonda* plista, SondaMarte xSonda);
void retiraSonda(listaSonda* plista);
void ImprimeListaSondas(listaSonda* plista);



#endif