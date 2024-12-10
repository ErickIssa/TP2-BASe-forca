#include <stdio.h>
#include <stdlib.h>
#include "SondaEspacial.h"

SondaMarte inicializaSonda(SondaMarte* sonda){
    
    setIdentificadorSonda(sonda, minhaVariavelGlobal);
    sonda->capacidadeSonda = 40;
    sonda->valorSonda = 0;
    sonda->pesoAtual = 0;
    minhaVariavelGlobal++;
    return *sonda;
}
void setIdentificadorSonda(SondaMarte* sonda, int identificador){
    sonda->identificadorSonda = identificador;
}
void set_CapacidadeSonda(SondaMarte* sonda, float capacidadeSonda){
    sonda->capacidadeSonda = capacidadeSonda;
}
void set_Valor(SondaMarte* sonda, float vel){
    sonda->valorSonda = vel;
}
void imprimeSonda(SondaMarte sonda) {
    printf("Sonda %d:", sonda.identificadorSonda);
    printf("Capacidade: %.2f ", sonda.capacidadeSonda);
    printf("Peso atual: %.2f ", sonda.pesoAtual);
    printf("Valor: %.2f ", sonda.valorSonda);
    printf("\n");
}
