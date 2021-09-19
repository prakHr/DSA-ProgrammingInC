#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node{
	int x;
	int y;
	int dir;	//1.right 2.down 3.left 4.up
	int dflag;	//to hold the ghost status
	char tag;	//to hold the adj val at the time of entering
	struct node *prev;
};
struct node * push(int x,int y,int dir,int dflag,char tag,struct node *tos);
struct node * pop(struct node *tos);
void rasta_khojo(int sx,int sy,int N,int M,char adj[][M]);
void disapper_appear(int dflag,int N,int M,char adj[][M]);
int check_update(int *x,int *y,int dir,int N,int M,char adj[][M]);
void print_adj(int N,int M,char adj[][M]);

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	char adj[N][M];
	int sx,sy;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf(" %c",&adj[i][j]);
			if(adj[i][j]=='H'){
				sx=i;
				sy=j;
				adj[i][j]='E';
			}
		}
	}
	rasta_khojo(sx,sy,N,M,adj);

	return 0;
}

struct node * push(int x,int y,int dir,int dflag,char tag,struct node *tos){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->x=x;
	temp->y=y;
	temp->dir=dir;
	temp->dflag=dflag;	//this is the dflag at before taking decision at this state
	temp->tag=tag;
	temp->prev=tos;
	return temp;
}
struct node * pop(struct node *tos){
	struct node *temp=tos->prev;
	free(tos);
	return temp;
}

//chal beta bake
void rasta_khojo(int sx,int sy,int N,int M,char adj[][M]){

	// Travelling variables
	int dflag=0,found=-1;
	int path_len=0;
	int min_len=INT_MAX;

	//Initializing the stack
	struct node *tos=NULL;
	tos=push(sx,sy,1,dflag,adj[sx][sy],tos);

	while(tos!=NULL){
		int cx,cy;	//holding the current pos before updating
		int x=cx=tos->x;
		int y=cy=tos->y;
		int flag=check_update(&x,&y,tos->dir,N,M,adj);
		printf("cx:%d cy:%d x:%d y:%d dir:%d len:%c\n",cx,cy,x,y,tos->dir,tos->tag);
		
		if(flag==1){
			path_len++;
			if(x==N-1 || y==M-1 || x==0 || y==0){
				found=1;
				if(path_len<min_len){
					min_len=path_len;
				}
			}
			adj[cx][cy]='W'; //blocking the prev path

			//now handling the switch cells
			if(adj[x][y]=='D' && dflag==0){
				dflag=1;
				while(tos!=NULL && tos->tag!='A'){
					//printf("D: %c %p\n",tos->tag,tos);
					adj[tos->x][tos->y]=tos->tag;
					tos=pop(tos);
				}
				disapper_appear(dflag,N,M,adj);
			}
			else if(adj[x][y]=='A' && dflag==1){
				dflag=0;
				disapper_appear(dflag,N,M,adj);
			}

			//else do these for every case in which transition was accepted
			tos=push(x,y,1,dflag,adj[x][y],tos);
		}
		else{
			if(tos->dir<4){
				tos->dir+=1;
				continue;
			}
			else{
				path_len--;
				//adj[cx][cy]='W';//since this path is bad block it forever
				tos=pop(tos);
				if(tos!=NULL){
					dflag=tos->dflag;
					disapper_appear(dflag,N,M,adj);
					adj[tos->x][tos->y]=tos->tag; //refreshing last path
					tos->dir+=1;
				}
			}
		}
		print_adj(N,M,adj);
	}
	if(found==1){
		printf("FOUND: %d\n",min_len+1);
	}
	else{
		printf("NOT FOUND %d\n",found);
	}
}

//to remove the mosters as we have found the mantar in rasta
//wah beta banke
void disapper_appear(int dflag,int N,int M,char adj[][M]){
	//Bhutwas bhagaying
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(dflag==1 && adj[i][j]=='M'){
				adj[i][j]='m';
			}
			else if(dflag==0 && adj[i][j]=='m'){
				adj[i][j]='M';
			}
		}
	}
}

int check_update(int *x,int *y,int dir,int N,int M,char adj[][M]){
	//m is when the monsters are disappered
	if(dir==1 && *y+1<M){
		if(adj[*x][*y+1]=='E' || adj[*x][*y+1]=='m' || adj[*x][*y+1]=='D' || adj[*x][*y+1]=='A'){
			*y=*y+1;
			return 1;//update possible
		}
	}
	else if(dir==2 && *x+1<N){
		if(adj[*x+1][*y]=='E' || adj[*x+1][*y]=='m' || adj[*x+1][*y]=='D' || adj[*x+1][*y]=='A'){
			*x=*x+1;
			return 1;
		}
	}
	else if(dir==3 && *y-1>-1){
		if(adj[*x][*y-1]=='E' || adj[*x][*y-1]=='m' || adj[*x][*y-1]=='D' || adj[*x][*y-1]=='A'){
			*y-=1;
			return 1;
		}
	}
	else if(dir==4 && *x-1>-1){
		if(adj[*x-1][*y]=='E' || adj[*x-1][*y]=='m' || adj[*x-1][*y]=='D' || adj[*x-1][*y]=='A'){
			*x-=1;
			return 1;
		}
	}
	return 0;
}

void print_adj(int N,int M,char adj[][M]){
	printf("printing adj mat: \n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%c ",adj[i][j]);
		}
		printf("\n");
	}
}