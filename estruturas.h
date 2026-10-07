#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_EQUIPES 100

// ==========================
// EQUIPE
// ==========================

typedef struct {
    char nome[50];
    int jogadores;
    int pontuacao;
    int vitorias;
    int derrotas;
} Equipe;


// ==========================
// PARTIDA
// ==========================

typedef struct {
    char equipe1[50];
    char equipe2[50];
    char horario[20];

    // 0 = ainda não realizada
    // 1 = equipe1 venceu
    // 2 = equipe2 venceu
    // 3 = empate
    int resultado;
} Partida;


// ==========================
// LISTA DUPLAMENTE ENCADEADA
// HISTÓRICO DE PARTIDAS
// ==========================

typedef struct NoPartida {
    Partida partida;

    struct NoPartida *anterior;
    struct NoPartida *proximo;

} NoPartida;


// ==========================
// FILA
// PARTIDAS AGUARDANDO
// ==========================

typedef struct NoFila {
    Partida partida;

    struct NoFila *proximo;

} NoFila;


typedef struct {
    NoFila *inicio;
    NoFila *fim;

} Fila;


// ==========================
// PILHA
// ALTERAÇÕES
// ==========================

typedef struct NoPilha {
    char descricao[200];

    struct NoPilha *proximo;

} NoPilha;


// ==========================
// ÁRVORE BINÁRIA DE BUSCA
// ==========================

typedef struct NoArvore {
    Equipe equipe;

    struct NoArvore *esquerda;
    struct NoArvore *direita;

} NoArvore;


// ==========================
// FUNÇÕES - EQUIPES
// ==========================

void cadastrarEquipe(
    Equipe equipes[],
    int *quantidade
);

int buscarEquipePorNome(
    Equipe equipes[],
    int quantidade,
    char nome[]
);

void listarEquipes(
    Equipe equipes[],
    int quantidade
);


// ==========================
// FUNÇÕES - FILA
// ==========================

void inicializarFila(Fila *fila);

void enfileirar(
    Fila *fila,
    Partida partida
);

int filaVazia(Fila *fila);

Partida desenfileirar(
    Fila *fila
);

void mostrarFila(
    Fila *fila
);


// ==========================
// FUNÇÕES - LISTA DUPLA
// ==========================

void adicionarHistorico(
    NoPartida **inicio,
    Partida partida
);

void mostrarHistorico(
    NoPartida *inicio
);

NoPartida *buscarPartidaHistorico(
    NoPartida *inicio,
    int numero
);


// ==========================
// FUNÇÕES - PILHA
// ==========================

void empilhar(
    NoPilha **topo,
    char descricao[]
);

void mostrarPilha(
    NoPilha *topo
);


// ==========================
// FUNÇÕES - ÁRVORE
// ==========================

NoArvore *inserirArvore(
    NoArvore *raiz,
    Equipe equipe
);

void mostrarArvore(
    NoArvore *raiz
);

void liberarArvore(
    NoArvore *raiz
);


// ==========================
// FUNÇÕES - RANKING
// ==========================

void ordenarRanking(
    Equipe equipes[],
    int quantidade
);

void mostrarRanking(
    Equipe equipes[],
    int quantidade
);

#endif