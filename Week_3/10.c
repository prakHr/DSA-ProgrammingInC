#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void insertion_sort(int *cp,int n,int arr[]);
void bubble_sort(int *cp,int n,int arr[]);
void selection_sort(int *cp,int n,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	// int cp=0;
	// insertion_sort(&cp,n,arr);
	// for(int i=0;i<n;i++){
	// 	printf("%d ",arr[i]);
	// }
	// printf("\ncp: %d\n",cp);

	// int cp=0;
	// bubble_sort(&cp,n,arr);
	// for(int i=0;i<n;i++){
	// 	printf("%d ",arr[i]);
	// }
	// printf("\ncp: %d\n",cp);

	int cp=0;
	selection_sort(&cp,n,arr);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\ncp: %d\n",cp);

}

void insertion_sort(int *cp,int n,int arr[]){
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			*cp+=1;
			if(arr[j-1]>arr[j]){
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void bubble_sort(int *cp,int n,int arr[]){
	int flag=0;
	for(int i=0;i<n;i++){
		flag=0;
		for(int j=1;j<n-i;j++){
			*cp+=1;
			if(arr[j]<arr[j-1]){
				flag=1;
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
		if(flag==0){
			break;
		}
	}
}

void selection_sort(int *cp,int n,int arr[]){
	for(int i=0;i<n-1;i++){
		int least=arr[i];
		int least_idx=i;//assuming this to be maximum range
		for(int j=i;j<n;j++){
			*cp+=1;
			if(arr[j]<least){
				least=arr[j];
				least_idx=j;
			}
		}
		arr[least_idx]=arr[i];
		arr[i]=least;
	}
}