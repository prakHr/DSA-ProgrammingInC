#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define min INT_MIN

struct node{
	int val;
	int cid;			//index: for address of the children
	struct node *next;	//to hold the next children of current node
};
void add_node(int pid,int cid,int val,struct node *graph[]);
int traverse_node(int pid,struct node *graph[]);
void print_graph(int M,struct node *graph[]);

int main(){
	int M;
	scanf("%d",&M);
	int adj[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf(" %d",&adj[i][j]);
			//this will signify that there is no such path
			if(adj[i][j]==0){
				adj[i][j]=min;
			}
		}
	}
	
	//building the graph in faishon of adj list
	//at max will take O(m^3)
	printf("Building graph\n");
	struct node *graph[M];
	for(int i=0;i<M;i++){
		graph[i]=NULL;
		for(int j=0;j<M;j++){
			int weight=adj[i][j];
			if(weight!=min){
				printf("%d %d\n",i,j);
				add_node(i,j,weight,graph);
			}
		}
	}
	printf("Graph built\n");
	print_graph(M,graph);

	//now traversing the graph to find the longest length;
	int maxlen=min;
	for(int i=0;i<M;i++){//at max O(M^2)
		int len=traverse_node(i,graph);
		printf("i:%d len:%d\n",i,len);
		if(len>maxlen){
			maxlen=len;
		}
	}
	printf("MAXLEN: %d\n",maxlen);
	return 0;
}

void add_node(int pid,int cid,int val,struct node *graph[]){
	//ask meaning from swami
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->cid=cid; //conneting to the child
	temp->next=NULL;

	struct node *head=graph[pid];
	if(head==NULL){
		graph[pid]=temp;
		return;
	}
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=temp;
}

//at max O(M)~very loosely. for each node(cuz of it being tree)
int traverse_node(int pid,struct node *graph[]){
	struct node *head=graph[pid];
	if(head==NULL){
		//these will be our leaves nodes
		//which have no children
		//when there is no furthur path,no(0) contrubution
		return 0;
	}
	int len=min;
	while(head!=NULL){
		int temp_len=head->val;
		temp_len+=traverse_node(head->cid,graph);
		if(temp_len>len){
			len=temp_len;
		}
		head=head->next;
	}
	return len;
}

void print_graph(int M,struct node *graph[]){
	for(int i=0;i<M;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d %d\n",i,head->cid,head->val);
			head=head->next;
		}
	}
}