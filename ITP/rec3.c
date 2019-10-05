#include <stdio.h>

void troca(char alfabeto[], int i, int j){

	int aux = alfabeto[i];
	alfabeto[i] = alfabeto[j];
	alfabeto[j] = aux;
}

void imprimePermutacoes(int numEsquerda, int qtd_letras, char alfabeto[]){  	
    if(numEsquerda == qtd_letras){
		for(int i = 0; i < qtd_letras; i++){
			printf("%c ", alfabeto[i]);
        }
		printf("\n");
	}
	else{

		for(int i = numEsquerda; i < qtd_letras; i++){
			troca(alfabeto, numEsquerda, i);
			imprimePermutacoes(numEsquerda + 1, qtd_letras, alfabeto);
			troca(alfabeto, numEsquerda, i);
		}
	}
}

int main(int argc, char const *argv[])
{
    int qtd_letras;
    char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    printf("Quantas letras serão permutadas?\n");
    scanf("%d", &qtd_letras);
    imprimePermutacoes(0, qtd_letras ,alfabeto);
    return 0;
}
