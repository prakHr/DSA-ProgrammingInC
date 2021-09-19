#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char key[100],text[100];
	scanf("%[^\n]s",key);
	scanf(" %[^\n]s",text);
	int len=strlen(key);
	int maxLen=strlen(text);
	int counter=0;
	for(int i=0;i<maxLen-len+1;i++){
		int flag=1;
		for(int j=0;j<len;j++){
			if(text[i+j]!=key[j]){
				printf("%d,%d %c,%c\n",i,j,text[i+j],key[j]);
				flag=0;
				break;
			}
		}
		if(flag==1){
			counter++;
		}
	}
	printf("%d\n",counter);
	return 0;
}
