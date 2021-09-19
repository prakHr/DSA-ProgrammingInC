#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void merge_sort(int *cp,int low,int high,int arr[]);
void un_merge_max(int low,int high,int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	int cp=0;
	merge_sort(&cp,0,n-1,arr);
	printf("Comparisons: %d\n",cp);
	
	un_merge_max(0,n-1,arr);
	printf("\nPrinting Tangled:\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	cp=0;
	merge_sort(&cp,0,n-1,arr);
	printf("Comparisons: %d\n",cp);

	return 0;
}

void merge_sort(int *cp,int low,int high,int arr[]){
	if(high==low){
		return;
	}

	//Dividing step
	int mid=(high+low)/2;
	merge_sort(cp,low,mid,arr);
	merge_sort(cp,mid+1,high,arr);

	//Merging step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1];
	int count=0;
	while(p1<=mid && p2<=high){
		*cp=*cp+1;
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
	for(int i=low;i<=high;i++){
		arr[i]=temp_arr[i-low];
	}
}

void un_merge_max(int low,int high,int arr[]){
	//dealing the base case of recursion
	if(high==low){
		//printf("Retruning STEP: %d %d\n",high,low);
		return;
	}

	
	//now the "un"merging step.(here encoding)
	int temp_arr[high-low+1];
	int p1=0;
	int p2=(0+high-low+1-1)/2+1;
	for(int i=low;i<=high;i++){
		if((i-low)%2==0){
			temp_arr[p1]=arr[i];
			p1++;
		}
		else{
			temp_arr[p2]=arr[i];
			p2++;
		}
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp_arr[i-low];
		//printf("%d ",arr[i]);
	}

	//dividing the problem(here problem is merged array :) strange lifes)
	int mid=(low+high)/2;
	//printf("\nLEFT STEP:\n");
	un_merge_max(low,mid,arr);
	//printf("\nRIGHT STEP:\n");
	un_merge_max(mid+1,high,arr);

}