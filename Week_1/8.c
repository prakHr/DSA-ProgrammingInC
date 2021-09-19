#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int counter[6];
	int len=strlen(str);

	for(int i=0;i<len;i++){
		if(str[i]=='g'){
			counter[0]++;
		}
		else if(str[i]=='o'){
			counter[1]++;
		}
		else if(str[i]=='d'){
			counter[2]++;
		}
		else if(str[i]=='b'){
			counter[3]++;
		}
		else if(str[i]=='y'){
			counter[4]++;
		}
		else if(str[i]=='e'){
			counter[5]++;
		}
	}
	int flag=1;
	for(int i=0;i<6;i++){
		if(i!=1 && counter[i]==0){
			flag=0;
			break;
		}
		if(i==1 && counter[i]<2){
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}