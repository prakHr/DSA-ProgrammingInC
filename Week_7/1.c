#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void insert_heap(int heap_type,int len,int val,int arr[]);
int delete_heapify(int heap_type,int len,int arr[]);
void print_heap(int len,int arr[]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		//scanf(" %d",&arr[i]);
		arr[i]=i;
	}

	//Filling the heap the we have around the mid and mid+1 
	//element
	int len1=-1,len2=-1;
	int arr1[N],arr2[N]; //1:max 2:min
	for(int i=0;i<N;i++){
		int val=arr[i];
		if(len1-len2==0){
			insert_heap(1,len1,val,arr1);
			len1++;
			//print_heap(len1,arr1);
			//print_heap(len2,arr2);
			float temp=val;
			if(len2!=-1 && arr2[0]<val){
				temp=arr2[0];				
			}
			printf("%f\n",temp);
		}
		else if(len1-len2==1){
			insert_heap(1,len1,val,arr1);
			len1++;
			int temp=delete_heapify(1,len1,arr1);
			len1--;
			insert_heap(2,len2,temp,arr2);
			len2++;
			//print_heap(len1,arr1);
			//print_heap(len2,arr2);
			if(arr1[0]>arr2[0]){
				int k=delete_heapify(1,len1,arr1);
				len1--;
				int kk=delete_heapify(1,len2,arr2);
				len2--;
				insert_heap(1,len1,kk,arr1);
				len1++;
				insert_heap(2,len2,k,arr2);
				len2++;
			}
			printf("%f\n",(float)(arr1[0]+arr2[0])/2);
		}
	}
	return 0;
}

void insert_heap(int heap_type,int len,int val,int arr[]){
	//assuming the len is current length before addn
	//heap_type:1=maxheap, heap_type:2=minheap

	if(len==-1){//when nothing is in the heap
		arr[len+1]=val;
		return;
	}
	int idx=len+1;
	arr[idx]=val;
	len++;
	int parent=(int)floor((float)(len-1)/2);
	while(parent>=0){
		if(arr[parent]>val && heap_type==2){
			arr[idx]=arr[parent];
			arr[parent]=val;
			idx=parent;
			parent=(int)floor((float)(idx-1)/2);
		}
		else if(arr[parent]<val && heap_type==1){
			arr[idx]=arr[parent];
			arr[parent]=val;
			idx=parent;
			parent=(int)floor((float)(idx-1)/2);
		}
		else{
			break;
		}
	}
}

int delete_heapify(int heap_type,int len,int arr[]){
	if(len==-1){
		return -1;
	}
	int ret_val=arr[0];
	arr[0]=arr[len];
	len--;
	if(heap_type==1){
		arr[len+1]=-1;
		//so that it is never selected i.e more in max-heap
	}
	else{
		arr[len+1]=10000000; 
		//so that is is never selected i.e less in min-heap
	}

	int idx=0;
	int child1=2*idx+1;
	int child2=2*idx+2;
	while(child1<=len || child2<=len){ 
	//atleast dono mein se ek bhi
		if(heap_type==1){//maxheap
			int val,pos;
			if(arr[child1]>arr[child2]){
				val=arr[child1];
				pos=child1;
			}
			else{
				val=arr[child2];
				pos=child2;
			}
			if(arr[idx]<val){
				arr[pos]=arr[idx];
				arr[idx]=val;
			}
			else{
				break;
			}
			idx=pos;
			child1=2*idx+1;
			child2=2*idx+2;
		}
		else{//minheap
			int val,pos;
			if(arr[child1]<arr[child2]){
				val=arr[child1];
				pos=child1;
			}
			else{
				val=arr[child2];
				pos=child2;
			}
			if(arr[idx]>val){
				arr[pos]=arr[idx];
				arr[idx]=val;
			}
			else{
				break;
			}
			idx=pos;
			child1=2*idx+1;
			child2=2*idx+2;
		}
	}
	return ret_val;
}

void print_heap(int len,int arr[]){
	printf("Printing Heap: ");
	for(int i=0;i<=len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}