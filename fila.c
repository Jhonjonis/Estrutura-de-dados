#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"


// ========================================
// INICIALIZAR FILA
// ========================================

void inicializarFila(Fila *fila) {

    fila->inicio = NULL;
    fila->fim = NULL;
}


// ========================================
// VERIFICAR SE FILA ESTA VAZIA
// ========================================

int filaVazia(Fila *fila) {

    if (fila->inicio == NULL) {
        return 1;
    }

    return 0;
}


// ========================================
// ENFILEIRAR PARTIDA
// ========================================

void enfileirar(
    Fila *fila,
    Partida partida
) {

    NoFila *novo =
        (NoFila *) malloc(sizeof(NoFila));

    if (novo == NULL) {

        printf("\nErro de memoria!\n");
        return;
    }

    novo->partida = partida;
    novo->proximo = NULL;

    // Se a fila estiver vazia
    if (fila->inicio == NULL) {

        fila->inicio = novo;
        fila->fim = novo;

    } else {

        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    printf("\nPartida adicionada a fila!\n");
}


// ========================================
// DESENFILEIRAR
// ========================================

Partida desenfileirar(
    Fila *fila
) {

    Partida vazia;

    vazia.equipe1[0] = '\0';
    vazia.equipe2[0] = '\0';
    vazia.horario[0] = '\0';
    vazia.resultado = 0;

    if (fila->inicio == NULL) {

        return vazia;
    }

    NoFila *temp = fila->inicio;

    Partida partida = temp->partida;

    fila->inicio = temp->proximo;

    if (fila->inicio == NULL) {

        fila->fim = NULL;
    }

    free(temp);

    return partida;
}


// ========================================
// MOSTRAR FILA
// ========================================

void mostrarFila(
    Fila *fila
) {

    if (fila->inicio == NULL) {

        printf("\nA fila de partidas esta vazia.\n");
        return;
    }

    NoFila *aux = fila->inicio;

    int contador = 1;

    printf("\n========== FILA DE PARTIDAS ==========\n");

    while (aux != NULL) {

        printf(
            "\n%d - %s x %s\n"
            "Horario: %s\n",
            contador,
            aux->partida.equipe1,
            aux->partida.equipe2,
            aux->partida.horario
        );

        aux = aux->proximo;

        contador++;
    }
}