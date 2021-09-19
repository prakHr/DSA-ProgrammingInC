#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node{
	int wt;
	struct node *next;
};
void add_node(int wt,int col,struct node *stone[]);
void print_node(int M,struct node *stone[]);
void dfs(int m,int x,int X,int dp[][X+1],struct node *stone[]);

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int N,M,X;
		scanf(" %d %d %d",&N,&M,&X);
		int wt[N];
		for(int i=0;i<N;i++){
			scanf(" %d",&wt[i]);
		}
		
		//creating the groups based on color
		struct node *stone[M];
		for(int i=0;i<M;i++){
			stone[i]=NULL;
		}
		for(int i=0;i<N;i++){
			int col;
			scanf(" %d",&col);
			add_node(wt[i],col-1,stone);
		}
		//print_node(M,stone);

		//Initializing the dp matrix;
		int dp[N][X+1]; //including zero
		for(int i=0;i<N;i++){
			for(int j=0;j<X+1;j++){
				dp[i][j]=-1;//not solved
			}
		}
		dfs(M-1,X,X,dp,stone);
		printf("\nPrinting dp\n");
		for(int i=0;i<M;i++){
			for(int j=0;j<X+1;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		printf("Max carrying capacity: %d\n",dp[M-1][X]);
	}
	return 0;
}

void add_node(int wt,int col,struct node *stone[]){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->wt=wt;
	temp->next=stone[col];
	stone[col]=temp;
}
void print_node(int M,struct node *stone[]){
	printf("Printing the stones\n");
	for(int i=0;i<M;i++){
		struct node *head=stone[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->wt);
			head=head->next;
		}
	}
}
//we are going top-down approach
void dfs(int m,int x,int X,int dp[][X+1],struct node *stone[]){
	//m:	which color we are choosing
	//x:	capacity left with us

	//Handling the base case
	if(m==0){
		struct node *head=stone[m];
		int max_weight=0;//means we cant take it.
		while(head!=NULL){
			int wt=head->wt;
			if(x-wt>=0 && wt>max_weight){
				max_weight=wt;
			}
			head=head->next;
		}
		dp[m][x]=max_weight;
		return;
	}

	//now instead of N elements we have M bags from which one to pick
	struct node *head=stone[m];
	int max_weight=0;//if not possible
	while(head!=NULL){
		int wt=head->wt;
		if(x-wt>=0 && dp[m-1][x-wt]==-1){
			//solving if not solved first
			dfs(m-1,x-wt,X,dp,stone);
			//now finding the running max
			if(dp[m-1][x-wt]==0){//if we cant fill preiously. we cant fill now
				continue;
			}
			else if(dp[m-1][x-wt]+wt>max_weight){
				max_weight=dp[m-1][x-wt]+wt;
			}
		}
		head=head->next;
	}
	dp[m][x]=max_weight;
}