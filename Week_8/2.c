#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int cid;
	struct node *next;
};
void insert_node(int pid,int cid,struct node *graph[]);
void print_graph(int M,struct node *graph[]);
void get_all_path(int *paths,int len,int k,int pid,int cid,int M,int visited[],struct node *graph[]);

int main(){
	int M,K;
	scanf("%d %d",&M,&K);
	int adj[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf(" %d",&adj[i][j]);
		}
	}
	int c1,c2;//city number is in zero based indexing
	scanf(" %d %d",&c1,&c2);

	//creating the graph
	struct node *graph[M];
	for(int i=0;i<M;i++){//O(M^3)
		graph[i]=NULL;
		for(int j=0;j<M;j++){
			if(adj[i][j]==1){
				insert_node(i,j,graph);
			}
		}
	}
	print_graph(M,graph);

	//Now traversing to find the longest path
	int visited[M];
	int paths=0;
	get_all_path(&paths,0,K,c1,c2,M,visited,graph);
	printf("total paths: %d\n",paths);	
	return 0;
}

void insert_node(int pid,int cid,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
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
void print_graph(int M,struct node *graph[]){
	printf("Printing Graph\n");
	for(int i=0;i<M;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->cid);
			head=head->next;
		}
	}
}


//at max O(m^2) if every city is connected to every other)
void get_all_path(int *paths,int len,int k,int pid,int cid,int M,int visited[],struct node *graph[]){
	printf("%d %d %d %d\n",pid,cid,len,*paths);
	//handling the base case
	if(len<=k && pid==cid){
		*paths+=1;
		//return; 
		//dotn return cuz there could be loop on final path also
	}
	if(len>k || graph[pid]==NULL || visited[pid]==1){
		return;
	}

	//recursive step
	visited[pid]=1;
	struct node *head=graph[pid];
	while(head!=NULL){
		get_all_path(paths,len+1,k,head->cid,cid,M,visited,graph);
		head=head->next;
	}
	visited[pid]=0;
	//so that this sub path could be used in other paths also
}