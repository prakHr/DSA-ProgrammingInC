#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void give_max_config(int *max,int cSum,int done[][2],int sum[][2],int n,int mat[][n]);
int sum_submat(int done[][2],int n,int mat[][n]);

int main(){
	int n;
	scanf("%d",&n);
	int mat[n][n];
	int sum[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %d",&mat[i][j]);
		}
		sum[i][0]=0;
		sum[i][1]=0;
	}
	
	int done[n][2];
	int tSum=0;//total sum, need not calcluate everytime
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum[i][0]+=mat[i][j];//for rows
			sum[i][1]+=mat[j][i];//for columns
			tSum+=mat[i][j];
		}
		done[i][0]=0;//flag for saying this row is "done" :(
		done[i][1]=0;
	}
	for(int i=0;i<n;i++){
		//printf("%d %d\n",sum[i][0],sum[i][1]);
	}
	int max=tSum;//less than worst case when all are -100 in 100by100
	printf("MAX: %d\n",max);
	give_max_config(&max,tSum,done,sum,n,mat);
	printf("MAX: %d\n",max);
	return 0;
}

void give_max_config(int *max,int cSum,int done[][2],int sum[][2],int n,int mat[][n]){
	//printf("DEPTH CHANGE\n");
	for(int i=0;i<n;i++){//redundancy will be there of 1-2 then 2-1(re-later)
		if(done[i][0]!=1){
			done[i][0]=1;
			for(int j=0;j<n;j++){
				if(done[j][1]!=1){
					done[j][1]=1;
					int cSumTemp=sum_submat(done,n,mat);
					printf("i:%d j:%d cS:%d cST:%d max:%d mat:%d\n",i,j,cSum,cSumTemp,*max,mat[i][j]);
					if(cSumTemp>*max){
						*max=cSumTemp;
					}
					give_max_config(max,cSumTemp,done,sum,n,mat);
					done[i][1]=0;
					//printf("DEPTH OVER\n");
				}
			}
			done[i][0]=0;
		}
	}
}

int sum_submat(int done[][2],int n,int mat[][n]){
	int sum=0;
	for(int i=0;i<n;i++){
		if(done[i][0]!=1){
			for(int j=0;j<n;j++){
				if(done[j][1]!=1){
					sum+=mat[i][j];
				}
			}
		}
	}
	return sum;
}