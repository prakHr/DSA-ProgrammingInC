#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int check_valid(int N,int K);

int main(){
	long long int n;
	int k;
	scanf("%lld %d",&n,&k);
	int small_flag=0;
	for(int i=(int)pow(10,n-1);i<(int)pow(10,n);i++){
		int flag=check_valid(i,k);
		if(flag==1){
			if(small_flag==0){
				printf("Smallest: %d\n",i);
			}
			small_flag=i;
		}
	}
	printf("BIGGEST: %d\n",small_flag);
	return 0;
}

int check_valid(int N,int K){
	int digs[10]={0};
	while(N!=0){
		int dig=(N%10);
		N=N/10;
		digs[dig]=1;
	}
	int count=0;
	for(int i=0;i<10;i++){
		count+=digs[i];
	}
	if(count!=K){
		return 0;
	}
	return 1;//reporting affirmative
}