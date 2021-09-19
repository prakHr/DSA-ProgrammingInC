#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


void dfs(int i,int j,int N,int col[],int dp[][N][2]);

int main(){
	int N;
	scanf(" %d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}

	//initializing the dp matrix;
	int dp[N][N][2];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dp[i][j][0]=-1;//this dimension is cost incurred for mixing
			dp[i][j][1]=-1;//this dimension of new color produced
		}
		dp[i][i][0]=arr[i];
		dp[i][i][1]=arr[i];
	}
	dfs(0,N-1,N,arr,dp);
	printf("Min cost incurred: %d\n",dp[0][N-1][0]);
	return 0;
}

void dfs(int i,int j,int N,int col[],int dp[][N][2]){
	//handling the base case
	if(j==i+1){//only two consecutive
		dp[i][j][0]=col[i]*col[j];
		dp[i][j][1]=(col[i]+col[j])%100;
		return;
	}

	//iterating to generate all possible two problem division of whole length
	int min_cost=INT_MAX;
	int min_color=0;
	for(int k=i+1;k<j;k++){//moving the end pointer
		//solving the problem if not solved
		printf("%d %d %d %d\n",i,k,k+1,j);
		if(dp[i][k][0]==-1){
			dfs(i,k,N,col,dp);
		}
		if(dp[k+1][j][0]==-1){
			dfs(k+1,j,N,col,dp);
		}

		//calculating the current cost
		int cost=dp[i][k][0]//for subproblem
					+dp[i][k][1]*dp[k+1][j][1];//for mixing them finally
		if(k+1!=j){
			cost+=dp[k+1][j][0];
		}
		

		if(cost<min_cost){
			min_cost=cost;
			min_color=(dp[i][k][1]+dp[k+1][j][1])%100;
		}
	}
	dp[i][j][0]=min_cost;
	dp[i][j][1]=min_color;
}