#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a,b) (a<b ? a : b)
#define MAX(a,b) (a>b ? a : b)

struct node{
	int val;
	int cid;
	struct node *next;
};
void add_node(int pid,int val,int cid,struct node *graph[]);
void print_graph(int N,struct node *graph[]);
int check_binary_tree(int pid,int visited[],struct node *graph[]);
void check_binary_search_tree(int *count,int arr[],int pval,int pid,struct node *graph[]);


int main(){
	int N,rid,rval;
	scanf("%d %d %d",&N,&rid,&rval);
	int adj[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf(" %d",&adj[i][j]);
		}
	}

	struct node *graph[N];
	for(int i=0;i<N;i++){
		graph[i]=NULL;
		for(int j=0;j<N;j++){
			if(adj[i][j]!=0){//0 means there is no connection
				add_node(i,adj[i][j],j,graph);
			}
		}
	}
	print_graph(N,graph);

	//checking the graph to be binary search tree
	int visited[N];
	for(int i=0;i<N;i++){
		visited[i]=0;
	}
	int flag=check_binary_tree(rid,visited,graph);
	for(int i=0;i<N;i++){
		if(visited[i]==0){
			flag=0;
			break;
		}
	}
	if(flag==0){
		printf("Not a Binary Tree\n");
	}
	else{
		printf("Binary Tree\n");
	}

	int trav[N],count=0;
	for(int i=0;i<N;i++){
		trav[i]=0;
	}
	check_binary_search_tree(&count,trav,rval,rid,graph);
	for(int i=0;i<N;i++){
		printf("%d ",trav[i]);
	}
	printf("\n");

	return 0;
}

void add_node(int pid,int val,int cid,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
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
void print_graph(int N,struct node *graph[]){
	printf("Printing the graph\n");
	for(int i=0;i<N;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d %d\n",i,head->cid,head->val);
			head=head->next;
		}
	}
}

int check_binary_tree(int pid,int visited[],struct node *graph[]){
	//handling the base case
	if(visited[pid]==1){
		return 0;
	}
	else if(graph[pid]==NULL){
		visited[pid]=1;
		return 1;
	}

	//going deeper
	int count=0;//2 se jayda children hain
	struct node *head=graph[pid];
	visited[pid]=1;
	while(head!=NULL){
		count++;
		int flag=check_binary_tree(head->cid,visited,graph);
		head=head->next;
		if(flag==0 || count>2){
			return 0;
		}
	}
	return 1;
}

//could have also constructed tree and done inorder traversal
void check_binary_search_tree(int *count,int arr[],int pval,int pid,struct node *graph[]){
	//gval is value of grandfather
	//Handling the base case
	if(graph[pid]==NULL){
		//when we want to check the subtree but the subtree was single node
		arr[*count]=pval;
		(*count)+=1;
		return;
	}

	//handling the recursion of traversal;
	struct node *cid1=graph[pid];
	struct node *cid2=graph[pid]->next;

	if(cid2!=NULL){
		struct node *pos1;
		struct node *pos2;
		if(cid2->val<cid1->val){
			pos1=cid2;
			pos2=cid1;
		}
		else{
			pos1=cid1;
			pos2=cid2;
		}

		check_binary_search_tree(count,arr,pos1->val,pos1->cid,graph);
		arr[*count]=pval;
		(*count)+=1;
		check_binary_search_tree(count,arr,pos2->val,pos2->cid,graph);
	}
	else{
		check_binary_search_tree(count,arr,cid1->val,cid1->cid,graph);
		arr[*count]=pval;
		(*count)+=1;
	}
}