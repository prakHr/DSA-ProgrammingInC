#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void insert(int val,int len,int heap[]);
void print_heap(int len,int arr[]);
int delete_heapify(int len,int heap[]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}
	//Creating heap
	int heap[N];
	for(int i=0;i<N;i++){
		insert(arr[i],i-1,heap);
		print_heap(i,heap);
	}
	/*for(int i=0;i<N;i++){
		printf("Deleting %d\n",i);
		delete_heapify(N-i-1,heap);
		print_heap(N-i-2,heap);
	}*/

	//take out two elemtnt at once and inset sum back
	int count=0;
	int sum=0;
	int len=N-1;
	while(count!=N-1){
		int val1=delete_heapify(len,heap);
		len--;
		int val2=delete_heapify(len,heap);
		len--;
		sum+=val1+val2;
		insert(val1+val2,len,heap);
		len++;
		count++;
		printf("Printing heap: count:%d len:%d",count,len);
		print_heap(len,heap);
	}
	printf("COST: %d\n",sum);
	return 0;
}

void insert(int val,int len,int heap[]){
	//len is the cuurent last position in the heap
	if(len==-1){
		heap[len+1]=val;
		return;
	}
	int idx=len+1;
	heap[idx]=val;
	int parent=(idx-1)/2; // '/' will automatically take floor
	while(parent>=0){
		//printf("Parent: %d\n",parent);
		if(heap[parent]>val){
			heap[idx]=heap[parent];
			heap[parent]=val;
		}
		idx=parent;
		parent=(int)floor((float)(idx-1)/2);
	}
}

int delete_heapify(int len,int heap[]){
	int val=heap[0];
	heap[0]=heap[len];
	//printf("first: %d\n",heap[0]);
	len--;
	int idx=0;
	int child1=(2*idx+1);
	int child2=(2*idx+2);
	//printf("ch1: %d ch2: %d len: %d\n",child1,child2,len);
	while(child1<=len || child2<=len){
		int val1=heap[child1];
		int val2=heap[child2];

		if(val1<=val2 && heap[idx]>val1){
			int temp=heap[idx];
			heap[idx]=val1;
			heap[child1]=temp;
			idx=child1;
		}
		else if(val2<val1 && heap[idx]>val2){
			int temp=heap[idx];
			heap[idx]=val2;
			heap[child2]=temp;
			idx=child2;
		}
		else{
			break;
		}
		child1=2*idx+1;
		child2=2*idx+2;
	}
	//printf("JA JA\n");
	return val;
}

void print_heap(int len,int arr[]){
	printf("Printing Heap: ");
	for(int i=0;i<=len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}