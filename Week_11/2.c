#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

struct node{
	int cid;
	struct node *next;
};
void add_node(int cid,int pid,struct node *graph[]);
void print_graph(int N,struct node *graph[]);
void step_by_step(int *total,int pid,int cost[],int visited[],struct node *graph[]);


int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	struct node *graph[N];
	int visited[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
		graph[i]=NULL;
		visited[i]=0;
	}
	//since the tree will have N-1 edges
	for(int i=0;i<N-1;i++){
		int p,c;
		scanf(" %d %d",&p,&c);
		add_node(c-1,p-1,graph);
	}

	print_graph(N,graph);
	int total=0;
	step_by_step(&total,0,arr,visited,graph);
	printf("\ntotal:%d\n",total);
	for(int i=0;i<N;i++){
		printf("i:%d fl:%d\n",i,visited[i]);
	}
	return 0;
}
void add_node(int cid,int pid,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->cid=cid;
	temp->next=graph[pid];
	graph[pid]=temp;
}
void print_graph(int N,struct node *graph[]){
	printf("\nPrinting the graph\n");
	for(int i=0;i<N;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->cid);
			head=head->next;
		}
	}
	printf("\n");
}

//every node will be touched at max six times
void step_by_step(int *total,int pid,int cost[],int visited[],struct node *graph[]){
	//handling the base case
	if(visited[pid]==1 || visited[pid]==-1){
		struct node *head=graph[pid];
		printf("%d\n",pid);
		while(head!=NULL){
			step_by_step(total,head->cid,cost,visited,graph);
			head=head->next;
		}
		return;
	}

	//initiallizing the cost
	int pg_cost=cost[pid];
	int c_cost=0;

	struct node *head=graph[pid];
	while(head!=NULL){//at max 2
		c_cost+=cost[head->cid];
		struct node *chead=graph[head->cid];
		while(chead!=NULL){//at max 2
			pg_cost+=cost[chead->cid];
			chead=chead->next;
		}
		head=head->next;
	}

	printf("%d %d %d\n",pid,pg_cost,c_cost);
	//selecting the level
	if(pg_cost>c_cost){
		visited[pid]=1;
		*total+=cost[pid];
		head=graph[pid];
		while(head!=NULL){
			visited[head->cid]=-1;//dont take them.
			head=head->next;
		}
	}
	else{
		visited[pid]=-1;
		head=graph[pid];
		c_cost=0;
		while(head!=NULL){
			c_cost+=cost[head->cid];
			visited[head->cid]=1;//take them.
			struct node *chead=graph[head->cid];
			while(chead!=NULL){
				visited[chead->cid]=-1;//dont take the grand parents
				chead=chead->next;
			}
			head=head->next;
		}
		*total+=c_cost;
	}

	//now dividing the problem.structure is similar to the
	//previous problem
	head=graph[pid];
	while(head!=NULL){
		step_by_step(total,head->cid,cost,visited,graph);
		head=head->next;
	}
}