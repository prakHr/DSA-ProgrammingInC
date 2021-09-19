#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int check_luck(int N);

int main(){
	long long int N;
	scanf("%lld",&N);
	//printf("%d\n",check_luck(N));
	int count=0;
	for(int i=1;i<=N;i++){
		int flag=check_luck(i);
		if(flag==1){
			printf("NUM: %d\n",i);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}

int check_luck(int N){
	int temp=1;
	while(N!=0){
		int dig=(N%(temp*10))/temp;
		//printf("dig %d\n",dig);
		N=(N-dig)/(temp*10);
		if(dig==7 || dig==1 || dig==9){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}