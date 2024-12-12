#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSondas.h"
#include <time.h>

#define PESO_MAXIMO 40
int minhaVariavelGlobal = 1;



int main(){

    clock_t inicio = clock();
    SondaMarte sonda1;
    listaSonda sondasL;
    ListaRochas compartimentoL;
    
    inicializarListaComp(&compartimentoL);
    iniciaListaSonda(&sondasL);

    for(int i = 0;i < 3;i++){
        insereSonda(&sondasL, inicializaSonda(&sonda1));
    }

    ImprimeListaSondas(&sondasL);
    FILE *arq = NULL;
    arq = fopen("testerocha.txt", "r");
    if(arq == NULL){
        printf("falha leitura");
        exit(0);
    }
    int nRochas; 
    float peso, valor;
    fscanf(arq, "%d", &nRochas);

    for(int i = 0; i<nRochas;i++){
        fscanf(arq,"%f %f", &peso, &valor);
        insere_Rocha(&compartimentoL, valor, peso, 0);
    }
    ImprimeCompartimento(&compartimentoL);

    melhor_rocha(&compartimentoL);

   
    ImprimeCompartimento(&compartimentoL);

    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio) / 1000000;
    printf("Tempo gasto: %f segundos\n", tempo_decorrido);
    printf("\n"); 

    return 0;
}