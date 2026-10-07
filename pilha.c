#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"


// ========================================
// EMPILHAR
// ========================================

void empilhar(
    NoPilha **topo,
    char descricao[]
) {

    NoPilha *novo =
        (NoPilha *) malloc(sizeof(NoPilha));

    if (novo == NULL) {

        printf("\nErro de memoria!\n");
        return;
    }

    strcpy(
        novo->descricao,
        descricao
    );

    novo->proximo = *topo;

    *topo = novo;
}


// ========================================
// MOSTRAR PILHA
// ========================================

void mostrarPilha(
    NoPilha *topo
) {

    if (topo == NULL) {

        printf("\nNenhuma alteracao registrada.\n");

        return;
    }

    printf("\n========== PILHA DE ALTERACOES ==========\n");

    int contador = 1;

    while (topo != NULL) {

        printf(
            "%d - %s\n",
            contador,
            topo->descricao
        );

        topo = topo->proximo;

        contador++;
    }
}