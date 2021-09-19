#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

void merge_count(int *count,int low,int high,int arr[]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}
	int count=0;
	merge_count(&count,0,N-1,arr);
	for(int i=0;i<N;i++){
		printf("%d ",arr[i]);
	}
	printf("\nCOUNT: %d\n",count);
	return 0;
}
void merge_count(int *count,int low,int high,int arr[]){
	if(high==low){
		return;
	}

	//dividing the problem
	int mid=(high+low)/2;
	merge_count(count,low,mid,arr);
	merge_count(count,mid+1,high,arr);

	//combining the solution
	int p1=low;
	int p2=mid+1;
	int temp[high-low+1];
	int c=0;
	while(p1<=mid && p2<=high){
		if(arr[p1]>arr[p2]){
			temp[c]=arr[p2];
			p2++;
			c++;
			*count+=(mid-p1)+1; //+1 kyunki ye khud bhi to bada hai
		}
		else{
			temp[c]=arr[p1];
			p1++;
			c++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp[c]=arr[i];
			c++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp[c]=arr[i];
			c++;
		}
	}

	//finally updating the solved subproblem in actual array
	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}
}