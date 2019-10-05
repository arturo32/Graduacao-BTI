#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char descricao[50];
    double valor;
    int estoque;
}Produto;


typedef struct{
    char nome[70];
    Produto produtos[100];
    int qtdProdutos;
}Loja;


void inserirLoja(Loja *vetorLojas, int *numLojasCadastradas){
    printf("Qual o nome da Loja?\n");
    scanf(" %[^\n]", vetorLojas[*numLojasCadastradas].nome);
    vetorLojas[*numLojasCadastradas].qtdProdutos = 0;
    (*numLojasCadastradas)++;
    
}


void inserirProduto(Loja *vetorLojas, int numLojasCadastradas){
    int i;
    char nomeLoja[50];
    int qtdProdutos;
    printf("\nQual o nome da Loja que deseja inserir o produto?\n");
    scanf(" %[^\n]", nomeLoja);
    for (i = 0; i < numLojasCadastradas; i++){
        if (strcmp(nomeLoja, vetorLojas[i].nome) == 0){
            if (vetorLojas[i].qtdProdutos < 99){
                qtdProdutos = vetorLojas[i].qtdProdutos;
                printf("Qual o Código do Produto?\n");
                scanf("%d", &vetorLojas[i].produtos[qtdProdutos].codigo); 
                printf("Qual a descrição do produto?\n");
                scanf(" %[^\n]", vetorLojas[i].produtos[qtdProdutos].descricao);
                printf("Qual o valor do produto?\n");
                scanf(" %lf", &vetorLojas[i].produtos[qtdProdutos].valor);
                printf("Qual o estoque do produto?\n");
                scanf("%d", &vetorLojas[i].produtos[qtdProdutos].estoque);
                vetorLojas[i].qtdProdutos++;
            }
        }
    }
}



void imprimirLojas(Loja *vetorLojas, int numLojasCadastradas){
    int i, j;
    for ( i = 0; i < numLojasCadastradas; i++){
        printf("\nLoja %s - PRODUTOS:\n", vetorLojas[i].nome);
        for(j=0; j < vetorLojas[i].qtdProdutos; j++){
            printf("-------------------\n");
            printf("Código: %d\n", vetorLojas[i].produtos[j].codigo);
            printf("Descrição: %s\n", vetorLojas[i].produtos[j].descricao);
            printf("Valor: %.2lf\n", vetorLojas[i].produtos[j].valor);
            printf("Estoque: %d\n", vetorLojas[i].produtos[j].estoque);
        }
    }
}

void menu(){
    printf("\nO que deseja?\n");
    printf("[1] Inserir Loja\n");
    printf("[2] Inserir Produto\n");
    printf("[3] Listar todas as Lojas e os seus respectivos produtos\n");
    printf("[4] Listar Lojas com ...\n");
    printf("[0] Sair\n");

}

int main(int argc, char const *argv[]){

    int qtdMaxLojas, escolha, numLojasCadastradas=0;
    Loja *vetorLojas;
    
    printf("Qual o número máximo de lojas que serão cadastradas?\n");
    scanf("%d", &qtdMaxLojas);
    vetorLojas = (Loja *)malloc(qtdMaxLojas *(sizeof(Loja)));
    
    do{
        menu(vetorLojas, numLojasCadastradas);
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                inserirLoja(vetorLojas, &numLojasCadastradas);
                break;
            case 2:
                inserirProduto(vetorLojas, numLojasCadastradas);
                break;
            case 3:
                imprimirLojas(vetorLojas, numLojasCadastradas);
                break;
            case 4:
                //listarLojasMedia();
                break;
            case 0: 
                printf("Saindo...\n");
                break;
            default:
                printf("Opção Inválida! Tente Novamente!\n");
                break;
        }

    }while(escolha != 0);

    return 0;
}





