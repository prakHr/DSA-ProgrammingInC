#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int val;
	struct node *next;
};
struct node * insert_element(int val,struct node *tail);
void print_list(struct node *head);
void swap_pairwise(struct node *head);

int main(){
	struct node *head=NULL;
	struct node *tail=NULL;
	for(int i=0;i<9;i++){
		int val=i;
		tail=insert_element(val,tail);
		if(head==NULL){
			head=tail;
		}
	}
	print_list(head);
	swap_pairwise(head);
	print_list(head);
	return 0;
}
struct node * insert_element(int val,struct node *tail){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
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
void swap_pairwise(struct node *head){
	while(head!=NULL && head->next!=NULL){
		int val=head->val;
		head->val=(head->next)->val;
		(head->next)->val=val;

		head=(head->next)->next;
	}
}