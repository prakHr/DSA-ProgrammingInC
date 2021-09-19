#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max 100
struct node{
	int id;
	struct node *next;
};
void add_node(int pos,int id,struct node *carr[]);


int main(){
	int len;
	scanf("%d",&len);
	char str[len+1];
	scanf(" %[^\n]s",str);
	len=strlen(str);

	//Making the count array
	int count[26]={0};
	struct node *carr[26]={NULL};
	for(int i=0;i<len;i++){
		count[str[i]-97]+=1;
		add_node(str[i]-97,i,carr);
	}

	//finding the answer
	int ans[len];
	int flag=0;
	for(int i=0;i<26;i++){
		if(count[i]%2!=0){
			flag++;
			ans[len/2]=carr[i]->id;//the len will be odd in case of one odd
			carr[i]=carr[i]->next;
		}
	}
	if(flag>1){
		printf("%d\n",-1);
	}
	else{
		int i=0;
		int j=len-1;
		for(int k=0;k<26;k++){
			struct node *head=carr[k];
			while(head!=NULL){
				ans[i]=head->id;
				head=head->next;
				ans[j]=head->id;
				head=head->next;
				i++;
				j--;
			}
		}
		for(int i=0;i<len;i++){
			printf("%d ",ans[i]+1);
		}
		printf("\n");
	}
	
	return 0;
}
void add_node(int pos,int id,struct node *carr[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->id=id;
	temp->next=carr[pos];
	carr[pos]=temp;
}