#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max 100
struct node{
	char val;
	struct node *left;
	struct node *right;
};
struct node * create_tree(int pstart,int pend,int istart,int iend,char ino[],char preo[]);
void inorder_traversal(struct node *root);
void preorder_traversal(struct node *root);

int main(){
	char ino[max];
	char preo[max];
	scanf("%[^\n]s",ino);
	scanf(" %[^\n]s",preo);
	int len=strlen(ino);

	struct node * root=create_tree(0,len-1,0,len-1,ino,preo);
	inorder_traversal(root);
	printf("\n");
	preorder_traversal(root);
	printf("\n");
	return 0;
}

struct node * create_tree(int pstart,int pend,int istart,int iend,char ino[],char preo[]){
	//handle the base case
	if(pstart>pend){//for right problem. will automatically handle ino part
		return NULL;
	}
	else if(istart>iend){//for handling the left problem. will automatically hadle preo part
		return NULL;
	}
	else if(pstart==pend || istart==iend){
		struct node *root=(struct node *)malloc(sizeof(struct node));
		root->val=preo[pend];
		root->left=NULL;
		root->right=NULL;
		return root;
	}

	//Dividing the Probelm into right and left subproblem
	char rval=preo[pend];

	//search for the right sub-problem
	int count=0;
	for(int i=iend;i>=istart;i--){
		if(ino[i]==rval){
			break;
		}
		count++;
	}
	int npstart=pend-count;//with respect to post array
	int npend=pend-1;		 //in order will be handled by post only
	int nistart=iend-count+1;
	int niend=iend;
	//solving the right sub-problem
	struct node *right=create_tree(npstart,npend,nistart,niend,ino,preo);

	//search the left sub-problem
	npend=npstart-1;
	npstart=pstart;
	niend=nistart-2;//crossing the root
	nistart=istart;
	//solving the left sub-problem
	struct node *left=create_tree(npstart,npend,nistart,niend,ino,preo);


	//Combining the problem
	struct node *root=(struct node *)malloc(sizeof(struct node));
	root->val=rval;
	root->left=left;
	root->right=right;
	return root;
}

void inorder_traversal(struct node *root){
	if(root==NULL){
		return;
	}
	inorder_traversal(root->left);
	printf("%c ",root->val);
	inorder_traversal(root->right);
}
void preorder_traversal(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%c ",root->val);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}