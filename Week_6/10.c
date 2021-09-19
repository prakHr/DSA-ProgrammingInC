#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	struct node *prev;
};
struct node * insert_node(int val,struct node *tail);
void print_list_circle(struct node *head);
int get_position(int m,struct node *head);

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	struct node *head=NULL;
	struct node *tail=NULL;

	for(int i=0;i<n;i++){
		tail=insert_node(i+1,tail);
		if(head==NULL){
			head=tail;
		}
	}
	tail->next=head;
	head->prev=tail;
	print_list_circle(head);
	int pos=get_position(m,head);
	printf("Position: %d\n",pos);
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

void print_list_circle(struct node *head){
	struct node *temp=head->next;
	printf("LIST: %d\n",head->val);
	while(temp!=head){
		printf("LIST: %d\n",temp->val);
		temp=temp->next;
	}
}
int get_position(int m,struct node *head){
	int count=0;
	while(head->next!=head){
		if(count%m==0){
			struct node *temp=head->prev;
			temp->next=head->next;
			(head->next)->prev=temp;
			free(head);
			head=temp->next;
			count++;
			continue;
		}
		head=head->next;
		count++;
	}
	return head->val;
}