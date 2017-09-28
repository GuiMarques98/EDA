#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char name[30];
	int id;
	struct no *next;
}no;

no * head = NULL;

no* new(){}

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
