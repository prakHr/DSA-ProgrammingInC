#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int m,p;
	scanf("%d %d",&m,&p);
	int A[m][p];
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			scanf(" %d",&A[i][j]);
		}
	}
	int n;
	scanf(" %d %d",&p,&n);
	int B[p][n];
	for(int i=0;i<p;i++){
		for(int j=0;j<n;j++){
			scanf(" %d",&B[i][j]);
		}
	}

	int sum=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<p;k++){
				sum+=A[i][k]*B[k][j];
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}