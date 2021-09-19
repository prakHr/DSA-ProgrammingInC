#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void merge_sort(int low,int high,int arr[]);

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int x[n];
	int y[m][2];
	int min;
	for(int i=0;i<n;i++){
		scanf(" %d",&x[i]);
		if(i==0){
			min=x[i];
		}
		else if(x[i]<min){
			min=x[i];
		}
	}
	for(int i=0;i<m;i++){
		scanf(" %d",&y[i][0]);
		y[i][1]=0;//for used flag
	}

	//Approach 1: with masking the elemet of Y O(mn).
	//and overall complexity O(mn+nlogn)
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(y[i][0]==x[j]){
				x[j]=min-m+i;//giving the 
				y[i][1]=1;
			}
		}
	}
	printf("Sorting the x:\n");
	merge_sort(0,n-1,x);
	for(int i=0;i<n;i++){
		if(x[i]<min){
			int j=x[i]-min+m;
			x[i]=y[j][0];
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");


	printf("Processing y:\n");
	int temp_arr[m];
	int count=0;
	for(int i=0;i<m;i++){
		if(y[i][1]==0){
			temp_arr[count]=y[i][0];
			printf("%d %d\n",i,temp_arr[count]);
			count++;
		}
	}
	if(count>0){
		merge_sort(0,count-1,temp_arr);
		for(int j=0;j<count;j++){
			printf("%d ",temp_arr[j]);
		}
		printf("\n");
	}

	return 0;
}

void merge_sort(int low,int high,int arr[]){
	//hadling the base case of our recursion
	if(high==low){
		return;
	}

	//dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//conquer the subproblems
	int p1=low;
	int p2=mid+1;
	int count=0;
	int temp_arr[high-low+1];

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
	//copying the temp_arr abck to origin memory
	//think of how to do without the extra memory.
	for(int i=low;i<=high;i++){
		arr[i]=temp_arr[i-low];
	}
}