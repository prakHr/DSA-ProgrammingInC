#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
	long long int n;
	scanf("%d",&n);
	long long int counter=0;
	do{
		counter+=n%2;
		n=n/2;
	}while(n!=0);
	printf("%lld\n",counter);
	return 0;
}