#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node{
	int val;
	struct node *next;
};

int main(){
	int N;
	scanf("%d",&N);
	struct node *head=NULL;
	struct node *tail=NULL;
	for(int i=0;i<N;i++){
		int val;
		scanf(" %d",&val);
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->val=val;
		temp->next=NULL;
		if(head==NULL){
			tail=temp;
			head=temp;
		}
		else{
			tail->next=temp;
			tail=temp;
		}
	}
	struct node *head2=head;
	while(head2!=NULL && head2->next!=NULL){
		head=head->next;
		head2=(head2->next)->next;
	}
	
	printf("The value is: %d\n",head->val);
	return 0;
}