#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int modP(int c,int n,int p);

int main(){
	int c,n,p;
	scanf("%d %d %d",&c,&n,&p);
	int ans=modP(c,n,p);
	printf("%d\n",ans);
	return 0;
}

int modP(int c,int n,int p){
	int a=n/2,b=n/2;
	if(n%2!=0){
		b=b+1;
	}
	if(a==1 || b==1){
		return (int)pow(c,n)%p;
	}
	else{
		return (modP(c,a,p)*modP(c,b,p))%p;
	}
	return 0;
}