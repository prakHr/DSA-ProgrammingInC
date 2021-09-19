#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define lli long long int
lli divisor(lli num);

int main(){
	lli a,b;
	int n;
	scanf("%lld %lld %d",&a,&b,&n);

	int count=0;
	for(lli i=a;i<=b;i++){ //a and b are inclusive
		lli div=divisor(i);
		if(div==n){//is lli and int comparison valid, int will be impleictl converted to long long so yes
			count++;
		}
	}
	printf("COUNT: %d\n",count);
	return 0;
}

lli divisor(lli num){
	lli count=0;
	lli to=(lli)pow(num,0.5);
	for(lli i=1;i<=to;i++){
		if(num%i==0){
			count++;
			if(num/i!=i){
				count++;
			}
		}
	}
	return count;
}