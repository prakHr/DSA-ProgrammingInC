#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define lli long long int
struct node{
	int pos;
	struct node *next;
};

//Function Definition
int get_Kay(lli num);
struct node * get_digits(lli num);
int evaluation_function(lli n,lli m,int k,lli nCr[][65]);

int main(){
	lli m;
	int k;
	scanf("%lld %d",&m,&k);
	
	//Preprocessing for evaluation function
	lli nCr[64][65]; //maximum number required is around 60 digits in binary
	for(int i=0;i<64;i++){//1,2...64
		for(int j=0;j<=i+1;j++){//0,1,2,....64
			if(i==0 || j==0 || i+1==j){ //i.e n=1 or r=0 or n=r
				nCr[i][j]=1;
			}
			else{
				nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
			}
		}	
	}


	//evaluation_function(m,m,k,nCr);
	//finally
	// lli lo=m,hi=1000000000000000000;
	// lli mid;
	// while(lo<hi){
	// 	mid=(lo+hi)/2;
	// 	int flag=evaluation_function(mid,m,k,nCr);
	// 	printf("n:%lld flag:%d\n",mid,flag);
	// 	if(flag==1){
	// 		hi=mid;
	// 	}
	// 	else{
	// 		lo=mid+1;
	// 	}
	// }

	// printf("N: %lld\n",lo);
	evaluation_function(m,m,13,nCr);

	return 0;
}

int get_Kay(lli num){
	int count=0;
	while(num!=0){
		if(num%2==1){
			count++;
		}
		num=num/2;
	}
	return count;
}

struct node* get_digits(lli num){
	int count=0;
	struct node *head;
	int flag=0;
	while(num!=0){
		count++;
		if(num%2==1){
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->pos=count;
			//printf("count: %d\n",count);
			if(flag==0){
				head=temp;
				temp->next=NULL;
				flag=1;
			}
			else{
				temp->next=head;
				head=temp;
			}
			//printf("%p %p %p\n",head,temp,temp->next);
		}
		num=num/2;
	}
	return head;
}

int evaluation_function(lli n,lli m,int k,lli nCr[][65]){
	int n_k=get_Kay(n);
	struct node *head;
	head=get_digits(n);

	//calculating number of digits with k 1s
	lli before=0;
	if(k==n_k){
		printf("ABHINAV\n");
		before++;
	}
	int count=0;
	while(head!=NULL){
		int pos=(head->pos)-1; 
		lli temp;
		if(k-count<=pos && k-count>=0){ //handling the case when r>n but make sure dont take zero index here(we are doing mathematically)
			temp=nCr[pos-1][k-count];//extra minus 1 due to zero based indexing
		}
		else{
			temp=0;
		}
		printf("pos:%d k:%d count:%d temp: %lld\n",pos,k,count,temp);
		before+=temp;
		head=head->next;
		count++;
	}
	printf("before: %lld\n",before);

	//calculating after
	
	n=2*n;
	int nmax_k=get_Kay(n);
	head=get_digits(n);

	lli after=0;
	if(k==nmax_k){
		after++;
	}
	count=0;
	while(head!=NULL){
		int pos=(head->pos)-1;
		lli temp;
		if(k-count<=pos && k-count>=0){
			temp=nCr[pos-1][k-count];
		}
		else{
			temp=0; //no no need to initialize the full array to zero
		}
		printf("pos:%d k:%d count:%d temp: %lld\n",pos,k,count,temp);
		after+=temp;
		head=head->next;
		count++;
	}
	printf("after: %lld\n",after);

	if((after-before)>=m){//send if possible in this number
		return 1;
	}

	return 0;
}






//printf("%d\n",get_Kay(100000000000000000));
	// lli temp=100000000000000000; will take 63 years
	// for(int i=0;i<temp;i++){
	// 	if(i%100000000000==0){
	// 		printf("Ky!!\n");
	// 	}
	// }


// while(head!=NULL){
// 		printf("%d\n",head->pos);
// 		head=head->next;
// 	}