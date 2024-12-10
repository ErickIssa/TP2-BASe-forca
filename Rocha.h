#ifndef ROCHA_H
#define ROCHA_H


typedef struct{
    float valorRocha;
    float pesoRocha;
    int usada;
} RochaIndv;

void set_valor(RochaIndv* rocha, float valorRocha);
void set_pesoRocha(RochaIndv* rocha, float pesoRocha);
void set_usada(RochaIndv* rocha, int usada);
void iniciaRocha(RochaIndv* rocha, float valorRocha, float pesoRocha, int usada);
void imprimeRocha(RochaIndv rocha);

#endif