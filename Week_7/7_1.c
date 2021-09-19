#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int m,rval;
	scanf("%d %d",&m,&rval);
	int arr[m][3];
	char temp;
	for(int i=0;i<m;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
		scanf(" %c",&temp);
		if(temp=='L'){
			arr[i][2]=0;
		}
		else{
			arr[i][2]=1;
		}
	}

	//heap initialization
	int heap[m+1];
	heap[0]=rval;
	for(int i=1;i<m+1;i++){
		heap[i]=-1;
		//some sort of initialization flag to check for any conflict.
	}
	//heap[m+1]=-1;

	//checking for the possible conflict.
	int node=0;
	int p_val=rval;
	int conflict=0;
	for(int i=0;i<m && conflict==0;i++){
		int p=arr[i][0];
		int c=arr[i][1];
		int dir=arr[i][2];
		if(p<c){
			conflict=1;
			break;
		}
		if(p!=p_val){
			node++;
			p_val=p;
		}
		int loc=2*node+1+dir;
		if(loc>m){
			conflict=1;
			break;
		}
		if(heap[loc]==-1){
			heap[loc]=c;
		}
		else{
			conflict=1;
			break;
		}
	}
	if(conflict==1){
		printf("Difficult\n");
	}
	else{
		printf("Easy\n");
	}
	return 0;
}