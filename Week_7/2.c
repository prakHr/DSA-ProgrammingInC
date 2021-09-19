#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void print_heap(int len,int arr[][2]);
void insert_minheap(int val,int actid,int len,int arr[][2]);
int delete_heapify(int len,int arr[][2]);

//first sort the time array for correct answer in hacker rank
//also question requires long long int for time

int main(){
	int N;
	scanf("%d",&N);
	int arr[N][2];
	for(int i=0;i<N;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
	}

	//now doing the shortest job first
	int global_time=0;
	int heap[N][2];
	int len=-1;
	int wait_time=0;
	for(int i=0;i<N;i++){
		if(arr[i][0]<=global_time){
			insert_minheap(arr[i][1],i,len,heap);
			len++;
			//global_time=arr[i][0];
			print_heap(len,heap);
			printf("global_time: %d\n\n",global_time);
		}
		else if(len!=-1){
			int idx=delete_heapify(len,heap);
			len--;
			global_time+=arr[idx][1];
			wait_time+=(global_time-arr[idx][0]);
			i--;
			print_heap(len,heap);
			printf("global_time: %d\n\n",global_time);
		}
		else{
			global_time=arr[i][0];
			i--;
		}
	}
	while(len!=-1){
		int idx=delete_heapify(len,heap);
		len--;
		global_time+=arr[idx][1];
		wait_time+=(global_time-arr[idx][0]);
		print_heap(len,heap);
		printf("global_time: %d\n\n",global_time);
	}
	printf("%d\n",wait_time/N);
	return 0;
}

void insert_minheap(int val,int actid,int len,int arr[][2]){
	if(len==-1){
		arr[0][0]=val;
		arr[0][1]=actid;
		return;
	}
	int idx=len+1;
	arr[idx][0]=val;
	arr[idx][1]=actid;
	int parent=(int)floor((float)(idx-1)/2); //otherwise 0 pe atak jayega
	while(parent>=0){
		if(arr[parent][0]>val){
			arr[idx][0]=arr[parent][0];
			arr[idx][1]=arr[parent][1];
			arr[parent][0]=val;
			arr[parent][1]=actid;
			idx=parent;
			parent=(int)floor((float)(idx-1)/2);
		}
		else{
			break;
		}
	}
}

int delete_heapify(int len,int arr[][2]){
	int ret_actid=arr[0][1];
	arr[0][0]=arr[len][0];
	arr[0][1]=arr[len][1];
	len--;
	arr[len+1][0]=1000000001;//ab kabhi chota nahi hoga. so upar nahi jayega
	int idx=0;
	int child1=2*idx+1;
	int child2=2*idx+2;
	while(child1<=len || child2<=len){
		int val,pos,actid;
		if(arr[child1][0]<arr[child2][0]){
			val=arr[child1][0];
			actid=arr[child1][1];
			pos=child1;
		}
		else{
			val=arr[child2][0];
			actid=arr[child2][1];
			pos=child2;
		}
		if(arr[idx][0]>val){
			arr[pos][0]=arr[idx][0];
			arr[pos][1]=arr[idx][1];
			arr[idx][0]=val;
			arr[idx][1]=actid;
		}
		else{
			break;
		}
		idx=pos;
		child1=2*idx+1;
		child2=2*idx+2;
	}
	return ret_actid;
}

void print_heap(int len,int arr[][2]){
	printf("Printing Heap: ");
	for(int i=0;i<=len;i++){
		printf("%d ",arr[i][0]);
	}
	printf("\n");
}

