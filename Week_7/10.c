#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 10000000
void print_adjacency_matrix(int N,int arr[][N]);
int get_weights(int N,int arr[][N]);

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int arr[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			arr[i][j]=max;		//symbol for no connection
		}
	}
	for(int i=0;i<M;i++){
		int from,to,val;
		scanf(" %d %d %d",&from,&to,&val);
		if(from==to){
			continue;			//dont take those edges
		}
		arr[from-1][to-1]=val;
		arr[to-1][from-1]=val;// the node is undirected
	}
	//printf("printing adj-list\n");
	print_adjacency_matrix(N,arr);
	int sum=get_weights(N,arr);
	printf("SUM:%d\n",sum);
	return 0;
}

int get_weights(int N,int arr[][N]){
	int vtook[N];
	vtook[0]=1; 	//one hot vector to represent if the number is taken or not
	for(int i=1;i<N;i++){
		vtook[i]=0;
	}

	//selecting the edges for all vertexes
	int sum=0;
	int count=0; 	//use the general property of tree
	while(count!=N-1){
		int min_val=max;
		int to=-1;
		for(int i=0;i<N;i++){
			if(vtook[i]!=1){
				continue;
			}
			for(int j=0;j<N;j++){
				if(vtook[j]!=1 && arr[i][j]<min_val){
					min_val=arr[i][j];
					to=j;
				}
			}
		}
		printf("node:%d val:%d\n",to,min_val);
		vtook[to]=1;
		sum+=min_val;
		count++;
	}
	return sum;
}

void print_adjacency_matrix(int N,int arr[][N]){
	for(int i=0;i<N;i++){
		printf("[ ");
		for(int j=0;j<N;j++){
			printf("%d ",arr[i][j]);
		}
		printf("]\n");
	}
}


