#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int len=strlen(str);

	int flag=1,start=-1;
	for(int i=0;i<=len;i++){
		printf("%d,%d,%d\n",i,start,flag);
		if(str[i]==' ' && flag==1){
			start=i;
			flag=1;
			continue;
		}
		else if((str[i]==' ' || str[i]=='\0') && flag==0){
			int to=(i-1+start)/2;
			if(i>to*2+1-start){
				to=to+1;
			}
			for(int j=start+1;j<=to;j++){
				printf("  %d,%d,%d\n",j,i-(j-start),to);
				char temp=str[j]+3;
				str[j]=str[i-(j-start)]+3;
				str[i-(j-start)]=temp;
				if(str[i-(j-start)]>122){
					str[i-(j-start)]=(str[i-(j-start)]-122)+96;
				}
				if(str[j]>122){
					str[j]=(str[j]-122)+96;
				}
			}
			start=i;
			flag=1;
		}
		else{
			flag=0;
		}
	}
	printf("\nENCODED STRING :: %s\n",str);
	flag=1;
	start=-1;//the position of the first space
	for(int i=0;i<=len;i++){
		printf("%d,%d,%d\n",i,start,flag);
		if(str[i]==' ' && flag==1){
			start=i;
			flag=1;
			continue;
		}
		else if((str[i]==' ' || str[i]=='\0') && flag==0){
			int to=start+(int)ceil(((float)(i-1)-start)/2);
			for(int j=start+1;j<=to;j++){
				printf("  %d,%d,%d\n",j,i-(j-start),to);
				char temp=str[j]-3;
				str[j]=str[i-(j-start)]-3;
				str[i-(j-start)]=temp;
				if(str[j]<97){
					str[j]=123-(97-str[j]);
				}
				if(str[i-(j-start)]<97){
					str[i-(j-start)]=123-(97-str[i-(j-start)]);
				}
			}
			start=i;
			flag=1;
		}
		else{
			flag=0;
		}
	}
	printf("\nDECODED STRING:: %s\n",str);
	return 0;
}