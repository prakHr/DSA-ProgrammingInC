#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int cid;
	struct node *next;
};
struct stak{
	int cid;
	struct stak *prev;
};
void add_node(int cid,int pid,struct node *graph[]);
struct stak * push(int cid,struct stak *tos);
struct stak *pop(struct stak *tos);
void print_graph(int N,struct node *graph[]);

int main(){
	int N,E;
	scanf("%d %d",&N,&E);
	struct node *graph[N];
	for(int i=0;i<N;i++){
		graph[i]=NULL;
	}
	for(int i=0;i<E;i++){
		int pid,cid;
		scanf(" %d %d",&pid,&cid);
		add_node(cid,pid,graph);
	}
	print_graph(N,graph);

	//now spreading the bankegiri
	int count=1;//to label the nodes
	int visited[N];
	for(int i=0;i<N;i++){
		visited[i]=0;
	}
	for(int i=0;i<N;i++){
		int pid=i;
		struct node *head=graph[pid];
		while(visited[pid]==0 && head!=NULL){
			

		}
	}

	return 0;
}

void add_node(int cid,int pid,struct node *graph[]){
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
struct stak * push(int cid,struct stak *tos){
	struct stak *temp=(struct stak *)malloc(sizeof(struct stak));
	temp->cid=cid;
	temp->prev=tos;
	return temp;
}
struct stak *pop(struct stak *tos){
	struct stak *temp=tos->prev;
	free(tos);
	return temp;
}
void print_graph(int N,struct node *graph[]){
	printf("Prinintg the graph\n");
	for(int i=0;i<N;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->cid);
			head=head->next;
		}
	}
	printf("Done Printing\n");
}


//making the graph undirected will be same as in case of
//undirected. but it will easy in undirected. so do it.
//or lite