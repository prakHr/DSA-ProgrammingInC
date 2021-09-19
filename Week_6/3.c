#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int x;
	int y;
	int dir;//1:right,2:down,3:left,4:up
	struct node *back;
};
struct node * push_stack(int x,int y,struct node *tos);
struct node * pop_stack(struct node *tos);
int check_pos_update(int *x,int *y,struct node *tos,int N,int mat[][N]);
int get_come_dir(int dir);

int main(){
	int N=10;
	int mat[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf(" %d",&mat[i][j]);
		}
	}
	
	struct node *tos=(struct node*)malloc(sizeof(struct node));
	tos->x=0;
	tos->y=0;
	tos->dir=1;
	tos->back=NULL;
	int done=0;
	while(tos!=NULL){
		int k;
		//scanf(" %d",&k);
		int curr_x,curr_y;
		int x=curr_x=tos->x;
		int y=curr_y=tos->y;

		int flag=check_pos_update(&x,&y,tos,N,mat);
		if(flag==1){
			//printf("POSSIBLE\n");
			if(x==N-1 && y==N-1){
				done=1;
				break;
			}
			printf("WAY POINT: %d %d %d\n",tos->dir,x,y);
			mat[curr_x][curr_y]=0;
			tos=push_stack(x,y,tos);
			continue;
		}
		else{
			//printf("NOT POSSIBLE\n");
			if(tos->dir<4){
				//printf("Changing direction\n");
				tos->dir+=1;
				continue;
			}
			else{
				//printf("Popping\n");
				mat[x][y]=-1;
				tos=pop_stack(tos);
				if(tos!=NULL){
					mat[tos->x][tos->y]=1;
				}
				continue;
			}
		}
	}
	if(done==1){
		printf("REACHED\n");
	}
	else{
		printf("NOT REACHED\n");
	}
	return 0;
}

struct node * push_stack(int x,int y,struct node *tos){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->x=x;
	temp->y=y;
	temp->dir=1;
	temp->back=tos;
	return temp;
}
struct node * pop_stack(struct node *tos){
	struct node *temp=tos->back;
	free(tos);
	return temp;
}

int check_pos_update(int *x,int *y,struct node *tos,int N,int mat[][N]){
	if(tos->dir==2 && *x+1<N){
		if(mat[*x+1][*y]==1){
			*x=*x+1;
			return 1;
		}
	}
	else if(tos->dir==1 && *y+1<N){
		//printf("\ny_val:\n%d",*y);
		if(mat[*x][*y+1]==1){
			*y=*y+1;
			return 1;
		}
	}
	else if(tos->dir==4 && *x-1>0){
		if(mat[*x-1][*y]==1){
			*x=*x-1;
			return 1;
		}
	}
	else if(tos->dir==3 && *y-1>0){
		if(mat[*x][*y-1]==1){
			*y=*y-1;
			return 1;
		}
	}
	return 0;
}

int get_come_dir(int dir){
	if(dir==1){
		return 3;
	}
	else if(dir==2){
		return 4;
	}
	else if(dir==3){
		return 1;
	}
	else{
		return 2;
	}
}