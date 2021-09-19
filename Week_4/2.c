#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void merge_sort(int low,int high,int arr[]);
void binary_search(int *found,int num,int id,int low,int high,int arr[]);


int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int amt[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&amt[i]);
	}


	int found=0;
	merge_sort(0,n-1,amt);
	for(int i=0;i<n;i++){
		printf("%d ",amt[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		int search=x-amt[i];
		binary_search(&found,search,i,0,n-1,amt);
		if(found==1){
			printf("num:%d\n",amt[i]);
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

void merge_sort(int low,int high,int arr[]){
	//handling the base case
	if(high==low){
		return;
	}

	//Dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//Merging Step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1];
	int count=0;

	while(p1<=mid && p2<=high){
		if(arr[p1]>arr[p2]){
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

void binary_search(int *found,int num,int id,int low,int high,int arr[]){
	//id is self id so that we dont find ourselves
	if(high==low){
		if(arr[low]==num && low!=id){
			*found=1;
		}
		return;
	}
	//printf("low:%d high:%d\n",low,high);
	int mid=(high+low)/2;
	if(arr[mid]>num){
		binary_search(found,num,id,low,mid,arr);
	}
	else if(arr[mid]<num){
		binary_search(found,num,id,mid+1,high,arr);
	}
	else{
		if(mid!=id){
			*found=1;
		}
		return;
	}
	//return
	
}