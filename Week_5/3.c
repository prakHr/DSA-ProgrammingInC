#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int find_maxIn_Col(int n,int m,int col,int mat[][m]);

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int mat[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %d",&mat[i][j]);
		}
	}

	int low=0;
	int high=m-1;
	int mid;
	int max_id;
	while(low<high){
		mid=(high+low)/2;
		max_id=find_maxIn_Col(n,m,mid,mat);
		//if we reach last column by this prrocess then this means that the side col
		//is low and nothing to check at tother end so its max is max
		if(mid==0 || mid==n-1){
			break;
		}
		//if we get the correct answer
		if(mat[max_id][mid]>=mat[max_id][mid-1] 
			&& mat[max_id][mid]>=mat[max_id][mid+1]){
			break;
		}

		else if(mat[max_id][mid-1]>=mat[max_id][mid]){
			high=mid-1;
		}
		else if(mat[max_id][mid+1]>=mat[max_id][mid]){
			low=mid+1;
		}
	}

	printf("MAX:%d\n",mat[max_id][mid]);

	
	return 0;
}

int find_maxIn_Col(int n,int m,int col,int mat[][m]){
	int max_id;
	int max;
	for(int i=0;i<n;i++){
		if(i==0){
			max=mat[i][col];
			max_id=i;
		}
		else if(mat[i][col]>max){
			max=mat[i][col];
			max_id=i;
		}
	}
	return max_id;
}