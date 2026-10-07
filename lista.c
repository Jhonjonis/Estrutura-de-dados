#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"


// ========================================
// ADICIONAR AO HISTORICO
// ========================================

void adicionarHistorico(
    NoPartida **inicio,
    Partida partida
) {

    NoPartida *novo =
        (NoPartida *) malloc(sizeof(NoPartida));

    if (novo == NULL) {

        printf("\nErro de memoria!\n");
        return;
    }

    novo->partida = partida;

    novo->anterior = NULL;
    novo->proximo = NULL;


    // Lista vazia
    if (*inicio == NULL) {

        *inicio = novo;

        return;
    }


    // Vai ate o ultimo elemento
    NoPartida *aux = *inicio;

    while (aux->proximo != NULL) {

        aux = aux->proximo;
    }


    aux->proximo = novo;

    novo->anterior = aux;
}


// ========================================
// MOSTRAR HISTORICO
// ========================================

void mostrarHistorico(
    NoPartida *inicio
) {

    if (inicio == NULL) {

        printf("\nNenhuma partida realizada.\n");

        return;
    }

    NoPartida *aux = inicio;

    int contador = 1;

    printf("\n========== HISTORICO DE PARTIDAS ==========\n");

    while (aux != NULL) {

        printf(
            "\nPartida %d\n",
            contador
        );

        printf(
            "Equipes: %s x %s\n",
            aux->partida.equipe1,
            aux->partida.equipe2
        );

        printf(
            "Horario: %s\n",
            aux->partida.horario
        );


        if (aux->partida.resultado == 1) {

            printf(
                "Resultado: %s venceu\n",
                aux->partida.equipe1
            );

        } else if (aux->partida.resultado == 2) {

            printf(
                "Resultado: %s venceu\n",
                aux->partida.equipe2
            );

        } else if (aux->partida.resultado == 3) {

            printf("Resultado: Empate\n");

        }

        aux = aux->proximo;

        contador++;
    }
}


// ========================================
// BUSCAR PARTIDA PELO NUMERO
// ========================================

NoPartida *buscarPartidaHistorico(
    NoPartida *inicio,
    int numero
) {

    if (numero <= 0) {
        return NULL;
    }

    NoPartida *aux = inicio;

    int contador = 1;

    while (
        aux != NULL &&
        contador < numero
    ) {

        aux = aux->proximo;

        contador++;
    }

    return aux;
}