#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int check_feasibility(int prop_min,int n,int m,int fold[]);

int main(){
	int M,N;
	scanf("%d %d",&M,&N);
	int fold[M];
	for(int i=0;i<M;i++){
		scanf(" %d",&fold[i]);
	}

	int min=0;
	int max=1000000;//or according to constraint if given
	
	int mid;
	//iterative version of binary search
	while(min<max){
		mid=(max+min)/2;
		//printf("MID:%d MIN:%d MAX:%d\n",mid,min,max);
		int k_flag=check_feasibility(mid,N,M,fold);
		if(k_flag==1){
			max=mid;
		}
		else{
			min=mid+1;
		}
	}


	printf("the optimal score is: %d\n",min);


	return 0;
}

int check_feasibility(int prop_min,int n,int m,int fold[]){
	int part=1;
	int sum=0;
	for(int i=0;i<m;i++){
		sum=sum+fold[i];
		if(sum>prop_min){
			sum=fold[i];
			part++;
		}
	}
	if(part<=n){
		return 1;
	}
	else{
		return 0;
	}
}