#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct node{
	int val;
	struct node *next;
};

struct node * insert_node(int val,struct node *tail);
void print_list(struct node *head);
int check_in_line(struct node *head,struct node *now);
int detect_cycle(struct node *head);

int main(){
	srand(0);
	int N=10;
	int cycle_pos=rand()%(N-1);
	int choice;
	scanf("%d",&choice);
	struct node *tail=NULL;
	struct node *head=NULL;
	struct node *cycle_node;
	for(int i=0;i<N;i++){
		int val=i;
		tail=insert_node(val,tail);
		if(head==NULL){
			head=tail;
		}
		if(i==cycle_pos){
			cycle_node=tail;
		}
	}
	print_list(head);
	if(choice==1){
		tail->next=cycle_node;//cycle created
	}
	//print_list(head);
	int cycle=detect_cycle(head);
	printf("Cycle %d\n",cycle);

	return 0;
}

struct node * insert_node(int val,struct node *tail){
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

int detect_cycle(struct node *head){
	struct node *head2=head;
	int flag=0;
	while(head!=NULL && flag==0){
		flag=check_in_line(head2,head);
		head=head->next;
	}
	return flag;
}
int check_in_line(struct node *head,struct node *now){
	int flag=0;
	if(now->next==now){
		return 1;
	}
	while(head!=now){
		if(head==now->next){
			flag=1;
			break;
		}
		head=head->next;
	}
	return flag;
}