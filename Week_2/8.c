#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void split_prime(int arr[][2],int N);
int check_prime(int N);

int main(){
	int N;
	scanf("%d",&N);
	int parr[N+1][2];
	for(int i=2;i<=N;i++){
		parr[i][0]=check_prime(i);
		parr[i][1]=0;
	}
	split_prime(parr,N);
	int sum=0;
	for(int i=2;i<=N;i++){
		sum+=parr[i][1];
		printf("%d %d\n",i,parr[i][1]);
	}
	printf("SUM %d\n",sum);
	return 0;
}

int check_prime(int N){
	int flag=1;
	for(int i=2;i<(N)/2;i++){
		if(N%i==0){
			flag=0;
			break;
		}
	}
	//1:prime, 0:non-prime
	return flag;
}

void split_prime(int arr[][2],int N){
	int quot=0;
	for(int i=2;i<=N;i++){
		if(arr[i][0]==1 && N%i==0){
			arr[i][1]++;
			quot=N/i;
			split_prime(arr,quot);
			return;
		}
	}
	return;
}