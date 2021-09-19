#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void merge_sort(int low,int high,int arr[][3]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int c_arr[1000][3];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	for(int i=0;i<1000;i++){
		c_arr[i][0]=i+1;
		c_arr[i][1]=-1;//will be filled later
		c_arr[i][2]=0;
	}

	int loc=0;
	for(int i=0;i<n;i++){
		c_arr[arr[i]-1][2]+=1;
		if(c_arr[arr[i]-1][1]==-1){
			c_arr[arr[i]-1][1]=loc;
			loc++;
		}
	}
	// for(int i=0;i<1000;i++){
	// 	printf("idx:%d loc:%d num:%d\n",c_arr[i][0],c_arr[i][1],c_arr[i][2]);
	// }

	merge_sort(0,1000-1,c_arr);
	for(int i=0;i<1000;i++){
		//printf("%d\n",i);
		if(c_arr[i][2]==0){
			continue;
		}
		int num=c_arr[i][0];
		for(int j=0;j<c_arr[i][2];j++){
			printf("%d ",num);
		}
	}
	printf("\n");
	return 0;
}

void merge_sort(int low,int high,int arr[][3]){
	//handling base case of recursion
	if(high==low){
		return;
	}

	//Dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//merging step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1][3];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1][2]<arr[p2][2]){
			temp_arr[count][2]=arr[p2][2];
			temp_arr[count][1]=arr[p2][1];
			temp_arr[count][0]=arr[p2][0];
			count++;
			p2++;
		}
		else if(arr[p1][2]==arr[p2][2]){
			if(arr[p1][1]>arr[p2][1]){//will have the sequence order.
				temp_arr[count][2]=arr[p2][2];
				temp_arr[count][1]=arr[p2][1];
				temp_arr[count][0]=arr[p2][0];
				count++;
				p2++;
			}
			else{
				temp_arr[count][2]=arr[p1][2];
				temp_arr[count][1]=arr[p1][1];
				temp_arr[count][0]=arr[p1][0];
				count++;
				p1++;
			}
		}
		else{
			temp_arr[count][2]=arr[p1][2];
			temp_arr[count][1]=arr[p1][1];
			temp_arr[count][0]=arr[p1][0];
			count++;
			p1++;
		}
	}

	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp_arr[count][2]=arr[i][2];
			temp_arr[count][1]=arr[i][1];
			temp_arr[count][0]=arr[i][0];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp_arr[count][2]=arr[i][2];
			temp_arr[count][1]=arr[i][1];
			temp_arr[count][0]=arr[i][0];
			count++;
		}
	}
	for(int i=low;i<=high;i++){
		arr[i][0]=temp_arr[i-low][0];
		arr[i][1]=temp_arr[i-low][1];
		arr[i][2]=temp_arr[i-low][2];
	}
}	