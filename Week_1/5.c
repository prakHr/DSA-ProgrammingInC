#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
long long int mod10_10(int n);

int main(){
	int n;
	scanf("%d",&n);
	long long int ans=mod10_10(n);
	printf("%lld\n",ans);
	return 0;
}

long long int mod10_10(int n){
	int a=n/2,b=n/2;
	if(n%2!=0){
		a=n/2;
		b=n/2+1;
	}
	if(a==1 || b==1){
		return pow(2,n);
	}
	else{
		return (mod10_10(a)*mod10_10(b))%(int)pow(10,10);
	}
	return 0;
}