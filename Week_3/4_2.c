#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int check_feasibility(int prop_max,int M,int N,int nop[]);

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int nop[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&nop[i]);
	}

	int min=0;
	int max=(N/M)*109;

	while(min<max){
		int mid=(min+max)/2+1;
		printf("min:%d max:%d mid:%d\n",min,max,mid);
		int k_flag=check_feasibility(mid,M,N,nop);
		if(k_flag==1){
			min=mid;//always contains the feasible number of teams
		}
		else{
			max=mid-1;//will come down which could be possible and when breaks then its =min(thats feasible)
		}
	}
	printf("The max num of teams: %d\n",max);//so max is printed
	return 0;
}

int check_feasibility(int prop_max,int M,int N,int nop[]){
	int pool=0;
	for(int i=0;i<N;i++){
		if(nop[i]>=prop_max){
			pool+=prop_max;
		}
		else{
			pool+=nop[i];
		}
	}
	if(pool>=M*prop_max){
		return 1;
	}
	else{
		return 0;
	}
}