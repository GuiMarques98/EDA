#include <stdio.h>
#define MAX 40

typedef struct {
	int q[MAX];
	int init;
	int fin;
}Fila;

Fila new() {
	Fila q;
	q.init = 0;
	q.fin = 0;
}

void clean(Fila *f) {
	f->init = f->fin = 0;
}

void enqueue(Fila *f, int p) {
	if(f->fin == MAX-1) {
		if(!f->init) {
			printf("Queue is full!\n");
			return;
		}
		f->q[0] = p;
	 	f->fin = 0;
		return;
	}
	if(f->fin+1 == f->init) {
		printf("Queue is full!\n");
		return;
	}
	f->q[f->fin]=p;	
	++f->fin;
}


void dequeue(Fila *f) {
	if(f->init == MAX-1) {
		if(!f->fin) {
			printf("Queue is empty\n");
		}
		f->init = 0;
	}
	if(f->init == f->fin) {
		printf("Queue is empty!\n");
		return;
	}
	f->init++;
}

int first_el(Fila f) {
	return f.q[f.init];
}

int main(){
	Fila p;
	return 0;
}
