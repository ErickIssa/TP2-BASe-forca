#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSondas.h"
#include <time.h>
#define PESO_MAXIMO 40
int minhaVariavelGlobal = 1;

void avaliaCombinacao(ListaRochas* lista, int combinacao, float* valorTotal, float* pesoTotal) {
    *valorTotal = 0;
    *pesoTotal = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (combinacao & (1 << i)) { // Verifica se o i-ésimo bit está ativo
            *valorTotal += lista->vetor[i].valorRocha;
            *pesoTotal += lista->vetor[i].pesoRocha;
        }
    }
}

// Função principal para encontrar a melhor combinação de rochas
void encontraMelhoresRochas(ListaRochas* lista) {
    int melhorCombinacao = 0;
    float melhorValor = 0;

    int totalCombinacoes = (1 << lista->tamanho); // 2^tamanho

    for (int combinacao = 0; combinacao < totalCombinacoes; combinacao++) {
        float valorAtual, pesoAtual;
        avaliaCombinacao(lista, combinacao, &valorAtual, &pesoAtual);

        if (pesoAtual <= PESO_MAXIMO && valorAtual > melhorValor) {
            melhorValor = valorAtual;
            melhorCombinacao = combinacao;
        }
    }

    // Imprime os índices da melhor combinação
    printf("Melhor combinação de rochas:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        if (melhorCombinacao & (1 << i)) {
            printf("Rocha %d (Valor: %.2f, Peso: %.2f)\n", i, lista->vetor[i].valorRocha, lista->vetor[i].pesoRocha);
        }
    }
    printf("Valor total: %.2f\n", melhorValor);
}


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

    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio);
    printf("Tempo gasto: %f segundos\n", tempo_decorrido);
    printf("\n"); 

    encontraMelhoresRochas(&compartimentoL);

    return 0;
}