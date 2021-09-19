#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}
	int ptr1=0,ptr2=N-1;
	int year=1;
	int cost=0;
	while(ptr1<=ptr2){
		if(arr[ptr1]<=arr[ptr2]){
			cost+=arr[ptr1]*year;
			ptr1++;
		}
		else{
			cost+=arr[ptr2]*year;
			ptr2--;
		}
		year++;
	}
	printf("COST:%d\n",cost);
	return 0;
}