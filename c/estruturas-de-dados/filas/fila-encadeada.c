#include <stdio.h>
#include <stdlib.h>

typedef struct Sfila{
    int info;
    struct Sfila *next;
}Tfila;
Tfila *fila;

void enqueue(int dado){
    Tfila *novo = malloc(sizeof(Tfila));
    novo->info = dado;
    novo->next = NULL;
    Tfila *ultimo;

    if(fila == NULL){
        fila = novo;
        return;
    }
    ultimo = fila;
    while(ultimo->next != NULL){
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
}

void listar(){
  Tfila *ultimo;
  for (ultimo = fila; ultimo != NULL; ultimo = ultimo->next){
    printf("%d ", ultimo->info);
  }
}

Tfila *buscar(int key){
    Tfila *ultimo = fila;
    while(ultimo != NULL){
        if(ultimo->info == key){
            return ultimo;
        }
        ultimo = ultimo->next;
    }
    return NULL;
}

void dequeue(){
    Tfila *ultimo = fila;

    if(ultimo != NULL){
        fila = ultimo->next;
        free(ultimo);
    }
}

int main(){
    int leitura, key;
    while(1){
        printf("Insira um número: ");
        scanf("%d", &leitura);

        if(leitura == 0){
            break;
        }
        enqueue(leitura);
    }

    printf("\nAntes do dequeue.\n");
    listar();

    dequeue();
    dequeue();
    printf("\nDepois do dequeue.\n");
    listar();

    printf("\nInforme o número que deseja buscar: \n");
    scanf("%d", &key);

    Tfila *resultado = buscar(key);

    if(resultado == NULL){
        printf("\nValor não encontrado na fila.\n");
    }else{
        printf("\nValor encontrado no endereço: %p\n", (void*)resultado);
    }
    
    return 0;
}