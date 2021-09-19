#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define range 10000
struct node{
	int num;
	int cid;
	struct node *next;
};
int check_prime(int num);
void add_node(int num,int cid,int pid,struct node *graph[]);
int check_one_diff(int num1,int num2);
void print_graph(int N,int nums[],struct node *graph[]);
int search_path(int pid,int visited[],int num,int nums[],struct node *graph[]);

int main(){
	int arr[range];
	int count=0;
	for(int i=1000;i<range;i++){
		arr[i]=check_prime(i);
		if(arr[i]==1){
			count++;
		}
		//printf("num:%d flag:%d\n",i+1,arr[i]);
	}

	//creating the graph of prime
	struct node *graph[count];
	int nums[count];
	count=0;
	for(int i=1000;i<range;i++){
		if(arr[i]==1){
			nums[count]=i;
			count++;
		}
	}
	for(int i=0;i<count;i++){
		graph[i]=NULL;
	}
	for(int i=0;i<count;i++){ //O(N^2) :N is number of prime
		for(int j=i+1;j<count;j++){
			int flag=check_one_diff(nums[i],nums[j]);
			if(flag==1){
				add_node(nums[j],j,i,graph);
				add_node(nums[i],i,j,graph);
			}
		}
	}
	//print_graph(count,nums,graph);

	//now traverse the graph
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int num1,num2;
		scanf(" %d %d",&num1,&num2);
		if(num1==num2){
			printf("%d\n",0);
			continue;
		}
		int start;
		int visited[count];
		for(int i=0;i<count;i++){
			visited[i]=0;
			if(nums[i]==num1){
				start=i;
			}
		}
		search_path(start,visited,num2,nums,graph);
		printf("Length: %d\n",visited[start]);
	}
	return 0;
}
int check_prime(int num){
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}
void add_node(int num,int cid,int pid,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->num=num;
	temp->cid=cid;
	temp->next=NULL;

	if(graph[pid]==NULL){
		graph[pid]=temp;
		return;
	}
	struct node *head=graph[pid];
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=temp;
}
int check_one_diff(int num1,int num2){
	//will check for the only one digit difference between
	//the graph
	int count=0;
	for(int i=0;i<4;i++){
		int dig1=num1%10;
		int dig2=num2%10;
		if(dig1!=dig2){
			count++;
		}
		num1=num1/10;
		num2=num2/10;
	}
	if(count==1){
		return 1;
	}
	return 0;
}
void print_graph(int N,int nums[],struct node *graph[]){
	printf("Printing the Graph\n");
	for(int i=0;i<N;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("from:%d to:%d\n",nums[i],head->num);
			head=head->next;
		}
	}
}

//worst case complexity loosely (nC2 or O(N^2))
int search_path(int pid,int visited[],int num,int nums[],struct node *graph[]){
	//handling the base case
	if(graph[pid]==NULL || visited[pid]!=0){
		return -1;
	}
	
	struct node *head=graph[pid];
	visited[pid]=INT_MAX; //for showing that it has been travelled but
	//it has not yet foubd the end
	int found=0;
	while(head!=NULL){
		if(head->num==num){
			found=1;
			visited[pid]=1;
			printf("got it: pid:%d cid:%d len:%d\n",nums[pid],head->num,visited[pid]);
		}
		else if(visited[head->cid]!=0 && visited[head->cid]!=INT_MAX && 
						visited[head->cid]+1<visited[pid]){
			found=1;
			visited[pid]=visited[head->cid]+1;
			printf("got it: pid:%d cid:%d len:%d\n",nums[pid],head->num,visited[pid]);
		}
		else{
			int flag=search_path(head->cid,visited,num,nums,graph);
			if(flag==1 && visited[head->cid]+1<visited[pid]){
				found=1;
				visited[pid]=visited[head->cid]+1;
				printf("got it: pid:%d cid:%d len:%d\n",nums[pid],head->num,visited[pid]);
			}
		}
		head=head->next;
	}
	if(found==1){
		return 1;
	}
	return 0;
}