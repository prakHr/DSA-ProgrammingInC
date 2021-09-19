#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int fill_spiral(int n,int sid,int start,int *mat);

int main(){
	int n;
	scanf("%d",&n);
	//printf("Mallocing");
	int *mat=(int*)malloc(n*n*sizeof(int));
	//printf("Initializing");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//printf("HO");
			*(mat+i*n+j)=-1;
		}
	}
	//printf("Initialized");
	int loop=n/2;
	if(n%2==0){
		loop=loop-1;
	}
	int start=1;
	for(int sid=0;sid<=loop;sid++){
		start=fill_spiral(n,sid,start,mat);
	}
	printf("\n\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d   ",*(mat+i*n+j));
		}
		printf("\n");
	}
	return 0;
}
int fill_spiral(int n,int sid,int start,int *mat){
	printf("%d,%d,%d\n",n,sid,start);
	printf("STAGE 1\n");
	for(int i=sid;i<n-sid;i++){
		printf("i:%d j:%d\n",sid,i);
		*(mat+n*sid+i)=start;
		start++;
	}
	printf("STAGE 2\n");
	for(int j=sid+1;j<n-sid;j++){
		printf("i:%d j:%d\n",j,n-sid-1);
		*(mat+n*j+n-sid-1)=start;
		start++;
	}
	printf("STAGE 3\n");
	for(int i=n-sid-2;i>=sid;i--){
		printf("i:%d j:%d\n",(n-sid-1),i);
		*(mat+n*(n-sid-1)+i)=start;
		start++;
	}
	printf("STAGE 4\n");
	for(int j=n-sid-2;j>=sid+1;j--){
		printf("i:%d j:%d\n",j,sid);
		*(mat+n*j+sid)=start;
		start++;
	}
	return start;//the next starting point;
}