#include <stdio.h>
#include <math.h> //pow
#include <string.h>
#include <stdlib.h> //abs,malloc

void go_greedy(int min,int A[],int B[],int C[]);

int main(){
	int n;
	scanf("%d",&n);
	int arr[3][n];
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	int a_k=arr[0][0];
	int b_k=arr[1][0];
	int c_k=arr[2][0];
	int min=a_k+b_k+c_k;
	for(int i=1;i<n;i++){
		int a=arr[0][i];
		int b=arr[1][i];
		int c=arr[2][i];

		int A[2]={a_k,a};
		int B[2]={b_k,b};
		int C[2]={c_k,c};

		go_greedy(min,A,B,C);
		a_k=A[0];
		b_k=B[0];
		c_k=C[0];
	}
	printf("a_val:%d\n",a_k);
	printf("b_val:%d\n",b_k);
	printf("c_val:%d\n",c_k);
	return 0;
}

void go_greedy(int min,int A[],int B[],int C[]){
	int a_k=A[0];
	int b_k=B[0];
	int c_k=C[0];

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				int sum=abs(A[i]-B[j])+abs(A[i]-C[k])
						+abs(B[i]-C[k]);
				if(sum<min){
					min=sum;
					a_k=A[i];
					b_k=B[j];
					c_k=C[k];
				}
			}
		}
	}
	A[0]=a_k;
	B[0]=b_k;
	C[0]=c_k;
}