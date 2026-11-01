#include <stdio.h>
#define TAM 5

typedef struct Sfila {
    int inicio;
    int fim;
    int quantidade;
    int dados[TAM];
} Tfila;

Tfila queue;

int proximaPosicao(int posicao){
    if(posicao + 1 == TAM){
        return 0;
    }
    return posicao + 1;
}

void enqueue(int dado) {
    if (queue.quantidade == TAM) {
        printf("Fila cheia.\n\n");
        return;
    }

    queue.dados[queue.fim] = dado;
    queue.fim = proximaPosicao(queue.fim);
    queue.quantidade++;
}

void dequeue() {
    if (queue.quantidade == 0) {
        printf("Fila vazia.\n\n");
        return;
    }

    queue.inicio = proximaPosicao(queue.inicio);
    queue.quantidade--;
}

void listar() {
    int posicao = queue.inicio;

    for (int i = 0; i < queue.quantidade; i++) {
        printf("(%d): %d\n", posicao, queue.dados[posicao]);
        posicao = proximaPosicao(posicao);
    }
}

int buscar(int chave) {
    int posicao = queue.inicio;

    for (int i = 0; i < queue.quantidade; i++) {
        if (queue.dados[posicao] == chave) {
            return posicao;
        }
        posicao = proximaPosicao(posicao);
    }
    return -1;
}

int main() {
    int leitura;

    queue.inicio = 0;
    queue.fim = 0;
    queue.quantidade = 0;

    while (1) {
        printf("Informe o valor: ");
        scanf("%d", &leitura);

        if (leitura == 0) {
            break;
        }

        enqueue(leitura);
    }

    printf("\nFila atual:\n");
    listar();

    dequeue();

    printf("\nFila após dequeue:\n");
    listar();

    int key;
    printf("\nInforme o valor que deseja buscar: ");
    scanf("%d", &key);

    int posicao = buscar(key);

    if (posicao == -1) {
        printf("\nValor não encontrado na fila!\n");
    } else {
        printf("\nValor encontrado na posição %d!\n", posicao);
    }

    return 0;
}