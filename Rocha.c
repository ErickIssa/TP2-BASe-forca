#include "Rocha.h"
#include <stdio.h>
#include <stdlib.h>

void set_valor(RochaIndv* rocha, float valorRocha){
    rocha->valorRocha = valorRocha;
}

void set_pesoRocha(RochaIndv* rocha, float pesoRocha){
    rocha->pesoRocha = pesoRocha;
}

void set_usada(RochaIndv* rocha, int usada) {
    rocha->usada = usada;
}

void iniciaRocha(RochaIndv* rocha, float valorRocha, float pesoRocha, int usada){
    set_pesoRocha(rocha, pesoRocha);
    set_valor(rocha, valorRocha);
    set_usada(rocha, usada);
}

void imprimeRocha(RochaIndv rocha){
    printf("Valor Rocha rocha: %f\n", rocha.valorRocha);
    printf("Peso rocha: %f\n", rocha.pesoRocha);
    if (rocha.usada == 1) {
        printf("Usada\n");
    } else {
        printf("Disponivel\n");
    }
}