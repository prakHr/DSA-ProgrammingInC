#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
void scan_mat(int N,int arr[][N]);
void print_mat(int N,int arr[]);

int main(){
	int N;
	scanf("%d",&N);
	int arr1[N][N];
	int arr2[N][N];
	scan_mat(N,arr1);
	scan_mat(N,arr2);
	
	return 0;
}
void scan_mat(int N,int arr[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf(" %d",&arr[i][j]);
		}
	}
}
void print_mat(int N,int arr[]){
	printf("Printing:\n")
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("Done\n");
}
void strassens_bhavah(int lo1,int hi1,int lo2,int hi2,int N1,int arr1[][N1],int N2,int arr2[][N2],int N3,int ans[][N3]){
	//handling the abse case
	if(lo1==hi1){
		ans[N3-1][N3-1]=arr1[lo1][lo1]*arr2[lo2][hi2];
		return;
	}
	

	//getting the index for "stripping"
	int l11=lo1;
	int h11=(lo1+hi1)/2;
	int l12=(lo1+hi1)/2+1;//will be used for both row and col(N should be 2^k)
	int h12=hi1;

	int l21=lo2;
	int h21=(lo2+hi2)/2;
	int l22=(lo2+hi2)/2+1;
	int l22=hi2;

	//creating the s-matrixeds
	int len=l12-l11;//both length will be same
	int add=1;
	int sub=2;

	int s1[len][len];
	mat_op(sub,l21,l22,l22,l22,arr2,arr2,len,s1);

	int s2[len][len];
	mat_op(add,l11,l11,l11,l12,arr1,arr1,len,s2);

	int s3[len][len];
	mat_op(add,l12,l11,l12,l12,arr1,arr1,len,s3);

	int s4[len][len];
	mat_op(sub,l22,l21,l21,l21,arr2,arr2,len,s4);

	int s5[len][len];
	mat_op(add,l11,l11,l12,l12,arr1,arr1,len,s5);

	int s6[len][len];
	mat_op(add,l21,l21,l22,l22,arr2,arr2,len,s6);

	int s7[len][len];
	mat_op(sub,l11,l12,l12,l12,arr1,arr1,len,s7);

	int s8[len][len];
	mat_op(add,l22,l21,l22,l22,arr2,arr2,len,s8);

	int s9[len][len];
	mat_op(sub,l11,l11,l12,l11,arr1,arr1,len,s9);

	int s10[len][len];
	mat_op(add,l21,l21,l21,l22,arr2,arr2,len,s10);

	//creating the product matrix;
	int p1[len][len];
	strassens_bhavah(l11,h11,0,len-1,N1,arr1,len,s1,len,p1);

	int p2[len][len];
	strassens_bhavah(0,len-1,l22,h22,len,s2,N2,)
}
void mat_op(int op,int l1r,int l1c,int l2r,int l2c,int N1,int arr1[][N1],int N2,int arr2[][N2],int len,int s[][len]){
	for(int i=l1r,int j=l2r,int k=0; k<len; k++,j++,i++){
		for(int l=l1c,int m=l2c,int n=0; n<len; n++,m++,l++){
			if(op==1){//for addition
				s[k][n]=arr1[i][l]+arr2[j][m];
			}
			else if(op==2){//for subtraction
				s[k][n]=arr1[i][l]-arr2[j][m];
			}
		}
	}
}
