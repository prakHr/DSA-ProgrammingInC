#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int check_conflict(int x,int y,int N,int arr[][N]);
int backtrack_my_queen(int row,int N,int arr[][N]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			arr[i][j]=0;
		}
	}
	backtrack_my_queen(0,N,arr);
	return 0;
}
int check_conflict(int x,int y,int N,int arr[][N]){
	//initially we have not put anything
	//check horizontal
	for(int i=0;i<N;i++){
		if(arr[x][i]==1){
			return 1;//conflict
		}
	}

	//checking verticle
	for(int i=0;i<N;i++){
		if(arr[i][y]==1){
			return 1;
		}
	}

	//checking digonal 1
	for(int i=1; x-i>=0 && y+i<N; i++){
		if(arr[x-i][y+i]==1){
			return 1;
		}
	}
	for(int i=1; x+i<N && y-i>=0; i++){
		if(arr[x+i][y-i]==1){
			return 1;
		}
	}

	//checking the digonal 2
	for(int i=1; x-i>=0 && y-i>=0; i++){
		if(arr[x-i][y-i]==1){
			return 1;
		}
	}
	for(int i=1; x+i<N && y+i<N; i++){
		if(arr[x+i][y+i]==1){
			return 1;
		}
	}

	//now if until now everything is fine then update
	//arr[x][y]=1;
	return 0; //no conflict
}

//here backtracking means that we are not naively 
//searching while depth.
//whenever a row is not posssible to have queen 
//we dont search furthur
int backtrack_my_queen(int row,int N,int arr[][N]){
	if(row>=N){
		printf("Found the solution\n");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		return 1;
	}


	for(int i=0;i<N;i++){
		int flag=check_conflict(row,i,N,arr);
		int done=0;
		//printf("r:%d c:%d fl:%d\n",row,i,flag);
		if(flag==0){
			arr[row][i]=1;
			done=backtrack_my_queen(row+1,N,arr);
			arr[row][i]=0;
		}
		//printf("\n");
		if(done==1){
			return 1;
		}
	}
	return 0;
}

