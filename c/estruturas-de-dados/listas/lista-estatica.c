#include <stdio.h>
#define TAM 5

typedef struct Slista{
int dados[TAM];
int ocupado[TAM];
int quantidade;
}Tlista;

Tlista lista = {0};

void menu(){
    printf("\n==== LISTA ====\n");
    printf("1. Adicionar número.\n");
    printf("2. Remover número.\n");
    printf("3. Listar.\n");
    printf("4. Buscar.\n");
    printf("5. Sair.\n");
}

void adicionarNumero(int queue[], int posicao, int dado){
    if(posicao >= 0 && posicao < TAM){
    if(lista.ocupado[posicao] == 0){
    queue[posicao] = dado;
    lista.ocupado[posicao] = 1;
    lista.quantidade++;

    printf("\nValor inserido.\n");
    return;
    }else{
        printf("\nPosição na lista já está preenchida.\n");
        return;
    }
}else{
    printf("\nInsira uma posição válida.\n");
}
}

void listar(int queue[]){
    int i;
    for(i = 0; i < TAM; i++){
        if(lista.ocupado[i] == 1){
        printf("\n[%d]: %d", i, queue[i]);
        }else{
            printf("\n[%d]: vazio", i);
        }
    }
}

void removerNumero(int queue[], int ocupado[], int posicao){
   if(posicao >= 0 && posicao < TAM){
    if(ocupado[posicao] == 1){
        queue[posicao] = 0;
        ocupado[posicao] = 0;
        lista.quantidade--;
        printf("\nNúmero removido.\n");
        return;
    }else{
        printf("\nPosição está vazia.\n");
        return;
    }
}else{
    printf("\nInforme uma posição válida.\n");
}
}


int buscar(int queue[], int ocupado[], int chave){
    int i;
    for(i = 0; i < TAM; i++){
    if(ocupado[i] == 1 && chave == queue[i] ){
        return i;
    }
    }
    return -1;
}

int main(){
int opcao;

do{
    menu();
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
        int posicaoAdicionar, numero;
    
        printf("\nLISTA DE 5 POSIÇÕES.\n");

        printf("Informe a posição: ");
        scanf("%d", &posicaoAdicionar);
        printf("\nInforme o número: \n");
        scanf("%d", &numero);

        adicionarNumero(lista, posicaoAdicionar, numero, TAM);
        break;

        case 2:
        if(quantidade == 0){
        printf("\nAdicione algum número a lista.\n");
        break;
        }
        int posicaoRemover;
        printf("Informe a posição onde deseja remover o número da lista: ");
        scanf("%d", &posicaoRemover);
        removerNumero(lista, ocupado, posicaoRemover);
        break;
        
        case 3:
        if(lista.quantidade == 0){
        printf("\nAdicione algum número a lista.\n");
        break;
        }
        listar(lista, TAM);
        break;

        case 4:
        if(quantidade == 0){
        printf("\nAdicione algum número a lista.\n");
        break;
        }
        listar(lista, TAM);
        
        int key;
        int posicaoBuscar;

        printf("\nInforme o número: \n");
        scanf("%d", &key);

        posicaoBuscar = buscar(lista, ocupado, key);

        if(posicaoBuscar == -1){
            printf("\nValor não encontrado na lista.\n");
        }else{
            printf("\nValor encontrado na posição %d.\n", posicaoBuscar);
        }
        break;

        case 5:
        printf("\nSaindo...\n");
        break;
    
        default:
        printf("\nOpção inválida.\n");
        break;
        }
    }while(opcao != 5);
    return 0;
}