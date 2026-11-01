#include <stdio.h>

#define TAM 5

int queue[TAM];
    
void enqueue(int queue[], int dado){
    int i;
    for(i = 0; i < TAM; i++){
        if(queue[i] == 0){
            queue[i] = dado;
            return;
        }
    }
    if(i == TAM){
        printf("Valor não inserido na fila. Fila está cheia.\n\n");
    }
}

void listar(int queue[]){
    int i;
    for(i = 0; i < TAM; i++){
        if(queue[i] != 0){
            printf("%d ", queue[i]);
        }
    }
}

void dequeue(int queue[]){
    int i;
    for(i = 0; i < TAM - 1; i++){
        queue[i] = queue[i + 1];
    }
    queue[TAM - 1] = 0;
}

int buscar(int queue[], int chave){
    int i;
    for(i = 0; i < TAM; i++){
        if(chave == queue[i]){
            return i;
        }
    }
    return -1;
}

int main(){
   
    int leitura;
    while(1){
        printf("Informe o valor: ");
        scanf("%d", &leitura);

        if(leitura == 0){
            break;
        }
        enqueue(queue, leitura);
    }
    
    listar(queue);
    dequeue(queue);
    dequeue(queue);
    printf("\nFila atual: ");
    listar(queue);

    int key;
    printf("\n\nInforme o valor que deseja buscar: ");
    scanf("%d", &key);
    int posicao = buscar(queue, key);
    if(posicao == -1){
        printf("\nValor não encontrado!");
    }else{
        printf("Valor encontrado na fila.");
    }

    return 0;
}