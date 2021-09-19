#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int create_next_random(int N);

int main(){
	int N,num;
	scanf("%d",&N);
	scanf("%d",&num);

	for(int i=0;i<num;i++){
		int newSeed=create_next_random(N);
		printf("%d\n",newSeed);
		N=newSeed;
	}
	return 0;
}

int create_next_random(int N){
	int sq=N*N;
	//Calculating the number of dig in the number
	int count=0;
	while(N!=0){
		count++;
		N=N/10;
	}
	//Initializing the digs placeholder
	int digs[2*N];
	
	//Taking out the digits of sq
	int count_new=0;
	while(sq!=0){
		int dig=sq%10;
		sq=sq/10;
		digs[count_new]=dig;
		count_new++;
	}
	if(count%2 != count_new%2){
		digs[count_new]=0;
		count_new++;
	}

	int newSeed=0;
	int offset=(count_new-count)/2;
	int temp=1;
	for(int i=offset;i<offset+count;i++){
		newSeed+=digs[i]*temp;
		temp=temp*10;
	}
	return newSeed;
}