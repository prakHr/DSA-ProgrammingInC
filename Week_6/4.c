#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	char op;
	struct node *back;
};
void inTopost(char in[],char post[]);
struct node * push_stack(char op,struct node *tos);
struct node * pop_stack(struct node *tos);
int get_priority(char op);
int evaluate_postfix(char post[]);
int perform_evaluation(char a,char b,char op);

int main(){
	char in[100],post[100]={'\0'};
	scanf("%[^\n]s",in);

	inTopost(in,post);
	printf("%s\n",post);
	// int len1=strlen(in);
	// int len2=strlen(post);
	// printf("%d %d\n",len1,len2);
	int value=evaluate_postfix(post);
	printf("VALUE: %d\n",value);

	return 0;
}

void inTopost(char in[],char post[]){
	struct node *tos=NULL;
	int count=0;
	for(int i=0;i<strlen(in);i++){
		if(in[i]>47 && in[i]<58){
			post[count]=in[i];
			count++;
		}
		else if(in[i]=='('){
			tos=push_stack(in[i],tos);
		}
		else if(in[i]==')'){
			while(tos->op!='('){
				post[count]=tos->op;
				count++;
				tos=pop_stack(tos);
			}
			tos=pop_stack(tos);
		}
		else{//only operations are left
			if(tos==NULL){
				tos=push_stack(in[i],tos);
				continue;
			}
			int nprio=get_priority(in[i]);
			int cprio=get_priority(tos->op);
			while(nprio<=cprio){
				post[count]=tos->op;
				count++;
				tos=pop_stack(tos);
				if(tos==NULL){
					break;
				}
				else{
					cprio=get_priority(tos->op);
				}
			}
			tos=push_stack(in[i],tos);		
		}
	}
	while(tos!=NULL){
		post[count]=tos->op;
		count++;
		tos=pop_stack(tos);
	}
}
int evaluate_postfix(char post[]){
	struct node *tos=NULL;
	int len=strlen(post);
	int value=0;
	for(int i=0;i<len;i++){
		printf("%c\n",post[i]);
		if(post[i]>47 && post[i]<58){
			tos=push_stack(post[i],tos);
			//printf("tos: %c\n",tos->op);
		}
		else{
			char b=tos->op;
			tos=pop_stack(tos);
			char a=tos->op;
			tos=pop_stack(tos);
			value=perform_evaluation(a,b,post[i]);
			printf("a:%d b:%d value: %d\n",a-48,b-48,value);
			tos=push_stack(value+48,tos);
		}
	}
	return value;
}

struct node * push_stack(char op,struct node *tos){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->op=op;
	temp->back=tos;
	return temp;
}

struct node * pop_stack(struct node *tos){
	struct node * temp=tos->back;
	free(tos);
	return temp;
}

int get_priority(char opnew){
	if(opnew=='*' || opnew=='/'){
		return 2;
	}
	else if(opnew=='+' || opnew=='-'){
		return 1;
	}
	else if(opnew=='(' || opnew==')'){
		return 0;
	}
	return -1;
}

int perform_evaluation(char a,char b,char op){
	a=a-48;
	b=b-48;
	if(op=='/'){
		return a/b;
	}
	else if(op=='*'){
		return a*b;
	}
	else if(op=='+'){
		return a+b;
	}
	else{
		return a-b;
	}
}