#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max=100000
struct node{
	int p;
	int c;
	struct node *prev;
};

int main(){
	int m,rval;
	scanf("%d %d",&m,&rval);
	int arr[m][3];
	char temp;
	for(int i=0;i<m;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
		scanf(" %c",&temp);
		if(temp=='L'){
			arr[i][2]=-1;
		}
		else{
			arr[i][2]=1;
		}
	}

	struct node *tos=NULL;
	tos=push(max,rval,tos);
	int height=0,hflag=1;
	for(int i=0;i<m;i++){
		int p=arr[i][0];
		int c=arr[i][1];
		if(p==tos->c){
			tos=push(p,c,tos);
			if(hflag==1){
				height++;
			}
		}
		else{
			hflag=0;
			
		}
	}

	return 0;
}

struct node * push(int p,int c,struct node *tos){
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->p=p;
	temp->c=c;
	temp->prev=tos;
	return temp;
}

struct node * pop(struct node *tos){
	struct node *temp=tos->prev;
	free(tos);
	return temp;
}