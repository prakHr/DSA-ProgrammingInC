#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void merge_sort(int low,int high,int arr[][2]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n][2];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i][1]);
		arr[i][0]=i;
	}
	merge_sort(0,n-1,arr);
	for(int i=0;i<n;i++){
		if(arr[i][0]%2==0){
			printf("%d ",arr[i][1]);
		}
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i][0]%2!=0){
			printf("%d ",arr[i][1]);
		}
	}
	return 0;
}

void merge_sort(int low,int high,int arr[][2]){
	if(high==low){
		return;//sort one element :)
	}

	//dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//Conquer/Merge Step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1][2];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1][1]>arr[p2][1]){
			temp_arr[count][1]=arr[p2][1];
			temp_arr[count][0]=arr[p2][0];
			count++;
			p2++;
		}
		else{
			temp_arr[count][1]=arr[p1][1];
			temp_arr[count][0]=arr[p1][0];
			count++;
			p1++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp_arr[count][1]=arr[i][1];
			temp_arr[count][0]=arr[i][0];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp_arr[count][1]=arr[i][1];
			temp_arr[count][0]=arr[i][0];
		}
	}

	for(int i=low;i<=high;i++){
		arr[i][0]=temp_arr[i-low][0];
		arr[i][1]=temp_arr[i-low][1];
	}
}