#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct sparse{
	int row;
	int col;
	int val;
	struct sparse *next;
};
void insert_to_list(struct sparse **head,int row,int col,int val);
void transpose_sparse(struct sparse **head_add);


int main(){
	int mat[6][6];
	int count=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]!=0){
				count++;
			}
		}
	}
	printf("count %d\n",count);
	if(count<10){
		printf("SPARSE\n");
		struct sparse *head=NULL;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				//printf("%d %d %p\n",i,j,head);
				if(mat[i][j]!=0){
					insert_to_list(&head,i,j,mat[i][j]);
				}
			}
		}
		struct sparse *temp=head;
		while(temp!=NULL){
			printf("row: %d, col: %d, val: %d\n",temp->row,temp->col,temp->val);
			temp=temp->next;
		}
		transpose_sparse(&head);
		printf("Transposed sparse matrix\n");
		temp=head;
		while(temp!=NULL){
			printf("row: %d, col: %d, val: %d\n",temp->row,temp->col,temp->val);
			temp=temp->next;
		}
	}
	else{
		printf("NOT SPARSE\n");
	}
	
	return 0;
}

void insert_to_list(struct sparse **head_add,int row,int col,int val){
	struct sparse *temp=*head_add;
	struct sparse *last=NULL;
	while(temp!=NULL){
		//automatically they will be sequential
		//cuz inserting in that order only.
		last=temp;
		temp=temp->next;
	}
	temp=(struct sparse*)malloc(sizeof(struct sparse));
	temp->row=row;
	temp->col=col;
	temp->val=val;
	temp->next=NULL;
	if(last==NULL){
		*head_add=temp;
	}
	else{
		last->next=temp;
	}
}

void transpose_sparse(struct sparse **head_add){
	struct sparse *head=*head_add;
	struct sparse *temp=head;
	struct sparse *list2=NULL;
	while(temp!=NULL){
		struct sparse *temp2=list2;
		struct sparse *ele=(struct sparse*)malloc(sizeof(struct sparse));
		ele->row=temp->col;
		ele->col=temp->row;
		ele->val=temp->val;
		ele->next=NULL;
		if(temp2==NULL){
			list2=ele;
		}
		else{
			struct sparse *last=NULL;
			while(temp2!=NULL){
				printf("row: %d,list_r: %d, col: %d,list_col: %d\n",temp->col,temp2->row,temp->row,temp2->col);
				if(temp->col<temp2->row){
					printf("   cat1\n");
					ele->next=temp2;
					if(last==NULL){
						list2=ele;
					}
					else{
						last->next=ele;
					}
					break;
				}
				else if(temp->col==temp2->row && temp->row<temp2->col){
					printf("   cat2\n");
					ele->next=temp2;
					if(last==NULL){
						list2=ele;
					}
					else{
						last->next=ele;
					}
					break;
				}
				else if(temp2->next==NULL){
					printf("   cat3\n");
					temp2->next=ele;
					break;
				}
				last=temp2;
				temp2=temp2->next;
			}
		}
		temp=temp->next;
	}
	*head_add=list2;
}