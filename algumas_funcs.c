#include <stdlib.h>
#include <stdio.h>


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




int main() {
	long long i;
	scanf("%lld", &i);

	printf("%lld\n", fib(i) );
}
