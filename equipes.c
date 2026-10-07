#include <stdio.h>
#include <string.h>
#include "estruturas.h"


// ========================================
// CADASTRAR EQUIPE
// ========================================

void cadastrarEquipe(
    Equipe equipes[],
    int *quantidade
) {

    if (*quantidade >= MAX_EQUIPES) {
        printf("\nLimite de equipes atingido!\n");
        return;
    }

    Equipe nova;

    printf("\n========== CADASTRO DE EQUIPE ==========\n");

    printf("Nome da equipe: ");
    scanf(" %[^\n]", nova.nome);

    // Verifica se já existe
    if (buscarEquipePorNome(
            equipes,
            *quantidade,
            nova.nome
        ) != -1) {

        printf("\nEssa equipe ja esta cadastrada!\n");
        return;
    }

    printf("Quantidade de jogadores: ");
    scanf("%d", &nova.jogadores);

    if (nova.jogadores <= 0) {
        printf("\nQuantidade invalida!\n");
        return;
    }

    // Valores iniciais
    nova.pontuacao = 0;
    nova.vitorias = 0;
    nova.derrotas = 0;

    equipes[*quantidade] = nova;

    (*quantidade)++;

    printf("\nEquipe cadastrada com sucesso!\n");
}


// ========================================
// BUSCAR EQUIPE PELO NOME
// ========================================

int buscarEquipePorNome(
    Equipe equipes[],
    int quantidade,
    char nome[]
) {

    for (int i = 0; i < quantidade; i++) {

        if (strcmp(
                equipes[i].nome,
                nome
            ) == 0) {

            return i;
        }
    }

    return -1;
}


// ========================================
// LISTAR EQUIPES
// ========================================

void listarEquipes(
    Equipe equipes[],
    int quantidade
) {

    if (quantidade == 0) {

        printf("\nNenhuma equipe cadastrada.\n");
        return;
    }

    printf("\n========== EQUIPES ==========\n");

    for (int i = 0; i < quantidade; i++) {

        printf(
            "\nEquipe: %s\n"
            "Jogadores: %d\n"
            "Pontos: %d\n"
            "Vitorias: %d\n"
            "Derrotas: %d\n",
            equipes[i].nome,
            equipes[i].jogadores,
            equipes[i].pontuacao,
            equipes[i].vitorias,
            equipes[i].derrotas
        );
    }
}