#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int val; //1:T -1:F(relation with the node)
	int cid;
	struct node *next;
};
void add_node(int val,int cid,int pid,struct node *graph[]);
void print_graph(int N,struct node *graph[]);
int detect_paradoxical_cycle(int pval,int pid,int cid,int visited[][3],struct node *graph[]);


int main(){
	int N;
	scanf("%d",&N);
	while(N!=0){
		//Building the graph
		struct node *graph[N];
		for(int i=0;i<N;i++){
			int cid,val;//false:-1 true:1
			scanf(" %d %d",&cid,&val);
			graph[i]=NULL;
			add_node(val,cid-1,i,graph);
		}
		print_graph(N,graph);

		//traversing the graph and finding paradoxical cycle
		//starting from everywhere, cuz the edges will be directed
		int visited[N][3];
		int flag=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				visited[j][0]=0;
				visited[j][1]=0;
				visited[j][2]=0;
			}
			flag=detect_paradoxical_cycle(-1,-1,i,visited,graph);
			printf("%d %d\n",i,flag);
		}
		if(flag==1){
			printf("PARA\n");
		}
		else{
			printf("NOT PARA\n");
		}
		//Rescanning for other test cases
		scanf(" %d",&N);
		printf("\n\n");
	}
	return 0;
}

void add_node(int val,int cid,int pid,struct node *graph[]){
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
	printf("Printing Graph\n");
	for(int i=0;i<N;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d %d\n",i,head->cid,head->val);
			head=head->next;
		}
	}
	printf("DONE\n");
}

int detect_paradoxical_cycle(int pval,int pid,int cid,int visited[][3],struct node *graph[]){
	/* pval: relation ship of parent with current child
		pid is  fathers id (-1 for starting the traversal)
	*/
	//handling the base cases
	if(visited[cid][0]==1 && pid!=-1){
		int cs1=visited[pid][1]*pval;
		//int cs2=visited[pid][2]*pval;
		if(visited[cid][1]!=cs1){//comparing one is enough
			return 1;
		}
		else{
			return 0;
		}
	}
	//have to remember cuz graph could come from other pahce
	//to this node and still they have to mathc. like the \/ structure
	//in Dapne
	//(updating the current setting)
	if(pid!=-1){
		int cs1=visited[pid][1]*pval;
		int cs2=visited[pid][2]*pval;
		visited[cid][0]=1;
		visited[cid][1]=cs1;
		visited[cid][2]=cs2;
	}
	else{
		visited[cid][0]=1;
		visited[cid][1]=1;
		visited[cid][2]=-1;
	}
	//handling the recursion
	struct node *head=graph[cid];
	int flag=0; //no paradox
	while(head!=NULL){
		flag=detect_paradoxical_cycle(head->val,cid,head->cid,visited,graph);
		if(flag==1){
			return 1;
		}
		head=head->next;
	}
	return 0;
}