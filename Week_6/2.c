#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10
#define MODM 1000000007
int expo_mod(int a,int b);
int give_max_len(int l,int r,char str[]);

int main(){
	char str[MAX];
	scanf("%[^\n]s",str);
	int len=strlen(str);
	int q;
	scanf(" %d",&q);
	int arr[q][2];
	for(int i=0;i<q;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
		arr[i][0]--;
		arr[i][1]--;	//making it zero indexed
	}
	printf("DONE\n");
	int data[MAX][2];//starting from 1
	data[0][0]=1;
	printf("%d\n",expo_mod(2,3));
	for(int i=0;i<MAX;i++){
		printf("%d\n",i);
		// if(i>0){
		// 	data[i][0]=((i+1)*(data[i-1][0]%MODM))%MODM;
		// }
		// printf("HI\n");
		data[i][1]=expo_mod(i+1,MODM-2);
	}
	for(int i=0;i<MAX;i++){
		printf("fact:%d expo:%d\n",arr[i][0],arr[i][1]);
	}

	return 0;
}
int expo_mod(int a,int b){
	//printf("%d %d\n",a,b);
	if(b==1){
		return a%MODM;
	}
	int b1=b/2;
	int b2=b/2;
	if(b%2==1){
		b2=b2+1;
	}
	return ((expo_mod(a,b1)%MODM)*(expo_mod(a,b2)%MODM))%MODM;
}

int give_max_len(int l,int r,char str[]){

	return 0;
}