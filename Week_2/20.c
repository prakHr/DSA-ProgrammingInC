#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void disinfect_horizontal(int *flag,int row,int col,int board[][8]);
void disinfect_digonals(int *flag,int row,int col,int board[][8]);

int main(){
	int board[8][8]={0};
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			scanf("%d",&board[i][j]);
		}
	}
	int flag=1;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]==1){
				flag=1;
				disinfect_horizontal(&flag,i,j,board);
				//printf("Flag: %d\n",flag);
				disinfect_digonals(&flag,i,j,board);
				if(flag==0){
					printf("%d %d\n",i,j);
					printf("NO\n");
					break;
				}
			}
		}
		if(flag==0){
			break;
		}
	}
	if(flag==1){
		printf("YES\n");
	}
	return 0;
}

//spread the virus of -1 in the queens line of attack.
//if even a single one comes next then NO.
void disinfect_horizontal(int *flag,int row,int col,int board[][8]){
	//Along the row
	for(int j=0;j<8;j++){
		if(j!=col){
			if(board[row][j]==1){
				*flag=0;
				return;
			}
		}
	}
	//along the cols
	for(int i=0;i<8;i++){
		if(i!=row){
			//board[i][col]=-1;
			if(board[i][col]==1){
				*flag=0;
				return;
			}
		}
	}
	
}

void disinfect_digonals(int *flag,int row,int col,int board[][8]){
	int ub=0,lb=0;

	//For 45 degree digonal
	int dir1=row;//row wise
	int dir2=8-col-1;//col wise
	if(dir1<dir2){
		ub=dir1;
	}
	else{
		ub=dir2;
	}

	dir1=8-row-1;
	dir2=col;
	if(dir1<dir2){
		lb=dir1;
	}
	else{
		lb=dir2;//whichever is smaller that much amount we could translate
	}
	printf("First Digonal: %d %d\n",ub,lb);
	for(int i=1;i<=ub;i++){
		printf("    upper:%d %d\n",row-i,col+i);
		if(board[row-i][col+i]==1){
			*flag=0;
			return;
		}
		//board[row+i][col+i]=-1;
	}
	for(int i=1;i<=lb;i++){
		printf("    Lower: %d %d\n",row+i,col-i);
		if(board[row+i][col-i]==1){
			*flag=0;
			return;
		}
		//board[row-i][col-i]=-1;
	}


	//For 135 degree digonal movement
	dir1=row;
	dir2=col;
	if(dir1<dir2){
		lb=dir1;
	}
	else{
		lb=dir2;
	}
	dir1=8-row-1;
	dir2=8-col-1;
	if(dir1<dir2){
		ub=dir1;
	}
	else{
		ub=dir2;
	}
	printf("Second Digonal: %d %d\n\n",ub,lb);
	for(int i=1;i<=ub;i++){
		if(board[row+i][col+i]==1){
			*flag=0;
			return;
		}
		//board[row+i][col+i]=-1;
	}
	for(int i=1;i<=lb;i++){
		if(board[row-i][col-i]==1){
			*flag=0;
			return;
		}
		//board[row-i][col-i]=-1;
	}
}