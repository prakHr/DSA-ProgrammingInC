#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	char str[100];
	scanf("%[^\n]s",str);
	
	int len=strlen(str);
	int max=-1;
	//selecting the length
	for(int i=0;i<len;i++){
		//selecting the word's start pos now
		for(int j=0;j<len-i;j++){
			int count=0;
			//now searching amolg all words
			for(int k=0;k<len-i;k++){
				int flag=0;
				if(j!=k){
					for(int l=k;l<=k+i;l++){
						if(str[l]!=str[l-k+j]){
							flag=1;
							break;
						}
					}
				}
				if(flag==0){
					count++;
				}
			}
			if(count*(i+1)>max){
				max=count*(i+1);
			}
		}
	}
	printf("MAX: %d\n",max);
	return 0;
}