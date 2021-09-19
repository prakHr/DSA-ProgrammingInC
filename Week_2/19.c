#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void decode_num_offset(int num,int offset);

int main(){
	char msg[100];
	scanf("%[^\n]s",msg);
	int len=strlen(msg);
	for(int i=0;i<len;i++){
		char alpha=msg[i];
		if(alpha=='0' && msg[i+1]!='0'){
			printf(" ");
		}
		else if(msg[i]==' '){
			continue;
		}
		else{
			int num=alpha-48;
			int offset=1;
			do{
				i++;
				offset++;
			}while(msg[i]==alpha);
			i--;
			offset--;
			decode_num_offset(num,offset);
		}
	}
	printf("\n");
	return 0;
}

//print inside only after decoding
void decode_num_offset(int num,int offset){
	if((num==0 || num==1) && offset==2){
		printf("%d",num);
	}
	else if(num==7){
		if(offset==5){
			printf("%d",num);
		}
		else{
			printf("%c",'p'+offset-1);
		}
	}
	else if(num==9){
		if(offset==5){
			printf("%d",num);
		}
		else{
			printf("%c",'w'+offset-1);
		}
	}
	else{
		if(offset==4){
			printf("%d",num);
		}
		else if(num==8){
			printf("%c",'t'+offset-1);
		}
		else{
			printf("%c",'a'+(num-2)*3+offset-1);
		}
	}
}