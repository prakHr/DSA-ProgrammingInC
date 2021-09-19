#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void merge_sort(int low,int high,int arr[][2]);

int main(){
	int n;
	scanf("%d",&n);
	int time[n][2];
	for(int i=0;i<n;i++){
		scanf(" %d",&time[i][0]);
	}
	for(int i=0;i<n;i++){
		scanf(" %d",&time[i][1]);
	}
	merge_sort(0,n-1,time);
	for(int i=0;i<n;i++){
		printf("low:%d high:%d\n",time[i][0],time[i][1]);
	}
	printf("\n");
	int max=0;
	int opt_time=-1;
	for(int i=0;i<n;i++){
		int i_max=0;
		int t_self=time[i][0];
		for(int j=0;j<=i;j++){
			if(time[j][1]>=t_self){
				i_max+=1;
			}
		}
		printf("max:%d i_max:%d t_self:%d\n",max,i_max,t_self);
		if(i_max>max){
			opt_time=t_self;
			max=i_max;
		}
	}
	printf("\ntime:%d\n",opt_time);
	return 0;
}

void merge_sort(int low,int high,int arr[][2]){
	if(high==low){
		return;
	}

	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1][2];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1][0]>arr[p2][0]){
			temp_arr[count][0]=arr[p2][0];
			temp_arr[count][1]=arr[p2][1];
			count++;
			p2++;
		}
		else{
			temp_arr[count][0]=arr[p1][0];
			temp_arr[count][1]=arr[p1][1];
			count++;
			p1++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp_arr[count][0]=arr[i][0];
			temp_arr[count][1]=arr[i][1];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp_arr[count][0]=arr[i][0];
			temp_arr[count][1]=arr[i][1];
			count++;
		}
	}

	for(int i=low;i<=high;i++){
		arr[i][0]=temp_arr[i-low][0];
		arr[i][1]=temp_arr[i-low][1];
	}
}