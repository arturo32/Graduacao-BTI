#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dataCalendario{
    int dia;
    int mes;
    int ano;
}Data;
    
typedef struct pessoa{
    char nome[50];
    int altura;
    Data data;
}Pessoa;


void inserirPessoa(Pessoa *pessoa, int i){
    printf("Primeiro Nome: (Apenas)\n"); //Não Consegui pegar o nome após a pessoa digitar espaço
    scanf("%s", pessoa[i].nome);
    printf("Altura(cm): ");
    scanf("%d", &pessoa[i].altura);
    printf("Data de Nascimento (Ex: 00/00/00):\n");
    scanf("%d/%d/%d", &pessoa[i].data.dia, &pessoa[i].data.mes, &pessoa[i].data.ano); //DANDO ALGUM ERRO 
}

void listarPessoas(Pessoa *pessoa, int qtd){
    int i;
    for(i=0;i<qtd;i++){
        printf("\nPessoa %d\n", i+1);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Idade: %dcm\n", pessoa[i].altura);
        printf("Data de Nascimento: %d/%d/%d\n", pessoa[i].data.dia, pessoa[i].data.mes, pessoa[i].data.ano);
        printf("\n------------------------------\n");
    }
}

int compararData(Pessoa *pessoa, Data limite, int i){
    if(pessoa[i].data.ano < limite.ano){
        return 1;
    }
    else if (pessoa[i].data.ano == limite.ano){
        if (pessoa[i].data.mes < limite.mes){
            return 1;
        }
        else if (pessoa[i].data.mes == limite.mes){
            if(pessoa[i].data.dia < limite.dia){
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}



void pessoasPorData(Pessoa *pessoa, int qtd){
    Data limite;
    printf("Qual a data limite (Ex: 00/00/0000)?\n");
    scanf("%d/%d/%d", &limite.dia, &limite.mes, &limite.ano);
    int i;
    for(i=0;i<qtd;i++){
        if(compararData(pessoa, limite, i) == 1){
            printf("\nPessoa %d\n", i+1);
            printf("Nome: %s\n", pessoa[i].nome);
            printf("Idade: %dcm\n", pessoa[i].altura);
            printf("Data de Nascimento: %d/%d/%d\n", pessoa[i].data.dia, pessoa[i].data.mes, pessoa[i].data.ano);
            printf("\n------------------------------\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    Pessoa *lista;
    lista = (Pessoa *)malloc(10*sizeof(Pessoa));
    int aux = 1;
    int qtdPessoas = 0;
    while(aux != 0){
        printf("\nO que deseja?\n"
        "[1] Inserir uma pessoa\n"
        "[2] Listar todas pessoas\n"
        "[3] Listar pessoas por limite de data\n"
        "[0] Sair\n");
        scanf("%d", &aux);
        switch (aux){
        case 1:
            inserirPessoa(lista, qtdPessoas);
            qtdPessoas++;
            break;
        case 2:
            listarPessoas(lista, qtdPessoas);
            break;
        case 3:
            pessoasPorData(lista, qtdPessoas);
            break;
        case 0:
            break;
        default:
            printf("Opção Inválida! Tente novamente.\n\n");
            break;
        }
    }

free(lista);

    return 0;
}
