#include <stdio.h>
#include <stdlib.h>
#include "ListaSondas.h"

void iniciaListaSonda(listaSonda* pLista){ // com cabeça inicia com celula chave.
    pLista->primaSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->primaSonda;
    pLista->primaSonda->pProxSonda = NULL;
}
void insereSonda(listaSonda* pLista, SondaMarte xSonda){
    pLista->ultSonda->pProxSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->ultSonda->pProxSonda;
    pLista->ultSonda->chaveSonda = xSonda;
    pLista->ultSonda->pProxSonda = NULL;

}
void retiraSonda(listaSonda* plista){
    int idRetira;
    celulaSonda* atual = plista->primaSonda;
    celulaSonda* anterior = NULL;

    printf("Digite o ID da sonda para ser retirada: ");
    scanf("%d", &idRetira);

    while (atual != NULL && atual->chaveSonda.identificadorSonda != idRetira)
    {
        anterior = atual;
        atual = atual->pProxSonda;
    }
     if (atual == NULL) { //Olha se a sonda existe mesmo, se não, retorna uma mensagem
        printf("Sonda não existe com esse ID: %d\n", idRetira);
        return;// encerra codigo
    } 
    if(anterior == NULL){
        plista->primaSonda = atual->pProxSonda; //remove primeira
    } else {
        anterior->pProxSonda = atual->pProxSonda; // remove meio ou fim
    }
    free(atual);
    printf("Sonda Removida :)\n");
}

void ImprimeListaSondas(listaSonda* plista){

    celulaSonda* atual = plista->primaSonda->pProxSonda;

    while(atual != NULL){

        imprimeSonda(atual->chaveSonda);
        atual = atual->pProxSonda;
    }
}
