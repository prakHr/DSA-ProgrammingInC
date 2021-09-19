#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void num_offset(int *num,int *offset,char alpha);

int main(){
	char msg[100];
	scanf("%[^\n]s",msg);
	int len=strlen(msg);
	for(int i=0;i<len;i++){
		//printf("%d %d\n",num,offset);
		if(msg[i]>47 && msg[i]<58){
			int num=msg[i]-48;
			if(num==0 || num==1){
				printf("%d%d",num,num);
			}
			else{
				printf("%d%d%d%d",num,num,num,num);
				if(num==7 || num==9){
					printf("%d",num);
				}
			}
		}
		else if(msg[i]==' '){
			printf("%d",0);
		}
		else{
			int num,offset;
			num_offset(&num,&offset,msg[i]);
			for(int i=0;i<offset;i++){
				printf("%d",num);
			}
		}
		if(msg[i+1]==msg[i]){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void num_offset(int *num,int *offset,char alpha){
	if(alpha<=111 && alpha>=97){
		*num=2+(alpha-97)/3;
		*offset=1+(alpha-97)%3;//how many time to press
	}
	else if(alpha>111 && alpha<=115){
		*num=7+(alpha-112)/4;
		*offset=1+(alpha-112)%4;
	}
	else if(alpha>115 && alpha<=118){
		*num=8+(alpha-116)/3;
		*offset=1+(alpha-116)%3;
	}
	else if(alpha>118 && alpha<=122){
		*num=9+(alpha-119)/4;
		*offset=1+(alpha-119)%4;
	}
}