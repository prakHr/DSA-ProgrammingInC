#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node * makeBST(int N,int arr[]);
void insert_node(int val,struct node *root);
struct node * get_node(int val);
void traverse_inorder(struct node *root);
void make_list(struct node **start,struct node **end,struct node *root);

struct node{
	int val;
	struct node *left;
	struct node *right;
};

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}
	struct node *root=makeBST(N,arr);
	traverse_inorder(root);

	//Making the list(sorted)
	struct node *start=NULL;
	struct node *end=NULL;
	make_list(&start,&end,root);
	printf("Printing list:\n");
	while(start!=NULL){
		printf("%d \n",start->val);
		start=start->right;
	}
	return 0;
}

struct node * makeBST(int N,int arr[]){
	struct node *root=(struct node *)malloc(sizeof(struct node));
	root->left=NULL;
	root->right=NULL;
	root->val=arr[0];
	for(int i=1;i<N;i++){
		insert_node(arr[i],root);
	}
	return root;
}

void insert_node(int val,struct node *root){
	if(val>root->val){
		if(root->right==NULL){
			root->right=get_node(val);
		}
		else{
			insert_node(val,root->right);
		}
	}
	else{
		if(root->left==NULL){
			root->left=get_node(val);
		}
		else{
			insert_node(val,root->left);
		}
	}
}

struct node * get_node(int val){
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

void traverse_inorder(struct node *root){
	//if its leaf node
	if(root->left==NULL && root->right==NULL){
		printf("Leaf: %d %p\n",root->val,root);
		return;
	}
	else{
		if(root->left !=NULL){
			traverse_inorder(root->left);
		}
		printf("Self: %d %p\n",root->val,root);
		if(root->right !=NULL){
			traverse_inorder(root->right);
		}
	}
}

void make_list(struct node **start,struct node **end,struct node *root){
	//printf("%p \n",root);
	if(root->left==NULL && root->right==NULL){
		*start=root;
		*end=root;
		return;
	}
	else{
		//printf("bazinga\n");
		//this will definately be filled up
		struct node *curr_start=root;
		struct node *curr_end=NULL;

		//Handling the left sub-problem
		if(root->left!=NULL){
			make_list(&curr_start,&curr_end,root->left);
			curr_end->right=root;	//linking the end of lower tree to this node
		}
		*start=curr_start;		//overall start of this sub-tree
		root->left=curr_end;

		//Handling the right sub-problem
		curr_start=NULL;
		curr_end=root;
		if(root->right!=NULL){
			make_list(&curr_start,&curr_end,root->right);
			curr_start->left=root;
		}
		*end=curr_end;			//overall end of the sub-tree
		root->right=curr_start; //linking the right half to this node
		return;
	}
}