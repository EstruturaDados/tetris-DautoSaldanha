#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Cria a struct Peca
typedef struct {
    char tipo;
} Peca;

// Cria a struct Fila
typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Função para iniciar a fila
void iniciarFila(Fila *f) {
    f -> inicio = 0;
    f -> fim = 0;
    f -> total = 0;
}

// Dado da fila vazia
int filaVazia(Fila *f) {
    return f -> total == 0;
}

// Daodo da fila cheia
int filaCheia(Fila *f) {
    return f -> total == MAX;
}

// Função de adicionar
void enfileirar(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia\n");
        return;
    }

    f -> itens[f -> fim] = p;
    f -> fim = (f -> fim + 1) % MAX;
    f -> total++;
    printf("Peça %c adicionada à fila.\n", p.tipo);
}

// Removendo da Fila
Peca desenfileirar(Fila *f) {
    Peca p = {' '};

    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return p;
    }

    p = f -> itens[f -> inicio];
    f -> inicio = (f -> inicio + 1) % MAX;
    f -> total--;
    return p;
}


// Função para mostrar a fila
void mostraFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila de peças: \n");

    int pos = f -> inicio;
    for (int i = 0; i < f -> total; i++) {
        printf("%dª peça -> TIPO: %c\n", i+1, f -> itens[pos].tipo);
        pos = (pos + 1) % MAX;
    }
}

int main() {
    Fila fila;
    iniciarFila(&fila);

    int opcao;
    Peca p;

    do {
        printf("\n=== TETRIS STACK ===\n");
        printf("1 - Adicionar nova peça\n");
        printf("2 - Jogar peça\n");
        printf("3 - Mostrar fila de peças\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tipo da peça (I, O, T, L, etc): ");
                scanf(" %c", &p.tipo);
                enfileirar(&fila, p);
                break;

            case 2:
                p = desenfileirar(&fila);
                if (p.tipo != ' ') {
                    printf("Peça jogada: %c\n", p.tipo);
                }
                break;

            case 3:
                mostraFila(&fila);
                break;

            case 0:
                printf("Encerrando o jogo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

