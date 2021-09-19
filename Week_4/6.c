#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void push_forward(int j,int deadend,char sent[]);

int main(){
	char sent[100];
	scanf("%[^\n]s",sent);
	int len=strlen(sent);
	int words=0;
	for(int i=0;i<len;i++){
		if(sent[i]==' '){
			words++;
		}
	}
	//printf("%d\n",words);
	int deadend=len-1;//the pos of last char
	for(int i=1;i<=words;i++){//shift word-1 times
		//getting the end of word
		int w_idx=0;
		for(int j=1;j<len;j++){
			if(sent[j]==' '){
				w_idx=j-1;
				break;
			}
		}

		//pushing the word to deadend
		for(int j=w_idx;j>=0;j--){
			push_forward(j,deadend,sent);
			deadend--;
		}
		push_forward(0,deadend,sent);
		deadend--;
		printf("%s\n",sent);
	}
	//push_forward(0,deadend,sent);

	printf("%s\n",sent);
	return 0;
}

void push_forward(int j,int deadend,char sent[]){
	for(int i=j;i<deadend;i++){
		char temp=sent[i+1];
		sent[i+1]=sent[i];
		sent[i]=temp;
	}
}