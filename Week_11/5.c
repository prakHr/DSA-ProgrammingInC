#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max 100
void dfs(int j1,int j2,char str1[],char str2[],int len2,int dp[][len2]);

int main(){
	char str1[max],str2[max];
	scanf("%[^\n]s",str1);
	scanf(" %[^\n]s",str2);

	int len1=strlen(str1);
	int len2=strlen(str2);

	int dp[len1][len2];
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			dp[i][j]=-1;//not solved
		}
	}
	dfs(len1-1,len2-1,str1,str2,len2,dp);
	printf("Max len of Subarray: %d\n",dp[len1-1][len2-1]);
	return 0;
}

void dfs(int j1,int j2,char str1[],char str2[],int len2,int dp[][len2]){
	//handling the base case
	if(j1==0){
		int flag=0;
		for(int i=0;i<=j2;i++){
			if(str1[j1]==str2[i]){
				flag=1;
				break;
			}
		}
		dp[j1][j2]=flag;//at max length of common will be 1
		return;
	}
	else if(j2==0){
		int flag=0;
		for(int i=0;i<=j1;i++){
			if(str1[i]==str2[j2]){
				flag=1;
				break;
			}
		}
		dp[j1][j2]=flag;
		return;
	}

	//solving the unsolved problem
	if(dp[j1-1][j2]==-1){
		dfs(j1-1,j2,str1,str2,len2,dp);
	}
	if(dp[j1][j2-1]==-1){
		dfs(j1,j2-1,str1,str2,len2,dp);
	}
	if(dp[j1-1][j2-1]==-1){
		dfs(j1-1,j2-1,str1,str2,len2,dp);
	}

	//Now using the solved problem to combine current case by case
	int max_len=-1;
	//case 1: when last char is not same
	if(str1[j1]!=str2[j2]){
		if(dp[j1-1][j2]>dp[j1][j2-1]){
			max_len=dp[j1-1][j2];
		}
		else{
			max_len=dp[j1][j2-1];
		}
	}
	else{
		max_len=dp[j1-1][j2-1]+1;
	}
	dp[j1][j2]=max_len;
}