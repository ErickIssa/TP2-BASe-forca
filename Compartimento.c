#include "Compartimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("Rocha Indice:%d  Valor: %.2f  Peso: %.2f usada: %d\n", i, lista->vetor[i].valorRocha, lista->vetor[i].pesoRocha, lista->vetor[i].usada);
    }
}

void avaliaCombinacao(ListaRochas* lista, int combinacao, float* valorTotal, float* pesoTotal) {
    *valorTotal = 0;
    *pesoTotal = 0;
    
    for (int i = 0; i < lista->tamanho; i++) {
        if (combinacao % (int)pow(2, i + 1) >= (int)pow(2, i)) { 
            *valorTotal += lista->vetor[i].valorRocha;
            *pesoTotal += lista->vetor[i].pesoRocha;
             lista->vetor[i].usada = 1;
        }
    }
}

// Função principal para encontrar a melhor combinação de rochas
void melhor_rocha(ListaRochas* lista) {
    int melhorCombinacao = 0;
    float melhorValor = 0;

    int totalCombinacoes = (int)pow(2, lista->tamanho); // 2^tamanho

    for (int combinacao = 0; combinacao < totalCombinacoes; combinacao++) {
        float valorAtual, pesoAtual;
        avaliaCombinacao(lista, combinacao, &valorAtual, &pesoAtual);

        if (pesoAtual <= 40 && valorAtual > melhorValor) {
            melhorValor = valorAtual;
            melhorCombinacao = combinacao;
            
        }
    }

    marcaRochasUsadas(lista, melhorCombinacao);

    // Imprime os índices da melhor combinação
    printf("Melhor combinação de rochas:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        if (melhorCombinacao & (1 << i)) {
            printf("Rocha %d (Valor: %.2f, Peso: %.2f)\n", i, lista->vetor[i].valorRocha, lista->vetor[i].pesoRocha);
        }
    }
    printf("Valor total: %.2f\n", melhorValor);
}

void marcaRochasUsadas(ListaRochas* lista, int combinacao) {
    for (int i = 0; i < lista->tamanho; i++) {
        // Ajusta o campo usada para 1 apenas se a rocha faz parte da combinação
        if (combinacao % (int)pow(2, i + 1) >= (int)pow(2, i)) {
            lista->vetor[i].usada = 1;
        } else {
            lista->vetor[i].usada = 0;
        }
    }
}


