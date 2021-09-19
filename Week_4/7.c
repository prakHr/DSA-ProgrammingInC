#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void quickPartition(int lp,int rp,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	quickPartition(0,n-1,arr);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void quickPartition(int lp,int rp,int arr[]){
	int lflag=0,rflag=0;
	while(lp<rp){
		if(arr[lp]%2==1){
			lflag=1;
		}
		else if(lflag==0){
			lp++;
		}
		if(arr[rp]%2==0){
			rflag=1;
		}
		else if(rflag==0){
			rp--;
		}
		if(rflag==1 && lflag==1){
			int temp=arr[lp];
			arr[lp]=arr[rp];
			arr[rp]=temp;
			lflag=0;
			rflag=0;
			lp++;
			rp--;
		}

	}
}