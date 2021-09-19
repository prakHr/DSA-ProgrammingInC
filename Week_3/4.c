#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int low,int high,int arr[]);

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int ply[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&ply[i]);
	}
	
	int count=0;
	int pc;
	do{
		merge_sort(0,N-1,ply);
		for(int i=0;i<N;i++){
			printf("%d ",ply[i]);
		}
		printf("\n");
		pc=0;
		for(int i=N-1;i>=0;i--){
			if(ply[i]>0){
				ply[i]--;
				pc++;
			}
			if(pc==M){
				count++;
				break;
			}
		}
	}while(pc==M);

	printf("%d\n",count);
	return 0;
}

void merge_sort(int low,int high,int arr[]){
	//base case for recursion
	if(low==high){
		return;
	}
	//Divide Step
	int mid=(low+high)/2;
	merge_sort(mid+1,high,arr);
	merge_sort(low,mid,arr);
	

	//Conquer/Merge Step
	int p1=low;
	int p2=mid+1;//for second half problem the second pointer
	int temp_arr[high-low+1];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1]>arr[p2]){
			temp_arr[count]=arr[p2];
			p2++;
			count++;
		}
		else{
			temp_arr[count]=arr[p1];
			p1++;
			count++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp_arr[count]=arr[i];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp_arr[count]=arr[i];
			count++;
		}
	}

	for(int i=0;i<high-low+1;i++){
		arr[low+i]=temp_arr[i];
	}
}