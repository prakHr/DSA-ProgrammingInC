#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define max 10

struct node{
	int val;
	struct node *next;
};
void insert(int val,int m,struct node *hash[]);
int search(int val,int m,struct node *hash[]);
void print(int m,struct node *hash[]);

int main(){
	srand(1);
	int n,m;
	scanf("%d %d",&n,&m);

	//creating the hash table
	struct node *hash[m];
	for(int i=0;i<m;i++){
		hash[i]=NULL;
	}
	for(int i=0;i<n;i++){
		int val=rand()%(max*m);
		insert(val,m,hash);
	}

	//print(m,hash);
	//querying the hash table with random query
	int x=10000000;
	int count=0;
	for(int i=0;i<x;i++){
		int val=rand()%(max*m);
		count+=search(val,m,hash);
	}
	printf("The average search complexity: %f %d %d\n",(float)count/x,count,x);
	return 0;
}

void insert(int val,int m,struct node *hash[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;

	int key=val%m;
	struct node *head=hash[key];
	temp->next=head;
	hash[key]=temp;
}

int search(int val,int m,struct node *hash[]){
	int key=val%m;
	int count=0,flag=0;
	struct node *head=hash[key];
	while(head!=NULL){
		count++;
		if(head->val==val){
			flag=1;
			break;
		}
		head=head->next;
	}
	// if(flag==1){
	// 	printf("%d Found\n",val);
	// }
	// else{
	// 	printf("%d Not Found\n",val);
	// }
	return count;
}

void print(int m,struct node *hash[]){
	printf("Printing the hash table\n");
	for(int i=0;i<m;i++){
		struct node *head=hash[i];
		while(head!=NULL){
			printf("%d %d\n",i,head->val);
			head=head->next;
		}
	}
}