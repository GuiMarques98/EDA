#include <stdio.h>
#define MAX 30

void push(int *f_push, int *tam, int a){
	if(*tam == MAX){
		printf("Fila cheian\n");
		return;
	}
	f_push[*tam]=a;
	*tam = *tam +1;
}

void pop(int *f_push, int *tam){
	int f_pop[MAX], i, tam_pop = 0;

	if(!(*tam)){
		printf("Fila vazia\n");
		return;
	}
	for(i=*tam-1;i>=0;--i){
		push(f_pop, &tam_pop, f_push[i]);
	}
	tam_pop = tam_pop - 1;
	*tam = 0;

	for(i=tam_pop-1; i>=0;--i){
		push(f_push, tam, f_pop[i]);
	}
}

void print_f(int *f, int tam){
	int i;
	printf("\n");
	for(i=0;i<tam;++i){
		printf("Fila[%d] = %d\n", i, f[i]);
	}
	printf("=============END=============\n\n");
}

int main(){
	int fila_push[MAX], tam = 0, choice = 0;
	while(1){
		printf("\n1-Adicionar na fila\n2-Retirar da fila\n3-Imprimir fila\n0-Sair: ");
		scanf("%d", &choice);
		if(!choice) break;
		switch(choice){
		case 1:
			printf("Digite o item que quer adicionar na fila: ");
			scanf("%d", &choice);
			push(fila_push, &tam, choice);
			break;
		case 2:
			pop(fila_push, &tam);
			break;
		case 3:
			print_f(fila_push, tam);
		}
	}

	return 0;
}
