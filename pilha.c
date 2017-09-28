#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
	int tam;
	char *s;
}stack;

stack new(int i){
	stack p;
	p.tam = 0;
	p.s = (char*) malloc(i * sizeof(stack));
	return p;
}


int is_empty(stack p){
	return !p.tam;
}

void clear(stack *p){
	char *ps = p->s;
	p->tam = 0;
	free(ps);
}

void push(stack *p, char i){
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

char top_el(stack p){
	return p.s[p.tam-1];
}

/*Problema dos parenteses e notacao polonesa

int verify(char *st){
	int i=0, tam=strlen(st), p = 0, co = 1, ch = 2;
	stack s = new(tam);

	while(st[i] != '\0'){
		if(st[i] == '('){
			push(&s, p);
		}
		else if(st[i] == '['){
			push(&s, co);
		}
		else if(st[i] == '{'){
			push(&s, ch);
		}
		else if(st[i] == ')'){
			if(top_el(s) != p){
				printf("NAO TA CERTO ESSA BOSTA\n");
				return 0;
			}
			pop(&s);
		}
		else if(st[i] == ']'){
			if(top_el(s) != co){
				printf("NAO TA CERTO ESSA BOSTA\n");
				return 0;
			}
			pop(&s);
		}
		else if(st[i] == '}'){
			if(top_el(s) != ch){
				printf("NAO TA CERTO ESSA BOSTA\n");
				return 0;
			}
			pop(&s);
		}
		++i;
	}
	return 1;
}
*/

/*Notacao infixa para posfixa*/

int Prioridade(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
}

void In2Pos(char expr[]){
  stack p;
  int i = 0;
  char c,t;
 
  p = new(500);
  push(&p, '(');
 
  do{
    c = expr[i];
    i++;
    if(c >= 'a' && c <= 'z'){
      printf("%c", c);
    }
    else if(c == '('){
      push(&p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = top_el(p);
        pop(&p);
        if(t != '(')
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = top_el(p);
        pop(&p);
        if(Prioridade(c,t)){
          push(&p, t);
          push(&p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0');
  printf("\n");
  clear(&p);
}
int main(){
	char nome[100];

	scanf("%[^\n]", nome);

	In2Pos(nome);
/*	if(verify(nome))
		printf("\n\nVOCE E FODA SABE ESCREVER UM CALCULO CERTO MUI BUENO\n");
*/	return 0;
}
