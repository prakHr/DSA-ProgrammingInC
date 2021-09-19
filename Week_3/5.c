#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct list{
	long long int num;
	struct list * next;
};
void merge_sort(int low,int high,long long int arr[]);


int main(){
	long long int N,M;
	scanf("%lld %lld",&N,&M);
	long long int bound[N][2];
	for(int i=0;i<N;i++){
		scanf(" %lld",&bound[i][0]);
	}
	for(int i=0;i<N;i++){
		scanf(" %lld",&bound[i][1]);
	}
	struct list *head=NULL;
	struct list *tail=NULL;
	int count=0;
	printf("Adding to List\n");
	for(int i=0;i<N;i++){
		for(int j=bound[i][0];j<=bound[i][1];j++){
			printf("i:%d j:%d \n",i,j);
			if(i==0 && j-bound[i][0]==0){
				head=tail=(struct list*)malloc(sizeof(struct list));
				tail->num=j;
				count++;
			}
			else{
				struct list *temp=(struct list*)malloc(sizeof(struct list));
				temp->num=j;
				tail->next=temp;
				tail=temp;
				count++;
			}
		}
	}
	printf("Inserted\n");
	long long int arr[count];
	count=0;
	while(head!=NULL){
		printf("%lld ",head->num);
		arr[count]=head->num;
		//printf("%d %lld ",count,head->num);
		head=head->next;
		count++;
	}
	printf("\n");
	merge_sort(0,count-1,arr);
	for(int i=0;i<count;i++){
		printf("%lld ",arr[i]);
	}
	printf("\nMth smallest ele: %lld\n",arr[M]);
	return 0;
}

void merge_sort(int low,int high,long long int arr[]){
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
	long long int temp_arr[high-low+1];

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