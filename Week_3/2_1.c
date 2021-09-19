#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void merge_sort(int *ip,int low,int high,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ip=0;
	merge_sort(&ip,0,n-1,arr);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nIP: %d\n",ip);
	return 0;
}

void merge_sort(int *ip,int low,int high,int arr[]){
	//handling the base-case
	if(high==low){
		return;//last element nothing to do.
	}
	int mid=(high+low)/2;
	//Divide Step
	merge_sort(ip,mid+1,high,arr);
	merge_sort(ip,low,mid,arr);
	

	//merging step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1]>arr[p2]){
			*ip=*ip+1+(mid-p1);//(mid-p1) add the 
			//extra comparison which were left by 
			//ingenioty of quick sort.
			temp_arr[count]=arr[p2];
			count++;
			p2++;
		}
		else{
			temp_arr[count]=arr[p1];
			count++;
			p1++;
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
	for(int i=low;i<=high;i++){
		arr[i]=temp_arr[i-low];
	}
}