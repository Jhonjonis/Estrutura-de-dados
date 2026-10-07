#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"


// ========================================
// INSERIR NA ABB
// ========================================

NoArvore *inserirArvore(
    NoArvore *raiz,
    Equipe equipe
) {

    // Árvore vazia
    if (raiz == NULL) {

        NoArvore *novo =
            (NoArvore *) malloc(
                sizeof(NoArvore)
            );

        if (novo == NULL) {

            printf("\nErro de memoria!\n");

            return NULL;
        }

        novo->equipe = equipe;

        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }


    // Primeiro criterio: pontuacao
    if (
        equipe.pontuacao <
        raiz->equipe.pontuacao
    ) {

        raiz->esquerda =
            inserirArvore(
                raiz->esquerda,
                equipe
            );

    } else if (
        equipe.pontuacao >
        raiz->equipe.pontuacao
    ) {

        raiz->direita =
            inserirArvore(
                raiz->direita,
                equipe
            );

    } else {

        // Empate de pontos:
        // usa o nome como segundo criterio

        if (
            strcmp(
                equipe.nome,
                raiz->equipe.nome
            ) < 0
        ) {

            raiz->esquerda =
                inserirArvore(
                    raiz->esquerda,
                    equipe
                );

        } else {

            raiz->direita =
                inserirArvore(
                    raiz->direita,
                    equipe
                );
        }
    }

    return raiz;
}


// ========================================
// MOSTRAR ABB
// ========================================

void mostrarArvore(
    NoArvore *raiz
) {

    if (raiz == NULL) {
        return;
    }

    // Percurso em ordem
    mostrarArvore(raiz->esquerda);

    printf(
        "%s - %d pontos - %d vitorias\n",
        raiz->equipe.nome,
        raiz->equipe.pontuacao,
        raiz->equipe.vitorias
    );

    mostrarArvore(raiz->direita);
}


// ========================================
// LIBERAR MEMORIA DA ABB
// ========================================

void liberarArvore(
    NoArvore *raiz
) {

    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);

    liberarArvore(raiz->direita);

    free(raiz);
}