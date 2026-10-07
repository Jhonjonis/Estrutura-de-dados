#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"


// ========================================
// PROTOTIPOS AUXILIARES
// ========================================

void criarPartida(
    Fila *fila,
    Equipe equipes[],
    int quantidade
);

void realizarPartida(
    Fila *fila,
    NoPartida **historico,
    NoPilha **pilha,
    Equipe equipes[],
    int quantidade,
    NoArvore **arvore
);

void atualizarArvore(
    NoArvore **arvore,
    Equipe equipes[],
    int quantidade
);

void alterarResultado(
    NoPartida *historico,
    Equipe equipes[],
    int quantidade,
    NoPilha **pilha,
    NoArvore **arvore
);

void cancelarProximaPartida(
    Fila *fila,
    NoPilha **pilha
);

void mostrarMenu();


// ========================================
// MAIN
// ========================================

int main() {

    // ====================================
    // VETOR DE EQUIPES
    // ====================================

    Equipe equipes[MAX_EQUIPES];

    int quantidadeEquipes = 0;


    // ====================================
    // FILA
    // ====================================

    Fila fila;

    inicializarFila(&fila);


    // ====================================
    // LISTA DUPLAMENTE ENCADEADA
    // ====================================

    NoPartida *historico = NULL;


    // ====================================
    // PILHA
    // ====================================

    NoPilha *pilha = NULL;


    // ====================================
    // ABB
    // ====================================

    NoArvore *arvore = NULL;


    int opcao;


    // ====================================
    // MENU PRINCIPAL
    // ====================================

    do {

        mostrarMenu();

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);


        switch (opcao) {


            // ============================
            // CADASTRAR EQUIPE
            // ============================

            case 1:

                cadastrarEquipe(
                    equipes,
                    &quantidadeEquipes
                );

                atualizarArvore(
                    &arvore,
                    equipes,
                    quantidadeEquipes
                );

                break;


            // ============================
            // LISTAR EQUIPES
            // ============================

            case 2:

                listarEquipes(
                    equipes,
                    quantidadeEquipes
                );

                break;


            // ============================
            // CRIAR PARTIDA
            // ============================

            case 3:

                criarPartida(
                    &fila,
                    equipes,
                    quantidadeEquipes
                );

                break;


            // ============================
            // MOSTRAR FILA
            // ============================

            case 4:

                mostrarFila(&fila);

                break;


            // ============================
            // REALIZAR PARTIDA
            // ============================

            case 5:

                realizarPartida(
                    &fila,
                    &historico,
                    &pilha,
                    equipes,
                    quantidadeEquipes,
                    &arvore
                );

                break;


            // ============================
            // HISTORICO
            // ============================

            case 6:

                mostrarHistorico(
                    historico
                );

                break;


            // ============================
            // RANKING
            // ============================

            case 7:

                mostrarRanking(
                    equipes,
                    quantidadeEquipes
                );

                break;


            // ============================
            // ABB
            // ============================

            case 8:

                if (arvore == NULL) {

                    printf(
                        "\nA ABB esta vazia.\n"
                    );

                } else {

                    printf(
                        "\n========== ABB ==========\n"
                    );

                    mostrarArvore(arvore);
                }

                break;


            // ============================
            // ALTERAR RESULTADO
            // ============================

            case 9:

                alterarResultado(
                    historico,
                    equipes,
                    quantidadeEquipes,
                    &pilha,
                    &arvore
                );

                break;


            // ============================
            // CANCELAR PARTIDA
            // ============================

            case 10:

                cancelarProximaPartida(
                    &fila,
                    &pilha
                );

                break;


            // ============================
            // PILHA
            // ============================

            case 11:

                mostrarPilha(pilha);

                break;


            // ============================
            // SAIR
            // ============================

            case 0:

                printf(
                    "\nEncerrando o campeonato...\n"
                );

                break;


            default:

                printf(
                    "\nOpcao invalida!\n"
                );
        }

    } while (opcao != 0);


    // ====================================
    // LIBERAR MEMORIA
    // ====================================

    liberarArvore(arvore);


    return 0;
}


// ========================================
// MENU
// ========================================

void mostrarMenu() {

    printf("\n\n");
    printf("========================================\n");
    printf("       CAMPEONATO DE E-SPORTS\n");
    printf("========================================\n");

    printf("\n1  - Cadastrar equipe");
    printf("\n2  - Listar equipes");

    printf("\n3  - Criar partida");
    printf("\n4  - Mostrar fila");

    printf("\n5  - Realizar proxima partida");
    printf("\n6  - Mostrar historico");

    printf("\n7  - Mostrar ranking");
    printf("\n8  - Mostrar ABB");

    printf("\n9  - Alterar resultado");
    printf("\n10 - Cancelar proxima partida");

    printf("\n11 - Mostrar alteracoes");

    printf("\n0  - Sair");

    printf("\n========================================\n");
}


// ========================================
// CRIAR PARTIDA
// ========================================

void criarPartida(
    Fila *fila,
    Equipe equipes[],
    int quantidade
) {

    if (quantidade < 2) {

        printf(
            "\nCadastre pelo menos 2 equipes!\n"
        );

        return;
    }


    Partida partida;


    printf(
        "\n========== CRIAR PARTIDA ==========\n"
    );


    printf("Nome da equipe 1: ");
    scanf(
        " %[^\n]",
        partida.equipe1
    );


    int pos1 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida.equipe1
        );


    if (pos1 == -1) {

        printf(
            "\nEquipe 1 nao encontrada!\n"
        );

        return;
    }


    printf("Nome da equipe 2: ");
    scanf(
        " %[^\n]",
        partida.equipe2
    );


    int pos2 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida.equipe2
        );


    if (pos2 == -1) {

        printf(
            "\nEquipe 2 nao encontrada!\n"
        );

        return;
    }


    if (pos1 == pos2) {

        printf(
            "\nUma equipe nao pode jogar contra ela mesma!\n"
        );

        return;
    }


    printf("Horario da partida: ");

    scanf(
        " %[^\n]",
        partida.horario
    );


    partida.resultado = 0;


    enfileirar(
        fila,
        partida
    );
}


// ========================================
// REALIZAR PARTIDA
// ========================================

void realizarPartida(
    Fila *fila,
    NoPartida **historico,
    NoPilha **pilha,
    Equipe equipes[],
    int quantidade,
    NoArvore **arvore
) {

    if (filaVazia(fila)) {

        printf(
            "\nNao existem partidas na fila!\n"
        );

        return;
    }


    Partida partida =
        desenfileirar(fila);


    printf(
        "\n========== REALIZAR PARTIDA ==========\n"
    );


    printf(
        "\n%s x %s\n",
        partida.equipe1,
        partida.equipe2
    );

    printf(
        "Horario: %s\n",
        partida.horario
    );


    printf("\nResultado:\n");

    printf(
        "1 - %s venceu\n",
        partida.equipe1
    );

    printf(
        "2 - %s venceu\n",
        partida.equipe2
    );

    printf("3 - Empate\n");


    int resultado;

    printf("\nEscolha: ");
    scanf("%d", &resultado);


    if (
        resultado < 1 ||
        resultado > 3
    ) {

        printf(
            "\nResultado invalido!\n"
        );

        // Devolve a partida para a fila
        enfileirar(
            fila,
            partida
        );

        return;
    }


    partida.resultado = resultado;


    int pos1 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida.equipe1
        );


    int pos2 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida.equipe2
        );


    if (
        pos1 == -1 ||
        pos2 == -1
    ) {

        printf(
            "\nErro: equipe nao encontrada!\n"
        );

        return;
    }


    // ====================================
    // ATUALIZAR RESULTADO
    // ====================================

    if (resultado == 1) {

        // Equipe 1 venceu

        equipes[pos1].vitorias++;
        equipes[pos1].pontuacao += 3;

        equipes[pos2].derrotas++;

    }

    else if (resultado == 2) {

        // Equipe 2 venceu

        equipes[pos2].vitorias++;
        equipes[pos2].pontuacao += 3;

        equipes[pos1].derrotas++;

    }

    else if (resultado == 3) {

        // Empate

        equipes[pos1].pontuacao += 1;
        equipes[pos2].pontuacao += 1;
    }


    // ====================================
    // COLOCAR NO HISTORICO
    // ====================================

    adicionarHistorico(
        historico,
        partida
    );


    // ====================================
    // REGISTRAR NA PILHA
    // ====================================

    char descricao[200];

    if (resultado == 1) {

        sprintf(
            descricao,
            "Partida %s x %s realizada - %s venceu.",
            partida.equipe1,
            partida.equipe2,
            partida.equipe1
        );

    }

    else if (resultado == 2) {

        sprintf(
            descricao,
            "Partida %s x %s realizada - %s venceu.",
            partida.equipe1,
            partida.equipe2,
            partida.equipe2
        );

    }

    else {

        sprintf(
            descricao,
            "Partida %s x %s realizada - empate.",
            partida.equipe1,
            partida.equipe2
        );
    }


    empilhar(
        pilha,
        descricao
    );


    // ====================================
    // ATUALIZAR ABB
    // ====================================

    atualizarArvore(
        arvore,
        equipes,
        quantidade
    );


    printf(
        "\nPartida realizada com sucesso!\n"
    );
}


// ========================================
// ATUALIZAR ABB
// ========================================

void atualizarArvore(
    NoArvore **arvore,
    Equipe equipes[],
    int quantidade
) {

    // Apaga a árvore antiga
    liberarArvore(*arvore);

    *arvore = NULL;


    // Recria com os dados atuais
    for (
        int i = 0;
        i < quantidade;
        i++
    ) {

        *arvore =
            inserirArvore(
                *arvore,
                equipes[i]
            );
    }
}


// ========================================
// ALTERAR RESULTADO
// ========================================

void alterarResultado(
    NoPartida *historico,
    Equipe equipes[],
    int quantidade,
    NoPilha **pilha,
    NoArvore **arvore
) {

    if (historico == NULL) {

        printf(
            "\nNao existem partidas no historico.\n"
        );

        return;
    }


    mostrarHistorico(historico);


    int numero;

    printf(
        "\nDigite o numero da partida que deseja alterar: "
    );

    scanf("%d", &numero);


    NoPartida *no =
        buscarPartidaHistorico(
            historico,
            numero
        );


    if (no == NULL) {

        printf(
            "\nPartida nao encontrada!\n"
        );

        return;
    }


    Partida *partida =
        &no->partida;


    int pos1 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida->equipe1
        );


    int pos2 =
        buscarEquipePorNome(
            equipes,
            quantidade,
            partida->equipe2
        );


    if (
        pos1 == -1 ||
        pos2 == -1
    ) {

        printf(
            "\nErro ao localizar equipes.\n"
        );

        return;
    }


    // ====================================
    // DESFAZER RESULTADO ANTIGO
    // ====================================

    if (partida->resultado == 1) {

        equipes[pos1].vitorias--;
        equipes[pos1].pontuacao -= 3;

        equipes[pos2].derrotas--;
    }

    else if (partida->resultado == 2) {

        equipes[pos2].vitorias--;
        equipes[pos2].pontuacao -= 3;

        equipes[pos1].derrotas--;
    }

    else if (partida->resultado == 3) {

        equipes[pos1].pontuacao--;
        equipes[pos2].pontuacao--;
    }


    // ====================================
    // NOVO RESULTADO
    // ====================================

    printf(
        "\nNovo resultado:\n"
    );

    printf(
        "1 - %s venceu\n",
        partida->equipe1
    );

    printf(
        "2 - %s venceu\n",
        partida->equipe2
    );

    printf("3 - Empate\n");


    int novoResultado;

    printf("\nEscolha: ");

    scanf(
        "%d",
        &novoResultado
    );


    if (
        novoResultado < 1 ||
        novoResultado > 3
    ) {

        printf(
            "\nResultado invalido.\n"
        );

        return;
    }


    partida->resultado =
        novoResultado;


    // ====================================
    // APLICAR NOVO RESULTADO
    // ====================================

    if (novoResultado == 1) {

        equipes[pos1].vitorias++;
        equipes[pos1].pontuacao += 3;

        equipes[pos2].derrotas++;
    }

    else if (novoResultado == 2) {

        equipes[pos2].vitorias++;
        equipes[pos2].pontuacao += 3;

        equipes[pos1].derrotas++;
    }

    else {

        equipes[pos1].pontuacao++;
        equipes[pos2].pontuacao++;
    }


    // ====================================
    // REGISTRAR ALTERACAO
    // ====================================

    char descricao[200];

    sprintf(
        descricao,
        "Resultado da partida %s x %s foi alterado.",
        partida->equipe1,
        partida->equipe2
    );


    empilhar(
        pilha,
        descricao
    );


    // ====================================
    // RECRIAR ABB
    // ====================================

    atualizarArvore(
        arvore,
        equipes,
        quantidade
    );


    printf(
        "\nResultado alterado com sucesso!\n"
    );
}


// ========================================
// CANCELAR PROXIMA PARTIDA
// ========================================

void cancelarProximaPartida(
    Fila *fila,
    NoPilha **pilha
) {

    if (filaVazia(fila)) {

        printf(
            "\nNao existem partidas na fila.\n"
        );

        return;
    }


    Partida partida =
        desenfileirar(fila);


    char descricao[200];


    sprintf(
        descricao,
        "Partida %s x %s foi cancelada.",
        partida.equipe1,
        partida.equipe2
    );


    empilhar(
        pilha,
        descricao
    );


    printf(
        "\nPartida cancelada:\n"
    );

    printf(
        "%s x %s\n",
        partida.equipe1,
        partida.equipe2
    );
}