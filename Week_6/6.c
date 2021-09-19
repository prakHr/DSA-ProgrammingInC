#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int val;
	struct node *next;
	struct node *prev;
};
void print_list(struct node *head);
struct node * remove_element(int pos,struct node *head);
void remove_last(struct node *head);
struct node * remove_first(struct node *head);
void insert_end(int val,struct node *head);
struct node * insert_first(int val,struct node *head);

int main(){
	struct node *head=NULL;
	while(1){
		int choice;
		scanf(" %d",&choice);
		if(choice==1){
			int val;
			scanf(" %d",&val);
			printf("Inserting at first: %d\n",val);
			head=insert_first(val,head);
			//printf("%p\n",head);
		}
		else if(choice==2){
			int val;
			scanf(" %d",&val);
			printf("Inserting at end: %d\n",val);
			insert_end(val,head);
		}
		else if(choice==3){
			int pos;
			scanf(" %d",&pos);
			head=remove_element(pos,head);
		}
		else if(choice==4){
			head=remove_first(head);
		}
		else if(choice==5){
			remove_last(head);
		}
		else if(choice==6){
			printf("Printing the List: \n");
			print_list(head);
		}
	}
	return 0;
}

struct node * insert_first(int val,struct node *head){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->prev=NULL;
	temp->next=head;
	if(head!=NULL){
		head->prev=temp;
	}
	return temp;
}
void insert_end(int val,struct node *head){
	while(head->next!=NULL){
		head=head->next;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	head->next=temp;
	temp->prev=head;
	temp->next=NULL;
}
struct node * remove_first(struct node *head){
	struct node *temp=head->next;
	temp->prev=NULL;
	free(head);
	return temp;
}
void remove_last(struct node *head){
	while(head->next!=NULL){
		head=head->next;
	}
	struct node *temp=head->prev;
	temp->next=NULL;
	free(head);
}
struct node * remove_element(int pos,struct node *head){
	int count=0;
	struct node *temp=head;
	while(count!=pos && temp!=NULL){
		temp=temp->next;
		count++;
	}
	printf("Found pos \n");
	if(temp==NULL){
		printf("NOT POSSIBLE \n");
		return head;
	}
	if(temp==head){
		printf("removing first\n");
		return remove_first(head);
	}
	else if(temp->next==NULL){
		printf("removing last\n");
		remove_last(head);
		return head;
	}
	struct node *temp2=temp->prev;
	temp2->next=temp->next;
	(temp->next)->prev=temp2;
	free(temp);
	return head;
}

void print_list(struct node *head){
	//printf("%p\n",head);
	while(head!=NULL){
		printf("LIST:%d\n",head->val);
		head=head->next;
	}
}