#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};
struct node * insert(int val,struct node *tail);

int main(){
	int m,n;
	scanf("%d %d",&m,&n);

	struct node *head1=NULL;
	struct node *tail1=NULL;
	struct node *head2=NULL;
	struct node *tail2=NULL;

	for(int i=0;i<m;i++){
		int val;
		scanf(" %d",&val);
		tail1=insert(val,tail1);
		if(head1==NULL){
			head1=tail1;
		}
	}
	for(int i=0;i<n;i++){
		int val;
		scanf(" %d",&val);
		tail2=insert(val,tail2);
		if(head2==NULL){
			head2=tail2;
		}
	}

	if(m>n){
		int diff=m-n;
		for(int i=0;i<diff;i++){
			head1=head1->next;
		}
	}
	else{
		int diff=n-m;
		for(int i=0;i<diff;i++){
			head2=head2->next;
		}
	}

	int flag=0;
	int val;
	while(head1!=NULL && flag==0){
		if(head1->val==head2->val){
			flag=1;
			val=head1->val;
			break;
		}
		head1=head1->next;
		head2=head2->next;
	}
	if(flag==1){
		printf("val: %d\n",val);
	}
	else{
		printf("NO intersection\n");
	}
	return 0;
}

struct node * insert(int val,struct node *tail){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	if(tail!=NULL){
		tail->next=temp;
	}
	return temp;
}