#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int cid;
	struct node *next;
};
void add_node(int cid,int pid,struct node *graph[]);
void dfs(int pid,int dp[][2],int val[],struct node *graph[]);

int main(){
	int N;
	scanf("%d",&N);
	int val[N];
	struct node *graph[N];
	int dp[N][2];//for storing the solution of all the nodes

	for(int i=0;i<N;i++){
		scanf(" %d",&val[i]);
		graph[i]=NULL;
		dp[i][0]=dp[i][1]=0;
	}
	for(int i=0;i<N-1;i++){
		int pid,cid;
		scanf(" %d %d",&pid,&cid);
		add_node(cid-1,pid-1,graph);
	}
	
	int root=0;
	dfs(root,dp,val,graph);
	if(dp[root][0]>dp[root][1]){
		printf("Answer:%d\n",dp[root][0]);
	}
	else{
		printf("Answer:%d\n",dp[root][1]);
	}
	return 0;
}
void add_node(int cid,int pid,struct node *graph[]){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->cid=cid;
	temp->next=graph[pid];
	graph[pid]=temp;
}

//we are going bottom up approach
void dfs(int pid,int dp[][2],int val[],struct node *graph[]){
	//handling the base case
	if(graph[pid]==NULL){//we have reached our last node
		dp[pid][0]=0;
		dp[pid][1]=val[pid];
		return;
	}

	//Recursively solving the smallar sub-problem
	int c1=graph[pid]->cid;
	int c2=(graph[pid]->next)->cid;
	dfs(c1,dp,val,graph);
	dfs(c2,dp,val,graph);

	//Now since the problem is solved Merging them by using them
	//Case 1: when this current node is not taken
	dp[pid][0]=dp[c1][1]+dp[c2][1];

	//Case 2: when this current node is taken
	dp[pid][1]=dp[c1][0]+dp[c2][0]+val[pid];
}