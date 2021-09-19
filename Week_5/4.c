#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void calculate_rotation(int r,int m,int n,int rot[]);
void rotate_ring_once(int idx,int m,int n,int arr[][n]);

int main(){
	int m,n,r;
	scanf("%d %d %d",&m,&n,&r);
	int arr[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf(" %d",&arr[i][j]);
		}
	}

	int num_layer; //actual upto will come(in zero indexing)
	if(m%2==0){
		num_layer=(m-1)/2;
	}
	else{
		num_layer=(n-1)/2;
	}
	int rot[num_layer+1];
	calculate_rotation(r,m,n,rot);
	for(int i=0;i<=num_layer;i++){//see division for equality ^ in num_layer
		for(int j=1;j<=rot[i];j++){
			rotate_ring_once(i,m,n,arr);
		}
	}

	printf("Printing:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void calculate_rotation(int r,int m,int n,int rot[]){
	int num_layer;
	if(m%2==0){
		num_layer=(m-1)/2;
	}
	else{
		num_layer=(n-1)/2;
	}
	for(int i=0;i<=num_layer;i++){
		int rs=i;//row start
		int re=(m-1)-i;//row end
		int cs=i;
		int ce=(n-1)-i;
		int chain_len=2*(re-rs+1);
		if(ce-cs==0){
			chain_len/=2;
		}
		else{
			chain_len+=(ce-cs-1)*2;
		}
		rot[i]=r%chain_len;
		printf("i:%d len:%d rot:%d \n",i,chain_len,rot[i]);
	}
}

void rotate_ring_once(int idx,int m,int n,int arr[][n]){
	int rs=idx;
	int re=(m-1)-idx;
	int cs=idx;
	int ce=(n-1)-idx;

	//1st rotation
	//do worst part at first. Then at last you dont have to worry.
	int carry;
	if(cs==ce){
		carry=arr[re][cs];
	}
	else{
		carry=arr[rs][cs+1];
	}
	for(int i=rs;i<=re;i++){
		int temp=arr[i][cs];
		arr[i][cs]=carry;
		carry=temp;
	}

	//2nd rotation
	for(int i=cs+1;i<=ce;i++){//automatically teke care of just one col
		int temp=arr[re][i];
		arr[re][i]=carry;
		carry=temp;
	}

	//3rd rotation
	for(int i=re-1;i>=rs;i--){//automatically take care of one row
		int temp=arr[i][ce];
		arr[i][ce]=carry;
		carry=temp;
	}

	//4th rotation
	for(int i=ce-1;i>cs;i--){
		int temp=arr[rs][i];
		arr[rs][i]=carry;
		carry=temp;
	}
}