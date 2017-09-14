#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define debug(x) printf("%s = %d\n", #x, x);
#ifndef MAXNOME
#define MAXNOME 30
#endif

#ifndef VECTOR
#define VECTOR 40
#endif

typedef struct {
	int mat;
	char nome[MAXNOME];
}registro;


int main(int argc, char const *argv[])
{
	void inserir(registro *vetor,int *tamanho);
	void printa(registro *vetor,int tamanho);
	int c;
	registro *vetor = malloc(VECTOR* sizeof(registro));
	int tamanho=0;
	vetor[0].mat = -1;

	do
	{
		debug(tamanho);
		printf("0-Sair\n1-Incluir\n2-Imprimir\n");
		scanf("%d", &c);
		switch(c){
			case 1:
				inserir(vetor, &tamanho);
				break;
			case 2:
				printa(vetor, tamanho);
			case 0:
				break;
		}
	} while (c!=0 && tamanho!=39);
	return 0;
}

void inserir(registro *vetor,int *tamanho) {
	registro um, *temp = malloc(VECTOR* sizeof(registro)), *troca=NULL;
	int i, flag = 0;

	system("clear");
	printf("Insira o nome\n");
	scanf(" %[^\n]", um.nome);
	do{
		printf("Insira a mat\n");
		fflush(stdin);
		scanf("%d", &um.mat);
	}while(um.mat < 0);

	if (vetor[0].mat == -1){
		vetor[0]=um;
		um.mat = -1;
		vetor[1] = um;
	} else{
		for (i = 0; i < *tamanho; ++i) {
			if (um.mat < vetor[i].mat && !flag) {
				printf("aaaaaaaaaaaaaaaaaaaaaa\n");
				temp[i] = um;
				flag = 1;
			} else {
				printf("AAAAAAAAAAAAAA\n\n");
				temp[i] = vetor[i-flag];
			}
		}
		troca = vetor;
		vetor = temp;
		temp = troca;
		free(temp);
	}
	getchar();
	*tamanho = 1 + * tamanho;
}

void printa(registro *vetor,int tamanho) {
	int i;
	system("clear");
	if (!tamanho){
		printf("Nao existe pessoas registradas!\n");
	}else{
		printf("NOME            MAT\n===============================================\n");
		for (i = 0; i < tamanho; ++i) {
			printf("%s    %d\n", vetor[i].nome, vetor[i].mat);
		}
	}
	printf("\n\n\n\n");
}
