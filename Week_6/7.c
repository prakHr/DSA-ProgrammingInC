#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int val;
	struct node *next;
	struct node *prev;
};
struct node * insert_node(int val,struct node *tail);
void print_list(struct node *head);
struct node * get_tail(struct node *head);
void reverse_list_iteratively(struct node *head);
void reverse_list_recursively(struct node *head,struct node *tail);

int main(){
	srand(0);
	struct node *head=NULL;
	struct node *tail=NULL;

	for(int i=0;i<10;i++){
		//int val=rand()%10;
		int val=i;
		tail=insert_node(val,tail);
		if(head==NULL){
			head=tail;
		}
	}
	print_list(head);
	reverse_list_iteratively(head);
	printf("REVERSED:\n");
	print_list(head);
	reverse_list_recursively(head,tail);
	printf("REVERSED:\n");
	print_list(head);
	return 0;
}

struct node * insert_node(int val,struct node *tail){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	temp->prev=tail;
	if(tail!=NULL){
		tail->next=temp;
	}
	return temp;
}
void print_list(struct node *head){
	while(head!=NULL){
		printf("LIST: %d\n",head->val);
		head=head->next;
	}
}

struct node * get_tail(struct node *head){
	while(head->next!=NULL){
		head=head->next;
	}
	return head;//appearence are deceptive
}

void reverse_list_iteratively(struct node *head){
	struct node *tail=get_tail(head);
	while(head!=tail && head->prev!=tail){
		int temp=head->val;
		head->val=tail->val;
		tail->val=temp;
		
		head=head->next;
		tail=tail->prev;
	}
}

void reverse_list_recursively(struct node *head,struct node *tail){
	if(head==tail || head->prev==tail){
		return;
	}
	int temp=head->val;
	head->val=tail->val;
	tail->val=temp;

	head=head->next;
	tail=tail->prev;
	reverse_list_recursively(head,tail);
}