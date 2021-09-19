#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
void med_search(int l1,int h1,int l2,int h2,int arr[]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[2*N];
	for(int i=0;i<2*N;i++){
		scanf(" %d",&arr[i]);
	}
	med_search(0,N-1,N,2*N-1,arr);
	return 0;
}
void med_search(int l1,int h1,int l2,int h2,int arr[]){
	int m1=(l1+h1)/2;
	int m2=(l2+h2)/2;

	//handling the base case
	//printf("init: %d %d %d %d\n",l1,m1,l2,m2);
	if(m1==l1 && m2==l2){//that is we have converged to last four
		int temp[4];
		int count=0;
		while(m1<=h1 && m2<=h2){
			if(arr[m1]>arr[m2]){
				temp[count]=arr[m2];
				m2++;
				count++;
			}
			else{
				temp[count]=arr[m1];
				m1++;
				count++;
			}
		}
		if(m1>h1){
			temp[count++]=arr[m2++];
			temp[count]=arr[m2];
		}
		else{
			temp[count++]=arr[m1++];
			temp[count]=arr[m1];
		}
		for(int i=0;i<4;i++){
			printf("%d ",temp[i]);
		}
		printf("\nMedian is: %d\n",(temp[1]+temp[2])/2);
		return;
	}


	//calculating the current mid element
	int med1=arr[m1];
	int med2=arr[m2];
	if((h1-l1+1)%2==0){
		med1=(med1+arr[m1+1])/2;
	}
	if((h2-l2+1)%2==0){
		med2=(med2+arr[m2+1])/2;
	}

	
	if(med1<med2){
		if((h2-l2+1)%2==0){
			m2=m2+1;
		}
		printf("rec1: %d %d %d %d\n",m1,h1,l2,m2);
		med_search(m1,h1,l2,m2,arr);
	}
	else{
		if((h1-l1+1)%2==0){
			m1=m1+1;
		}
		printf("rec2: %d %d %d %d\n",m2,h2,l1,m1);
		med_search(m2,h2,l1,m1,arr);
	}
}