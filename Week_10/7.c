#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
void get_binary_exp(int val,int pos,int arr[][31]);
void get_y_kay(int u,int v,int arr[][31],int ans[]);
int get_number(int ans[]);

int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	int arr[N][31];
	for(int i=0;i<N;i++){
		int val;
		scanf(" %d",&val);
		get_binary_exp(val,i,arr);
		// for(int j=0;j<31;j++){
		// 	printf("%d ",arr[i][j]);
		// }
		// printf("\n");
	}
	int query[Q][2];
	for(int i=0;i<Q;i++){
		scanf(" %d %d",&query[i][0],&query[i][1]);
	}

	for(int i=0;i<Q;i++){
		int ans[31];
		get_y_kay(query[i][0],query[i][1],arr,ans);
		int num=get_number(ans);
		printf("ans: %d\n",num);
	}
	return 0;
}

void get_binary_exp(int val,int pos,int arr[][31]){
	for(int i=0;i<31;i++){
		int cof=val%2;
		arr[pos][i]=cof;
		val=val/2;
	}
}
void get_y_kay(int u,int v,int arr[][31],int ans[]){
	u=u-1;
	v=v-1;//making them zero based indexed
	for(int i=0;i<31;i++){
		int c0=0;
		int c1=0;
		for(int j=u;j<=v;j++){
			if(arr[j][i]==0){
				c0++;
			}
			else{
				c1++;
			}
		}
		if(c1>c0){
			ans[i]=0;//if 1 is more take 0 in y. for xor effect
		}
		else{
			ans[i]=1;
		}
	}
}
int get_number(int ans[]){
	int num=0;
	int two=1;
	for(int i=0;i<31;i++){
		//printf("%d ",ans[i]);
		num+=ans[i]*two;
		two=two*2;
	}
	//printf("\n");
	return num;
}
