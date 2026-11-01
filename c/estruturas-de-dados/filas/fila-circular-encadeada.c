#include <stdio.h>
#include <stdlib.h>

typedef struct Sfila{
    int info;
    struct Sfila *next;
}Tfila;
Tfila *fila = NULL;   

void enqueue(int dado){
    Tfila *novo = malloc(sizeof(Tfila));
    novo->info = dado;

    if(fila == NULL){
        novo->next = novo;          
    }else{
        novo->next = fila->next;    
        fila->next = novo;          
    }
    fila = novo;                    
}

void listar(){
    if(fila == NULL) return;

    Tfila *p = fila->next;          
    do{
        printf("%d ", p->info);
        p = p->next;
    }while(p != fila->next);        
}

Tfila *buscar(int key){
    if(fila == NULL) return NULL;

    Tfila *p = fila->next;
    do{
        if(p->info == key){
            return p;
        }
        p = p->next;
    }while(p != fila->next);

    return NULL;
}

void dequeue(){
    if(fila == NULL) return;

    Tfila *primeiro = fila->next;

    if(primeiro == fila){           
        fila = NULL;
    }else{
        fila->next = primeiro->next;   
    }
    free(primeiro);
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

    while(fila != NULL){            
        dequeue();
    }

    return 0;
}