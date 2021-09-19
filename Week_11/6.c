#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define max 100
void dfs(int m,int n,int o,char str1[],char str2[],char str3[],int len2,int len3,int dp[][len2][len3]);

int main(){
	char str1[max];
	char str2[max];
	char str3[max];
	scanf("%[^\n]s",str1);
	scanf(" %[^\n]s",str2);
	scanf(" %[^\n]s",str3);

	int len1=strlen(str1);
	int len2=strlen(str2);
	int len3=strlen(str3);

	int dp[len1][len2][len3];
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			for(int k=0;k<len3;k++){
				dp[i][j][k]=-1;//not solved
				//printf("%d %d %d\n",i,j,k);
			}
		}
	}
	//printf("%d %d %d\n",len1,len2,len3);
	dfs(len1-1,len2-1,len3-1,str1,str2,str3,len2,len3,dp);
	printf("The maximal length: %d\n",dp[len1-1][len2-1][len3-1]);

	return 0;
}

void dfs(int m,int n,int o,char str1[],char str2[],char str3[],int len2,int len3,int dp[][len2][len3]){
	//handling the base case
	if(m==0){
		//printf("hm\n");
		int flag1=0,flag2=0;
		for(int i=0;i<=n;i++){
			if(str1[m]==str2[i]){
				flag1=1;
				break;
			}
		}
		for(int i=0;i<=o;i++){
			if(str1[m]==str3[i]){
				flag2=1;
				break;
			}
		}
		dp[m][n][o]=flag1*flag2;
		return;
	}
	else if(n==0){
		//printf("hn\n");
		int flag1=0,flag2=0;
		for(int i=0;i<=m;i++){
			if(str2[n]==str1[i]){
				flag1=1;
				break;
			}
		}
		for(int i=0;i<=o;i++){
			if(str2[n]==str3[i]){
				flag2=1;
				break;
			}
		}
		dp[m][n][o]=flag1*flag2;
		return;
	}
	else if(o==0){
		int flag1=0,flag2=0;
		for(int i=0;i<=m;i++){
			if(str1[i]==str3[o]){
				flag1=1;
				break;
			}
		}
		for(int i=0;i<=n;i++){
			if(str2[i]==str3[o]){
				flag2=1;
				break;
			}
		}
		dp[m][n][o]=flag1*flag2;
		return;
	}

	//now conbining them together to get optimal for current step
	int max_len=-1;
	//CASE1:
	if(str1[m]==str2[n] && str2[n]==str3[o]){
		if(dp[m-1][n-1][o-1]==-1){
			//printf("Case1: %d %d %d\n",m-1,n-1,o-1);
			dfs(m-1,n-1,o-1,str1,str2,str3,len2,len3,dp);
		}
		max_len=dp[m-1][n-1][o-1]+1;
	}
	else{
		if(dp[m][n][o-1]==-1){
			//printf("Case2: %d %d %d\n",m,n,o-1);
			dfs(m,n,o-1,str1,str2,str3,len2,len3,dp);
		}
		if(dp[m-1][n][o]==-1){
			//printf("Case2: %d %d %d\n",m-1,n,o);
			dfs(m-1,n,o,str1,str2,str3,len2,len3,dp);
		}
		if(dp[m][n-1][o]==-1){
			//printf("Case2: %d %d %d\n",m,n-1,o);
			dfs(m,n-1,o,str1,str2,str3,len2,len3,dp);
		}
		int temp[3];
		temp[0]=dp[m][n][o-1];
		temp[1]=dp[m-1][n][o];
		temp[2]=dp[m][n-1][o];

		for(int i=0;i<3;i++){
			if(temp[i]>max_len){
				max_len=temp[i];
			}
		}
	}
	dp[m][n][o]=max_len;
}