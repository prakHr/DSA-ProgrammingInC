#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int num_factor(int num);
void stable_sort(int n,int max,int arr[][2]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n][2];
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i][0]);
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		arr[i][1]=num_factor(arr[i][0]);
		if(arr[i][1]>max){
			max=arr[i][1];
		}
		printf("num:%d factors:%d\n",arr[i][0],arr[i][1]);
	}
	stable_sort(n,max,arr);
	return 0;
}

int num_factor(int num){
	int count=0;
	int upto=(int)pow(num,0.5);
	for(int i=1;i<=upto;i++){
		if(num%i==0){
			count++;
			if(num/i!=i){
				count++;
			}
		}
	}
	return count;
}

void stable_sort(int n,int max,int arr[][2]){
	//assumption min ele is 1
	int count[max];
	for(int i=0;i<max;i++){
		count[i]=0;
	}
	//counting the numbers
	for(int i=0;i<n;i++){
		count[max-arr[i][1]]+=1;//here the max cout is reverse mapped ie. max,max-1,max-2 .... 2,1
	}
	// for(int i=0;i<max;i++){
	// 	printf("num:%d count:%d\n",max-i,count[i]);
	// }

	//Getting the cumulative sum
	for(int i=1;i<max;i++){
		count[i]+=count[i-1];
	}

	//Saving in a temp array of the sorted in decreasing order.
	int temp_arr[n][2];
	for(int i=n-1;i>=0;i--){//opp:this is necessary for forer comes former in case of same val
		int fact=arr[i][1];
		int prev=count[max-fact]-1;//converting to zero based indexing
		//printf("fact:%d pos:%d\n",fact,prev);
		temp_arr[prev][0]=arr[i][0];
		temp_arr[prev][1]=arr[i][1];
		count[max-fact]--;
	}
	printf("Printing:\n");
	for(int i=0;i<n;i++){
		printf("%d ",temp_arr[i][0]);
	}
	printf("\n");
}