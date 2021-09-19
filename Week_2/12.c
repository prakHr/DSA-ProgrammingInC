#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void find_lim(int *lb,int *ub,int arr[],int x,int low,int high);

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	int low=0,high=n-1;
	int lb=0,ub=n-1;
	find_lim(&lb,&ub,arr,x,low,high);

	printf("%d %d\n",lb,ub);

	return 0;
}

void find_lim(int *lb,int *ub,int arr[],int x,int low,int high){
	int mid=(low+high)/2;
	if(low>high){
		return;
	}
	if(arr[mid]<x){
		*lb=mid+1;
		if(high==low){
			return;
		}
		find_lim(lb,ub,arr,x,mid+1,high);
	}
	else if(arr[mid]>x){
		*ub=mid-1;
		if(high==low){
			return;
		}
		find_lim(lb,ub,arr,x,low,mid-1);
	}
	else{
		if(*lb>mid){
			*lb=mid;
		}
		if(*ub<mid){
			*ub=mid;
		}
		if(high==low){
			return;
		}
		find_lim(lb,ub,arr,x,low,mid-1);//search lower one
		find_lim(lb,ub,arr,x,mid+1,high);

	}
	return;
}