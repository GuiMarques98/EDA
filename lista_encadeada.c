#include <stdio.h>
#include <stdlib.h>

/*N A O  F A Z  S E N T I D O*/
typedef struct node //COLOCA ISSO MSM NAO FAZENDO SENTIDO
{
	int i;
	struct node *next;
}node;

node* cria(){
	return NULL;
}

node* novo() {
	node *n = NULL;
	n = (node*) malloc(sizeof(node));
	n->next = NULL;
	return n;
}

void lst_insert_init(int i, node **head) {
	node *n = NULL;
	n = novo();
	if(*head == NULL){
		n->i = i;
		*head = n;
	}
	else{
		n->i = i;
		n->next = *head;
		*head = n;
	}
}

void lst_delete(int a, node **head) {
	node *pi = *head, *pp = NULL;

	if(pi->i == a){
		*head = pi->next;
		return;
	}
	pp = pi;
	pi = pi->next;
	

	while(pi != NULL && pi->i != a){
		pp = pi;
		pi = pi->next;
	}
	if(pi==NULL)return;
	pp->next = pi->next;
	free(pi);
}

void lst_delete_rec(int i, node **head) {
	
}

void imprime(node* head) {
	if(head==NULL) return;
	printf("%d\n",head->i);
	imprime(head->next);
}

void lst_insert_end(int i, node **head){
	node *p = *head, *n = novo();

	n->i = i;
	if(*head==NULL){
		*head=n;
		return;
	}
	while(p->next != NULL) p = p->next;
	p->next = n;

}

/*void lst_insert_sort(int i, node **head){
	node *p = *head, *n = novo();

	if(p == NULL || p->i > i){
		*head->next = *head;
		*head = n;
		return;
	}
	while(p==NULL){
		if(p-i>i){
			p->next = p;
			p = n;
			return;
		}
		p = p->next;
	}

	lst_insert_end(i, head);
}
*/	
int main(int argc, char const *argv[]) {
	node *head = cria();
	int a;
	while(1){
		scanf("%d",&a);
		if(!a)break;
		lst_insert_end(a, &head);
	}
	system("clear");
	imprime(head);

	return 0;
}