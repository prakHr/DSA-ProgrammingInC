#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100

struct node{
	//current location
	int pos;
	int count;
	int arr[MAXN];

	//the pointers
	struct node *next;
	struct node *prev;
};
//Createing Stack
struct stack{
	int p;		//parent
	int c;		//child
	int pos;	//the verticle position
	struct stack *prev;
};
struct stack * push(int p,int c,int pos,struct stack *tos);
struct stack * pop(struct stack *tos);
struct node * insert_node(int val,int pos,struct node *head);


int main(){
	int N,root_val;
	scanf("%d %d",&N,&root_val);
	int arr[N][3];
	char temp;
	for(int i=0;i<N;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
		scanf(" %c",&temp);
		arr[i][2]=temp;
	}
	//initializing the stack
	struct stack *tos=NULL;
	int pos=0;
	tos=push(MAXN,root_val,pos,tos);

	//initializing the verticle list
	struct node *head=NULL;
	head=insert_node(root_val,pos,head);
	
	//printf("%p %p\n\n",tos,head);
	//iterating over all edges
	for(int i=0;i<N;i++){
		int p=arr[i][0];
		int c=arr[i][1];
		//printf("%p tosc:%d p:%d c:%d\n",tos,tos->c,p,c);
		if(p==tos->c){
			//printf("pushing ");
			if(arr[i][2]==76){
				pos=pos-1;
			}
			else{
				pos=pos+1;
			}
			tos=push(p,c,pos,tos);
			//printf("pos: %d c:%d %p\n",pos,c,head);
			head=insert_node(c,pos,head);
			//printf("%p\n\n",head);
		}
		else{
			//printf("poppping ");
			while(p!=tos->c){
				tos=pop(tos);
				if(tos->pos>head->pos){
					head=head->next;
				}
				else{
					head=head->prev;
				}
			}
			pos=tos->pos;
			if(arr[i][2]==76){
				pos=pos-1;
			}
			else{
				pos=pos+1;
			}
			//printf("%p \n",tos);
			tos=push(p,c,pos,tos);
			//printf("pos: %d c:%d %p\n",pos,c,head);
			head=insert_node(c,pos,head);
			//printf("%p\n\n",head);
		}
	}
	while(head->prev!=NULL){
		head=head->prev;
	}
	//printf("bazinga!! %p\n",head);

	int label=65;
	while(head!=NULL && label<=90){
		printf("%c ",label);
		//printf("%d %d\n",head->pos,head->count);
		for(int i=0;i<head->count;i++){
			printf("%d ",head->arr[i]);
		}
		printf("\n");
		head=head->next;
		label+=1;
	}

	return 0;
}

struct stack * push(int p,int c,int pos,struct stack *tos){
	struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
	temp->p=p;
	temp->c=c;
	temp->pos=pos;
	temp->prev=tos;
	return temp;
}
struct stack * pop(struct stack *tos){
	struct stack * temp=tos->prev;
	free(tos);
	return temp;
}

struct node * insert_node(int val,int pos,struct node *head){
	int flag=0;
	if(head!=NULL){
		if(pos<head->pos && head->prev!=NULL){
			head=head->prev;
			flag=1;
		}
		else if(pos>head->pos && head->next!=NULL){
			head=head->next;
			flag=1;
		}
	}
	
	if(flag==1){
		//printf("inserting\n");
		head->arr[head->count]=val;
		head->count++;
	}
	else{
		//printf("creating new\n");
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->pos=pos;
		temp->arr[0]=val;
		temp->count=1;
		temp->next=NULL;
		temp->prev=NULL;
		if(head!=NULL){
			if(head->pos>pos){
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
			}
			else if(head->pos<pos){
				temp->prev=head;
				head->next=temp;
				temp->next=NULL;
			}
		}
		head=temp;
	}
	return head;
}

