#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char msg[100];
	scanf("%[^\n]s",msg);
	int depth;
	scanf("%d",&depth);
	int len=strlen(msg);
	int part=len/depth;
	if(part%2!=0){
		part+=1;
	}
	int arr[depth][part];
	for(int i=0;i<depth;i++){
		for(int j=0;j<part;j++){
			arr[i][j]=0;
		}
	}

	int k=0,d=0;
	for(int i=0;i<len;i++){
		if(msg[i]!=' '){
			arr[k][d]=msg[i];
			k++;
			if(k>=depth){
				k=0;
				d++;
			}
		}
	}
	for(int i=0;i<depth;i++){
		for(int j=0;j<part;j++){
			if(arr[i]!=0){
				printf("%c",arr[i][j]);
			}
		}
	}
	printf("\n\n");
	return 0;
}