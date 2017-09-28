#include <stdlib.h>
#include <stdio.h>

#define MAX 20

#define ll long long

long long fat(long long i){
	if(i==1 || !i)
		return 1;
	else
		return i * fat(i-1);
}

long long fib(long long i){
	if(!i || i==1)
		return 1;
	else
		return fib(i-1)+fib(i-2);
}


ll insertSorted(ll *arr, int n, ll key)
{
	int i;
	if (n >= MAX)
		return n;

	for (i=n-1; ( i >= 0  && arr[i] > key); i--)
	 	arr[i+1] = arr[i];

	arr[i+1] = key;

	return (n+1);
}


int main() {
	long long i, vetor[MAX], tam = 0;

	while(1){
		scanf("%lld", &i);
		tam = insertSorted(vetor, tam, i);
		if(!i) break;
	}

	system("clear");

	for (i = 0; i < tam; ++i) {
		printf("%lld\n",vetor[i]);
	}

}
