#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Item{
	char item[20];
	int code;
	float price;
	int stock;
	int highDemand;
	int soldToday;
	struct Item *next;
};
void add_item(struct Item **list);
void print_list(struct Item **list);
void update_price(struct Item **list);

int main(){
	struct Item *list=NULL;
	while(1){
		int choice;
		printf("ENTER your CHOICE: ");
		scanf(" %d",&choice);
		switch(choice){
			case 1:
				add_item(&list);
				print_list(&list);
				break;
			case 2:
				update_price(&list);
				print_list(&list);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				return 0;
				break;
		}
	}
	return 0;
}

void add_item(struct Item **list){
	struct Item *temp=*list;
	struct Item *ele=(struct Item*)malloc(sizeof(struct Item));
	printf("Enter the credentials one by one\n");
	scanf(" %[^\n]s",ele->item);
	scanf("%d",&(ele->code));
	scanf("%f",&(ele->price));
	scanf("%d",&(ele->stock));
	scanf("%d",&(ele->highDemand));
	scanf("%d",&(ele->soldToday));
	ele->next=NULL;
	if(temp==NULL){
		*list=ele;
	}
	else{
		//printf("Inside else\n");
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=ele;
	}
}

void print_list(struct Item **list){
	struct Item *temp=*list;
	while(temp!=NULL){
		printf("item: %s \n",temp->item);
		printf("code: %d\n",temp->code);
		printf("price: %f\n",temp->price);
		printf("stock: %d\n",temp->stock);
		printf("highDemand: %d\n",temp->highDemand);
		printf("soldToday: %d\n",temp->soldToday);
		temp=temp->next;
		printf("\n");
	}
}

void update_price(struct Item **list){
	char name[20];
	printf("Enter the name of item:\n");
	scanf(" %[^\n]s",name);
	printf("Enter the new price:\n");
	float new_p;
	scanf("%f",&new_p);

	struct Item *temp=*list;
	while(temp!=NULL){
		int comp=strcmp(name,temp->item);
		if(comp==0){
			temp->price=new_p;
			break;
		}
		temp=temp->next;
	}
}