#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H
#include "Compartimento.h"
extern int minhaVariavelGlobal;

typedef struct {
    int identificadorSonda;
    float capacidadeSonda;
    float valorSonda;
    float pesoAtual;
} SondaMarte;

SondaMarte inicializaSonda(SondaMarte* sonda); 
void imprimeSonda(SondaMarte sonda);
void setIdentificadorSonda(SondaMarte* sonda, int identificador);
void set_CapacidadeSonda(SondaMarte* sonda, float capacidadeSonda);
void set_Valor(SondaMarte* sonda, float vel);
int gerarNumeroAleatorio();



#endif // SONDAESPACIAL_H