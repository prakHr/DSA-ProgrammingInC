#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}

	int num=arr[0];
	int count=1;
	for(int i=1;i<N;i++){
		if(arr[i]==num){
			count++;
			continue;
		}
		count--;
		if(count==-1){
			num=arr[i];
			count=1;
		}
	}
	int total=0;
	if(count>=0){
		for(int i=0;i<N;i++){
			if(arr[i]==num){
				total++;
			}
		}
		if(total>N/2){
			printf("%d \n",num);
		}
		else{
			printf("None\n");
		}
	}
	else{
		printf("None\n");
	}
	return 0;
}