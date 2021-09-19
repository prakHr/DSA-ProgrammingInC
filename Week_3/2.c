#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int h_idx;
	int l_idx;
	struct node *left;
	struct node *right;//we actually didnt needed this here
};
struct node* push_to_stack(struct node *tail,int h_idx,int l_idx);
void pop_the_stack(struct node *tail);
void merge_the_problems(struct node *tail,int *ip,int arr[]);


int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	//struct node *head=NULL;//dont actually need these here
	struct node *tail=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i==0){
			tail=push_to_stack(tail,i,i);
		}
		else{
			tail=push_to_stack(tail,i,i);
		}
	}

	int ip=0;
	printf("Entring into the merge\n");
	merge_the_problems(tail,&ip,arr);
	printf("Coming out of merge\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nIP: %d\n",ip);
	
	return 0;
}

struct node* push_to_stack(struct node *tail,int h_idx,int l_idx){
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->h_idx=h_idx;
	new->l_idx=l_idx;
	new->left=tail;
	new->right=NULL;
	if(tail!=NULL){
		tail->right=new;
	}
	
	//cant do tail=new cuz this is the local copy of the pointer. wont be reflected in the original pointer
	return new;//returning the address of new node for it to be tail next time.
}
//will be called after the merging of last two problems will be done
void pop_the_stack(struct node *tail){
	struct node *new_last=tail->left;
	new_last->h_idx=tail->h_idx;
	if(tail->right==NULL){
		return;
	}
	else{
		(tail->right)->left=new_last;
	}
	//should have not used the right pointer
	//we should worry about freeing the memory too. later
}

void merge_the_problems(struct node *tail,int *ip,int arr[]){
	//have to solve two subroblem till we get whole array sorted
	//struct node *temp=tail;
	printf("At beigning: %p\n",tail);
	while(tail->left!=NULL){//will run O(logN) times
		struct node *p2=tail;
		int flag=0;
		printf("at while: %p\n",tail);
		while(p2!=NULL){//will run O(N) times combined with inner while
			struct node *p1=p2->left;
			int p1_low=p1->l_idx;
			int p1_high=p1->h_idx;
			int p2_low=p2->l_idx;
			int p2_high=p2->h_idx;
			printf("  Inside While %p,%p\n",p1,p2);
			// int left_pointer=p1_low;
			// int right_pointer=p2_low;
			int counter=0;
			int temp_arr[p2_high-p1_low+1];
			printf("len: %d\n",p2_high-p1_low+1);
			printf("%d %d %d %d\n",p1_low,p1_high,p2_low,p2_high);
			while(p1_low<=p1_high && p2_low<=p2_high){
				if(arr[p1_low]>arr[p2_low]){
					*ip+=1;//automatically couldd all comparisons
					temp_arr[counter]=arr[p2_low];
					p2_low++;
					counter++;
				}
				else{
					temp_arr[counter]=arr[p1_low];
					p1_low++;
					counter++;
				}
			}
			printf("%d %d %d %d\n",p1_low,p1_high,p2_low,p2_high);
			//saving all the other left elemts directly. Could have been done in main arr only. but :)
			if(p1_low>p1_high){
				for(int i=p2_low;i<=p2_high;i++){
					temp_arr[counter]=arr[i];
					counter++;
				}
			}
			else{
				for(int i=p1_low;i<=p1_high;i++){
					//printf("extra:%d\n",arr[i]);
					temp_arr[counter]=arr[i];
					counter++;
				}
			}

			p1_low=p1->l_idx;
			p2_high=p2->h_idx;
			for(int i=0;i<p2_high-p1_low+1;i++){
				printf("%d ",temp_arr[i]);
			}
			printf("\n");
			//Finally saving all the mini-sorted problem in main array
			for(int i=p1_low;i<=p2_high;i++){
				arr[i]=temp_arr[i-p1_low];
			}

			for(int i=0;i<4;i++){
				printf("%d ",arr[i]);
			}
			printf("\nHari\n");

			//have to merge this two problem stack
			pop_the_stack(p2);
			printf("OM\n");
			//Solving other sub-problem
			p2=p1->left; //pointing to previous 2 sub-problem ka last part
			printf("Hari%p\n",p1->left);
			if(flag==0){
				flag=1;
				tail=p1;
			}
		}
	}
}