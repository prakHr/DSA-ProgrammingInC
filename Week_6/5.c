#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *back;
};
struct node * push_stack(int val,struct node *tos);
struct node * pop_stack(struct node *tos);

int main(){
	struct node *tos=NULL;
	struct node *tos2=NULL;
	while(1){
		int choice;
		scanf(" %d",&choice);
		if(choice==1){
			int val;
			scanf(" %d",&val);
			printf("Pushing to Stack: %d\n",val);
			tos=push_stack(val,tos);
		}
		else if(choice==2){
			if(tos==NULL){
				printf("Dequeue not possible\n");
				continue;
			}
			while(tos->back!=NULL){
				tos2=push_stack(tos->val,tos2);
				tos=pop_stack(tos);
			}
			printf("Dequed: %d\n",tos->val);
			tos=pop_stack(tos);
			while(tos2!=NULL){
				tos=push_stack(tos2->val,tos);
				tos2=pop_stack(tos2);
			}
		}
		else if(choice==3){
			struct node *temp=tos;
			while(temp!=NULL){
				printf("Stack1: %d\n",temp->val);
				temp=temp->back;
			}
			temp=tos2;
			while(temp!=NULL){
				printf("Stack2: %d\n",temp->val);
				temp=temp->back;
			}
		}
	}
	return 0;
}

struct node * push_stack(int val,struct node *tos){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->back=tos;
	return temp;
}
struct node * pop_stack(struct node *tos){
	struct node *temp=tos->back;
	free(tos);
	return temp;
}