#include <stdio.h>
#define TAM 5

typedef struct SPilha{
    int topo;
    int dados[TAM];
}TPilha;

TPilha stack;

void push(int tamanho, int dado){
    if(stack.topo == tamanho - 1){
        printf("Pilha cheia.\n\n");
        return;
    }

    stack.topo++;
    stack.dados[stack.topo] = dado;
}

void listar(){
    for(int i = stack.topo; i >= 0; i--){
        printf("(%d): %d\n", i, stack.dados[i]);
    }
    printf("\n\n");
}

void pop(){
    if(stack.topo == -1){
        printf("Pilha vázia.\n");
        return;
    }
    stack.topo--;
}

int buscar(int chave){
    int i;
    for(i = stack.topo; i >= 0; i--){
        if(chave == stack.dados[i]){
        return i;
        }
    }
    return -1;
}
int main(){
    int leitura;
    stack.topo = -1;
    
    while(1){
        printf("Informe o valor: ");
        scanf("%d", &leitura);

        if(leitura == 0){
            break;
        }
        push(TAM, leitura);
    }

    listar();
    pop();
    pop();
    listar();

    int key;

    printf("Informe o valor que deseja buscar: ");
    scanf("%d", &key);

    int posicao = buscar(key);

    if(posicao == -1){
        printf("\nValor não encontrado!\n");
    }else{
        printf("\nValor encontrado na fila!\n");
    }
    return 0;
}