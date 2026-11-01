#include <stdio.h>
#include <stdlib.h>

typedef struct Spilha{
    int info;
    struct Spilha *next;
}Tpilha;

Tpilha *stack = NULL;

void push(int dado){
    Tpilha *novo = malloc(sizeof(Tpilha));
    novo->info = dado;
    novo->next = stack;
    stack = novo;
}

void listar(){
    Tpilha *atual = stack;
    
    while(atual != NULL){
        printf("%d\n", atual->info);
        atual = atual->next;
    }
}

void pop(){

    if(stack == NULL){
        return;
    }

    Tpilha *removido = stack;
    stack = stack->next;
    free(removido);
}

Tpilha *buscar(int chave){
    Tpilha *atual;
    for(atual = stack; atual != NULL; atual = atual->next){
        if(atual->info == chave){
            return atual;
        }
    }
    return NULL;
}
int main(){
    int leitura;
    while(1){
        printf("Digite um número: ");
        scanf("%d", &leitura);

        if(leitura == 0){
            break;
        }
        push(leitura);
    }

    printf("\nAntes do pop:\n");
    listar();
    pop();
    printf("\nDepois do pop:\n");
    listar();

    int key;

    printf("Informe o número que deseja busca: ");
    scanf("%d", &key);

    Tpilha *resultado = buscar(key);

    if(resultado == NULL){
        printf("\nValor não encontrado na pilha.\n");
    }else{
        printf("\nValor encontrado na piha.\n");
    }

    return 0;
}