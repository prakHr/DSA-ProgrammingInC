#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int val;
	struct node *next;
};
void delete(int N,int val,struct node *tab[]);
void search(int N,int val,struct node *tab[]);
void print_table(int N,struct node *tab[]);
void insert(int N,int val,struct node *tab[]);

//void main also works
int main(){
	int N=10;
	struct node *tab[N];
	for(int i=0;i<N;i++){
		tab[i]=NULL;
	}
	while(1){
		int choice,val;
		scanf(" %d",&choice);
		if(choice==1){
			scanf(" %d",&val);
			insert(N,val,tab);
			printf("Inserted\n");
		}
		else if(choice==2){
			print_table(N,tab);
			printf("\nPrinted\n");
		}
		else if(choice==3){
			scanf(" %d",&val);
			search(N,val,tab);
			printf("\nSearched\n");
		}
		else if(choice==4){
			scanf(" %d",&val);
			delete(N,val,tab);
			printf("\nDeleted\n");
		}
		else{
			return 0;
		}
	}
	return 0;
}

void insert(int N,int val,struct node *tab[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;

	int key=val%N;
	int key2=(N-3)-val%(N-3);
	if(tab[key]==NULL){
		tab[key]=temp;
	}
	else if(tab[key2]==NULL){
		tab[key2]=temp;
	}
	else{
		struct node *head=tab[key];
		while(head->next!=NULL){
			head=head->next;
		}
		head->next=temp;
	}
}
void print_table(int N,struct node *tab[]){
	printf("Printing the Table\n");
	for(int i=0;i<N;i++){
		struct node *head=tab[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->val);
			head=head->next;
		}
	}
}
void search(int N,int val,struct node *tab[]){
	int key1=val%N;
	int key2=(N-3)-val%(N-3);

	int found=0;
	if(tab[key2]!=NULL && tab[key2]->val==val){
		found=1;
	}
	else{//wo apne actual positon mein hin hoga nahi to nahi
		//but first element isme ho sakta hai koi aur ho
		struct node *head=tab[key1];
		while(head!=NULL){
			if(head->val==val){
				found=1;
				break;
			}
			head=head->next;
		}
	}

	if(found==1){
		printf("Found\n");
	}
	else{
		printf("Not Found\n");
	}
}
void delete(int N,int val,struct node *tab[]){
	int key1=val%N;
	int key2=(N-3)-val%(N-3);

	if(tab[key2]!=NULL && tab[key2]->val==val){
		tab[key2]=tab[key2]->next;
		return;
	}
	else if(tab[key1]!=NULL){
		struct node *head=tab[key1];
		if(head!=NULL && head->val==val){
			tab[key1]=head->next;
			free(head);
			return;
		}
		struct node *prev=head;
		head=head->next;
		while(head!=NULL){
			if(head->val==val){
				prev->next=head->next;
				free(head);
				return;				
			}
			prev=prev->next;
			head=head->next;
		}
	}
	//if we dont find tit then only the control will reach here
	printf("NOT FOUND\n");
}