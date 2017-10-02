#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int tam;
	int *s;
}stack;

stack new(int i){
	stack p;
	p.tam = 0;
	p.s = (int*) malloc(i * sizeof(stack));
	return p;
}

int is_empty(stack p){
	return !p.tam;
}

void clear(stack *p){
	p->tam = 0;
}

void push(stack *p, int i){
	p->s[p->tam] = i;
	p->tam = p->tam +1;
}

void pop(stack *p){
	if(is_empty(*p)){
		printf("Stack is empty!\n");
		return;
	}
	p->tam = p->tam -1;
}

int top_el(stack p){
	return p.s[p.tam-1];
}

int main(){

}
