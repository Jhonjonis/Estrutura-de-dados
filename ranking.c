#include <stdio.h>
#include <string.h>
#include "estruturas.h"
// ========================================
// ORDENAR RANKING
// ========================================

void ordenarRanking(
    Equipe equipes[],
    int quantidade
) {

    for (
        int i = 0;
        i < quantidade - 1;
        i++
    ) {

        for (
            int j = 0;
            j < quantidade - i - 1;
            j++
        ) {

            int trocar = 0;


            // Primeiro criterio:
            // maior pontuacao

            if (
                equipes[j].pontuacao <
                equipes[j + 1].pontuacao
            ) {

                trocar = 1;
            }


            // Segundo criterio:
            // maior numero de vitorias

            else if (
                equipes[j].pontuacao ==
                equipes[j + 1].pontuacao
            ) {

                if (
                    equipes[j].vitorias <
                    equipes[j + 1].vitorias
                ) {

                    trocar = 1;
                }


                // Terceiro criterio:
                // nome em ordem alfabetica

                else if (
                    equipes[j].vitorias ==
                    equipes[j + 1].vitorias
                ) {

                    if (
                        strcmp(
                            equipes[j].nome,
                            equipes[j + 1].nome
                        ) > 0
                    ) {

                        trocar = 1;
                    }
                }
            }


            if (trocar) {

                Equipe temp =
                    equipes[j];

                equipes[j] =
                    equipes[j + 1];

                equipes[j + 1] =
                    temp;
            }
        }
    }
}


// ========================================
// MOSTRAR RANKING
// ========================================

void mostrarRanking(
    Equipe equipes[],
    int quantidade
) {

    if (quantidade == 0) {

        printf("\nNenhuma equipe cadastrada.\n");

        return;
    }

    // Faz uma copia para nao alterar
    // a ordem original das equipes

    Equipe copia[MAX_EQUIPES];

    for (
        int i = 0;
        i < quantidade;
        i++
    ) {

        copia[i] = equipes[i];
    }


    ordenarRanking(
        copia,
        quantidade
    );


    printf("\n========== RANKING ==========\n");

    for (
        int i = 0;
        i < quantidade;
        i++
    ) {

        printf(
            "%d - %s | %d pontos | %d V | %d D\n",
            i + 1,
            copia[i].nome,
            copia[i].pontuacao,
            copia[i].vitorias,
            copia[i].derrotas
        );
    }
}