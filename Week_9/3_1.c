#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct node{
	int val;
	struct node *next;
};
void quick_sort(struct node **shead,struct node **stail,struct node *head);

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
			head=temp;
			tail=temp;
			printf("%p\n",tail);
			continue;
		}
		tail->next=temp;
		tail=temp;
		printf("%p\n",tail);
	}
	struct node *shead,*stail;
	quick_sort(&shead,&stail,head);
	printf("Printing the sorted Array\n");
	while(shead!=NULL){
		printf("%d\n",shead->val);
		shead=shead->next;
	}
	return 0;
}
void quick_sort(struct node **shead,struct node **stail,struct node *head){
	//end is not needed and could be found in O(n) but it will
	//reduce complexity by not finding each time
	
	//handling the base case
	if(head->next==NULL){
		*shead=head;
		*stail=head;
		return;
	}

	//handling the recursion
	struct node *pivot=head;

	struct node *lhead=NULL;
	struct node *ltail=NULL;
	struct node *rhead=NULL;
	struct node *rtail=NULL;

	// printf("Pivoting\n");
	// printf("pivot:%p\n",pivot);
	while(head->next!=NULL){
		head=head->next;
		if(head->val<pivot->val){
			if(lhead==NULL){
				lhead=head;
				ltail=head;
				continue;
			}
			ltail->next=head;
			ltail=head;
		}
		else{
			if(rhead==NULL){
				rhead=head;
				rtail=head;
				continue;
			}
			rtail->next=head;
			rtail=head;
		}
	}
	struct node *cshead;
	struct node *cstail;
	//handling the left sub problem
	if(lhead!=NULL){
		ltail->next=NULL;
		cshead=NULL;
		cstail=NULL;
		quick_sort(&cshead,&cstail,lhead);
		*shead=cshead;
		cstail->next=pivot;
	}
	else{
		*shead=pivot;
	}

	//handling the right sub problem
	if(rhead!=NULL){
		rtail->next=NULL;
		cshead=NULL;
		cstail=NULL;
		quick_sort(&cshead,&cstail,rhead);
		*stail=cstail;
		pivot->next=cshead;
	}
	else{
		*stail=pivot;
	}
}