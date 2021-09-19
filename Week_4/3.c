#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void selection_sort(int *swap,int n,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	int swap=0;
	selection_sort(&swap,n,arr);
	printf("SWAP:%d\n",swap);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void selection_sort(int *swap,int n,int arr[]){
	for(int i=0;i<n-1;i++){
		int min=arr[i];
		int idx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<min){
				idx=j;
				min=arr[j];
			}
		}
		if(idx!=i){
			*swap+=1;
			arr[idx]=arr[i];
			arr[i]=min;
		}
	}
}