#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print_perm(int clen,int len,int carr[],char perm[]);

int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int len=strlen(str);

	int carr[128]; //all the possble ascii chars
	for(int i=0;i<128;i++){
		carr[i]=0;
	}
	for(int i=0;i<len;i++){
		carr[(int)str[i]]++;
	}
	for(int i=0;i<128;i++){
		if(carr[i]!=0){
			printf("%c %d\n",i,carr[i]);
		}
	}
	char perm[len+1];
	for(int i=0;i<len+1;i++){
		perm[i]='\0';
	}
	printf("%s\n",perm);
	print_perm(0,len,carr,perm);
	return 0;
}

void print_perm(int clen,int len,int carr[],char perm[]){
	//handling the base case
	if(clen>=len){
		return;
	}
	
	for(int i=0;i<128;i++){
		if(carr[i]!=0){
			perm[clen]=i;;
			carr[i]--;
			print_perm(clen+1,len,carr,perm);
			carr[i]++;
			if(clen==len-1){
				printf("%s\n",perm);
			}
		}
	}
}