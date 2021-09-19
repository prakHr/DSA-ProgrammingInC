#include <stdio.h>
#include <string.h>

int main(){
	char str[2][10];
	for(int i=0;i<2;i++){
		scanf(" %[^\n]s",str[i]);
	}
	char str2[2][10];
	for(int i=0;i<2;i++){
		strcpy(str2[i],str[i]);
	}
	for(int i=0;i<2;i++){
		printf("%s\n",str2[i]);
	}
}