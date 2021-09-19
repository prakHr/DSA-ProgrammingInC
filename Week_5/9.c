#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int max;
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
		if(i==0){
			max=arr[i];
		}
		else if(arr[i]>max){
			max=arr[i];
		}
	}

	int count[max]; //0 not included
	for(int i=0;i<max;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]-1]++;
	}

	int odd_flag=0;
	for(int i=max-1;i>=0;i--){
		if(count[i]%2!=0){
			odd_flag=1; //CH wins
			break;
		}
	}
	if(odd_flag==1){
		printf("VISHAL\n");
	}
	else{
		printf("TANMAY\n");
	}
	return 0;
}