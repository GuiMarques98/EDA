/*
Lista do fernando com vetor inserir no final,
inserir ordenado por matricula, e por nome, excluir qlqr um
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAX
#define MAX 20
#endif
typedef struct
{
	char name[31];
	int id;
}data;


int choice(char * input){
	if(input[0]== 'I'){
		switch(input[1]){
		case 'U':
			return 1;
		case 'M':
			return 2;
		case 'N':
			return 4;
		default:
			return 0;
		}
	}
	else if(input[0]=='E')
		return 3;
	else return 0;

}

void show(data *vetor, int tam){
	int i;
	if(tam==0){
		printf("BASE VAZIA\n");
		return;
	}
	for(i=0;i<tam;i++){
		printf("%s, %d;", vetor[i].name, vetor[i].id);
	}
	printf("\n");
}

int comp(data algo, data algo2){
	if(!strcmp(algo.name, algo2.name)){
		if(algo.id == algo.id){
			return 1;
		}
	}
	return 0;
}

void iu(data algo, data* vetor, int *tam){
	vetor[*tam]=algo;
	*tam = *tam + 1;
	show(vetor, *tam);
}

void im(data algo, data* vetor, int *tam){
	int i=0, flag = 0;

	for (i=*tam-1; ( i >= 0  && vetor[i].id > algo.id); i--)
	 	vetor[i+1] = vetor[i];

	vetor[i+1] = algo;

	*tam = *tam + 1;
	show(vetor, *tam);
}

void ex(data algo, data* vetor, int *tam){
	int i=0, flag=0;
	if(!tam){
		printf("BASE VAZIA!\n");
		return;
	}
	for(int i=0; i<*tam;i++){
		if(comp(algo, vetor[i])){
			flag = 1;
		}
		if(flag){
			if(*tam!=(i+1))
				vetor[i]=vetor[i+1];
		}
	}

	if(flag){
		*tam= *tam -1;
		show(vetor, *tam);
	}
	else
		printf("ENTRADA INVALIDA!\n");
}

void in(data algo, data* vetor, int *tam){
	int i=0, flag = 0;
	data troca;

	for (i=*tam-1; ( i >= 0  && strcmp(vetor[i].name, algo.name) > 0); i--)
	 	vetor[i+1] = vetor[i];

	vetor[i+1] = algo;

	*tam = *tam + 1;

	show(vetor, *tam);
}

int main()
{
	char input[3];
	data vetor[21];
	data algo;
	int tam = 0, flag = 1;

	while(tam != MAX-1 && flag){
		scanf("%s", input);
		scanf("%[^0-9] %d",algo.name, &algo.id);
		switch(choice(input)){
		 case 1:
		 	iu(algo, vetor, &tam);
			break;
		 case 2:
		 	im(algo, vetor, &tam);
			break;
		 case 3:
		 	ex(algo, vetor, &tam);
			break;
		 case 4:
		 	in(algo, vetor, &tam);
			break;
		case 0:
			flag = 0;
		}
	}
	return 0;
}
