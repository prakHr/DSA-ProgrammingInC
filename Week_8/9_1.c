#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void print_adj(int N,int adj[][N]);
void rang_badlo(int N,int count,int new_count,int visited[]);

int main(){
	int N,E;
	scanf("%d %d",&N,&E);
	int adj[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			adj[i][j]=0;
		}
	}
	for(int i=0;i<E;i++){
		int to,from;
		scanf(" %d %d",&to,&from);
		adj[to-1][from-1]=1;
		adj[from-1][to-1]=1;
	}
	print_adj(N,adj);

	//now traversing the nodes to get connected comp.
	int visited[N];
	for(int i=0;i<N;i++){
		visited[i]=0;
	}
	int count=1;
	for(int i=0;i<N;i++){//O(N^3) in worst case
		if(visited[i]==0){
			visited[i]=count;
			for(int j=0;j<N;j++){
				if(adj[i][j]==1 && visited[j]==0){
					visited[i]=count;
				}
				else if(adj[i][j]==1 && visited[j]!=count){
					rang_badlo(N,count,visited[j],visited);
					count=visited[j];
				}
			}
			count++;
		}
	}
	for(int i=0;i<N;i++){
		printf("rang: %d\n",visited[i]);
	}
	return 0;
}
void print_adj(int N,int adj[][N]){
	printf("Printing the MAtrix:\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

void rang_badlo(int N,int count,int new_count,int visited[]){
	for(int i=0;i<N;i++){
		if(visited[i]==count){
			visited[i]=new_count;
		}
	}
}