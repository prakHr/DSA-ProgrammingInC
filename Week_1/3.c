#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct charCount{
	char symbol;
	int count;
};

int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int len=strlen(str);
	struct charCount cC[len];
	for(int i=0;i<len;i++){
		cC[i].symbol=200;
		cC[i].count=0;
	}

	int next=0;
	for(int i=0;i<len;i++){
		char c=str[i];
		int addAt=next;
		for(int j=0;j<next;j++){
			if(cC[j].symbol==c){
				addAt=j;
				break;
			}
		}
		if(addAt==next){
			next++;
			cC[addAt].symbol=c;
		}
		cC[addAt].count++;
	}
	for(int i=0;i<next;i++){
		printf("%c %d\n",cC[i].symbol,cC[i].count);
	}
	return 0;
}