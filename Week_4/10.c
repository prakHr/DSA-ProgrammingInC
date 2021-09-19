#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void reverse(int idx,int arr[]);
void print_arr(int n,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	int count=0;
	while(count!=n){
		int max=arr[0];
		for(int i=1;i<n-count;i++){
			if(arr[i]>max){
				//printf("%d %d",arr[i],max);
				max=arr[i];//keep it up,else it will take from reverted array
				reverse(i,arr);
			}
		}
		count++;
		printf("count:%d ",count);
		reverse(n-count,arr);
		print_arr(n,arr);
	}
	return 0;
}

void reverse(int idx,int arr[]){
	for(int i=idx;i>=idx/2+1;i--){
		int temp=arr[i];
		arr[i]=arr[idx-i];
		arr[idx-i]=temp;
	}
}

void print_arr(int n,int arr[]){
	printf("new iter: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}