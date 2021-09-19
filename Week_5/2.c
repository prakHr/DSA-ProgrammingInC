#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void get_prime_fac(int N,int arr[]);
int relat_max_factor(int j,int arr2[],int arr[]);

int main(){
	int T;
	//scanf("%d",&T);
	T=300000;
	srand((unsigned int)time(0));
	for(int i=0;i<T;i++){
		int N;
		//scanf("%d",&N);
		N=rand()%1000000;
		int arr[N];
		int arr2[N];
		for(int j=0;j<N;j++){
			arr[j]=0;
			arr2[j]=0;
		}
		get_prime_fac(N,arr);
		//printf("Printing Factors\n");
		for(int j=0;j<N;j++){
			//printf("%d %d\n",j,arr[j]);
		}
		//printf("Printing LCM:\n");
		long long int lcm_sum=0;//atest bade wale ke sare factors to honge hin
		for(int j=1;j<=N;j++){
			int extra=relat_max_factor(j,arr2,arr);
			//printf("j:%d extra:%d lcm:%d\n",j,extra,extra*N);
			lcm_sum+=extra*N;
		}
		printf("LCM SUM:%lld\n",lcm_sum);
	}
	return 0;
}

void get_prime_fac(int N,int arr[]){
	//taking out all the even component
	while(N%2==0){
		arr[2-1]++;
		N=N/2;
		//printf("2\n");
	}

	
	for(int i=3;i<=sqrt(N);i+=2){//running for odd factors
		while(N%i==0){
			arr[i-1]++;
			N=N/i;
			//printf("%d\n",i);
		}
		//after this whatever will be left it will be
		// a factor of odd bigger than this.
		//cuz lower ka jitna hona tha wo to le hin liye hain

	}

	//if the nubmer has not finally become one then
	//the reduced N was itself prime
	if(N>2){//it cant be 2 left.
		arr[N-1]++;
		printf("%d\n",N);
	}
}

int relat_max_factor(int j,int arr2[],int arr[]){
	int extra=1;
	while(j%2==0){
		arr2[2-1]++;
		j=j/2;
	}
	if(arr2[2-1]>arr[2-1]){
		extra=extra*(int)pow(2,arr2[2-1]-arr[2-1]);
	}
	arr2[2-1]=0;

	for(int i=3;i<=sqrt(j);i+=2){
		while(j%i==0){
			arr2[i-1]++;
			j=j/i;
		}
		if(arr2[i-1]>arr[i-1]){
			extra=extra*(int)pow(i,arr2[i-1]-arr[i-1]);
		}
		arr2[i-1]=0;
	}
	if(j>2 && arr[j-1]==0){
		extra=extra*j;
	}

	return extra;
}



