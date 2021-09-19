#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};
struct node * enqueue(int val,struct node* tail);
struct node * dequeue(struct node* head);

int main(){
	struct node *head1=NULL,*head2=NULL;
	struct node *tail1=NULL,*tail2=NULL;
	while(1){
		int choice;
		scanf(" %d",&choice);
		if(choice==1){
			int val;
			scanf(" %d",&val);
			tail1=enqueue(val,tail1);
			if(head1==NULL){
				head1=tail1;
			}
		}
		else if(choice==2){
			if(head1==NULL){
				printf("Stack in Empty\n");
				continue;
			}
			while(head1->next!=NULL){
				tail2=enqueue(head1->val,tail2);
				if(head2==NULL){
					head2=tail2;
				}
				head1=dequeue(head1);
			}
			printf("Popping the stack %d\n",head1->val);
			head1=dequeue(head1);
			tail1=NULL;//think of better way of handling this
			while(head2!=NULL){
				tail1=enqueue(head2->val,tail1);
				if(head1==NULL){
					head1=tail1;
				}
				head2=dequeue(head2);
			}
			tail2=NULL;
		}
		else if(choice==3){
			struct node *temp=head1;
			while(temp!=NULL){
				printf("Queue1: %d\n",temp->val);
				temp=temp->next;
			}
			temp=head2;
			while(temp!=NULL){
				printf("Queue2: %d\n",temp->val);
				temp=temp->next;
			}
		}
	}
	return 0;
}

struct node * enqueue(int val,struct node* tail){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	if(tail!=NULL){
		tail->next=temp;
	}
	return temp;
}
struct node * dequeue(struct node* head){
	struct node *temp=head->next;
	free(head);
	return temp;
}