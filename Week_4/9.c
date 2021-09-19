#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct list{
	int num;
	struct list *next;
	struct list *prev;
};

int main(){
	int n;
	scanf("%d",&n);//they have to give number of digits
	struct list *head,*tail;
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		struct list *node=(struct list*)malloc(sizeof(struct list));
		node->num=temp;
		node->prev=NULL;
		node->next=NULL;
		if(i==0){
			head=tail=node;
		}
		else{
			node->prev=tail;
			tail->next=node;
			tail=node;
		}
		// if(i<n/2){
		// 	printf("%d",temp);
		// }
	}
	int count=0;
	tail=head;
	printf("First Half: ");
	n=n-1;
	while(count!=n/2){
		printf("%d",tail->num);
		tail=tail->next;//when it stop its at actually at n/2 from zero index
		count++;
	}
	printf(" Centre:");
	if((n)%2==0){//unique centre available
		printf("%d",tail->num+1);
		tail=tail->prev;
		printf(" Last:");
		while(tail!=NULL){
			printf("%d",tail->num);
			tail=tail->prev;
		}
	}
	else{
		int num1=tail->num;
		int num2=(tail->next)->num;
		if(num1<num2){
			printf("%d%d",num1+1,num1+1);
		}
		else{
			printf("%d%d",num1,num1);
		}
		tail=tail->prev;
		printf(" Last:");
		while(tail!=NULL){
			printf("%d",tail->num);
			tail=tail->prev;
		}
	}


	
	printf("\n");

	return 0;
}
