#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	struct node *prev;
};
void merge_sort_klist(int lo,int hi,struct node *lon,struct node *hin);
struct node * push(int val,struct node *tail);

int main(){
	int N;
	scanf("%d",&N);
	struct node *head=NULL;
	struct node *tail=NULL;
	for(int i=0;i<N;i++){
		//printf("HI");
		int val;
		scanf(" %d",&val);
		tail=push(val,tail);
		if(head==NULL){
			head=tail;
		}
	}
	merge_sort_klist(0,N-1,head,tail);
	while(head!=NULL){
		printf("LIST: %d\n",head->val);
		head=head->next;
	}

	return 0;
}

void merge_sort_klist(int lo,int hi,struct node *lon,struct node *hin){
	//handling the base case
	if(lo>=hi){
		return;
	}

	//DIVIDE
	int mid=(hi+lo)/2;
	int count=lo;
	struct node *midn=lon;
	while(count!=mid){
		midn=midn->next;
		count++;//jo bhi count hoga wo wala node midn mein hoga
	}
	merge_sort_klist(lo,mid,lon,midn);
	merge_sort_klist(mid+1,hi,midn->next,hin);

	//CONQUER
	struct node *p1=lon;
	struct node *p2=midn->next;

	struct node *head=NULL;
	struct node *tail=NULL;
	while(p1!=midn->next && p2!=hin->next){
		if(p1->val>p2->val){
			tail=push(p2->val,tail);
			if(head==NULL){
				head=tail;
			}
			p2=p2->next;
		}
		else{
			tail=push(p1->val,tail);
			if(head==NULL){
				head=tail;
			}
			p1=p1->next;
		}
	}
	if(p1==midn->next){
		while(p2!=hin->next){
			tail=push(p2->val,tail);
			p2=p2->next;
		}
	}
	else{
		while(p1!=midn->next){
			tail=push(p1->val,tail);
			p1=p1->next;
		}
	}

	while(head!=NULL){
		lon->val=head->val;
		head=head->next;
		lon=lon->next;
	}
}

struct node * push(int val,struct node *tail){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	temp->prev=tail;
	if(tail!=NULL){
		tail->next=temp;
	}
	return temp;
}