#include <stdio.h>

#define TAM 5

int queue[TAM];
int quantidade = 0;

void menu(){
    printf("\n\n===== FILA =====");   
    printf("\n1. Inserir valor."); 
    printf("\n2. Remover valor.");   
    printf("\n3. Listar Fila");   
    printf("\n4. Buscar valor.");   
    printf("\n5. Sair");      
}
void enqueue(int queue[], int dado){
    if(quantidade == TAM){

        printf("\nValor não inserido na fila. Fila está cheia.\n\n");
        return;
    }
    queue[quantidade] = dado;
    quantidade++;

    printf("\nValor inserido!");

}

void listar(int queue[]){
    int i;
    for(i = 0; i < quantidade; i++){
        printf("(%d): %d ", i + 1, queue[i]);
    }
    printf("\n");
}

void dequeue(int queue[]){
    int i;
    if(quantidade == 0){
        printf("Fila vázia!");
        return;
    }
    for(i = 0; i < quantidade - 1; i++){
        queue[i] = queue[i + 1];
    }
    quantidade--;
}


int buscar(int queue[], int chave){
    int i;
    for(i = 0; i < quantidade; i++){
        if(chave == queue[i]){
            return i;
        }
    }
    return -1;
}

int main(){

    int opcao;

    do{

    menu();

    printf("\n\nEscolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:

        int leitura;
        printf("\nInforme o valor: ");
        scanf("%d", &leitura);

        enqueue(queue, leitura);
    
    break;

    case 2:     

    if(quantidade == 0){
        printf("\n\nFila vazia!\n");
        break;
    }

    dequeue(queue);
    break;

    case 3:

    if(quantidade == 0){
        printf("\n\nFila vazia!\n");
        break;
    }

    listar(queue);
    break;

    case 4:

   if(quantidade == 0){
        printf("\n\nFila vazia!\n");
        break;
    }

    int key;
    
    listar(queue);
    printf("\n\nInforme o valor que deseja buscar: ");
    scanf("%d", &key);

    int posicao = buscar(queue, key);

    if(posicao == -1){
        printf("\nValor não encontrado!");
    }else{
        printf("\nValor encontrado na fila.");
    }
    break;

    case 5:

    printf("...");
    break;

    default:

    printf("\nOpção inválida!\n\n");
    break;
    }
    }while(opcao != 5);

    return 0;
}