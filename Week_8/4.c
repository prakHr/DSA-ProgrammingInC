#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node{
	int val;
	int cid;
	struct node *next;
};
void add_node(int pid,int cid,int val,struct node *graph[]);
void print_graph(int M,struct node *graph[]);
int detect_negetive_cycle(int cost,int pid,int visited[][2],struct node *graph[]);

int main(){
	int M;
	scanf("%d",&M);
	int adj[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf(" %d",&adj[i][j]);
		}
		adj[i][i]=0;	//removing the self-loop on any possible start
	}
	//making the "adj-list" graph O(m^3)
	printf("Building Graph\n");
	struct node *graph[M];
	for(int i=0;i<M;i++){
		graph[i]=NULL;
		for(int j=0;j<M;j++){
			if(adj[i][j]!=0){//0 being our no path pointer
				add_node(i,j,adj[i][j],graph);
			}
		}
	}
	printf("Printing Graph\n");
	print_graph(M,graph);

	//Finding the cycle with negetive gradient loop
	int flag=0;
	int visited[M][2];
	for(int j=0;j<M;j++){
		visited[j][0]=0;	//for checking if visited
		visited[j][1]=0;	//to keep track of cost last time it was visited
	}
	for(int i=0;i<M && flag==0;i++){//O(M^3)
		//int visited[M][2];
		int cost=0;
		// for(int j=0;j<M;j++){
		// 	visited[j][0]=0;	//for checking if visited
		// 	visited[j][1]=0;	//to keep track of cost last time it was visited
		// }
		flag=detect_negetive_cycle(cost,i,visited,graph);
		printf("InfLoop Possibility: %d %d\n",i,flag);
	}
	printf("InfLoop Possibility: %d\n",flag);

	return 0;
}

//could be reduced to O(1) just add at the begining. 
//like in new version of hash function we used in week9
void add_node(int pid,int cid,int val,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->cid=cid;
	temp->val=val;
	temp->next=NULL;

	struct node *head=graph[pid];
	if(head==NULL){
		graph[pid]=temp;
		return;
	}
	while(head->next!=NULL){//will run at max O(M) for each addn
		head=head->next;
	}
	head->next=temp;
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

//at max O(m^2) if every city is connected to every other
int detect_negetive_cycle(int cost,int pid,int visited[][2],struct node *graph[]){
	//the cost is cost incurred till now
	printf("print: %d %d %d\n",pid,cost,visited[pid][1]);
	//Handling the base case
	if(visited[pid][0]==1){
		//checking if there is negetive gradient
		if(cost<visited[pid][1]){
			return 1;
		}
		return 0;
	}
	else if(graph[pid]==NULL){//end of graph
		return 0;
	}

	struct node *head=graph[pid];
	visited[pid][0]=1;
	visited[pid][1]=cost;
	while(head!=NULL){
		int tcost=cost+head->val;
		int flag=detect_negetive_cycle(tcost,head->cid,visited,graph);
		head=head->next;
		if(flag==1){
			return 1;
		}
	}
	//visited[pid][0]=0; //now as this is already travelled and 
	//given sign if negetive cycle is there or not then not need
	//to travel this again so keep it flagged non zero
	return 0;
}

