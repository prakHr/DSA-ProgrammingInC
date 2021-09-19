#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void dfs(int year,int s,int n,int val[],int N,int dp[][N]);

int main(){
	int N;
	scanf("%d",&N);
	int val[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&val[i]);
	}

	//Initillizing the dp varialbe
	int dp[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dp[i][j]=-1;//showing the question not solved
		}
	}

	dfs(1,0,N-1,val,N,dp);
	printf("Max Cost is: %d\n",dp[0][N-1]);
	return 0;
}

/*first we have to go to the bottom to get the soln above
and in the process we will store some result which will be
used in right half of tree*/
void dfs(int year,int s,int n,int val[],int N,int dp[][N]){
	//s: is the start e: is the end
	//printf("%d %d\n",s,n);
	//handling the base case
	if(s==n){//start==end
		dp[s][n]=year*val[s];
		return;
	}

	//Solving the smallar subproblem requrired
	if(dp[s+1][n]==-1){//solve only if not solved
		dfs(year+1,s+1,n,val,N,dp);
	}
	if(dp[s][n-1]==-1){//for right part
		dfs(year+1,s,n-1,val,N,dp);
	}

	//Case 1: when left bottle is taken
	int costL=year*val[s]+dp[s+1][n];
	//Case 2: when right bottle is taken
	int costR=year*val[n]+dp[s][n-1];

	//Combining. Solution is max cost out of two choice
	if(costL>costR){
		dp[s][n]=costL;
	}
	else{
		dp[s][n]=costR;
	}
}