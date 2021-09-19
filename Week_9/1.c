#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define size 10
#define def INT_MIN //default value for hashtable
#define dum INT_MAX	//when we will put dummy after deleting
void insert(int val,int hash[]);
void print(int hash[]);
void search(int val,int hash[]);
void delete(int val,int hash[]);

int main(){
	int hash[size];
	for(int i=0;i<size;i++){
		hash[i]=def;
	}
	int choice;
	scanf("%d",&choice);
	while(1){
		if(choice==1){
			int val;
			scanf(" %d",&val);
			insert(val,hash);
			printf("Done\n");
		}
		else if(choice==2){
			print(hash);
			printf("Done\n");
		}
		else if(choice==3){
			int val;
			scanf(" %d",&val);
			search(val,hash);
			printf("Done\n");
		}
		else if(choice==4){
			int val;
			scanf(" %d",&val);
			delete(val,hash);
			printf("Done\n");
		}
		scanf(" %d",&choice);
	}
	return 0;
}

void insert(int val,int hash[]){
	printf("Inserting into Hash Table\n");
	int key=val%size;
	if(hash[key]==def || hash[key]==dum){
		hash[key]=val;
		return;
	}
	//since we know that quadratic probing is capable of giving
	//us a sequence of index of permutation from 0...m-1
	//still we will count to know if hash is full
	else{
		int count=1;
		while(count!=size){
			int pkey=(key+count*count)%size;
			count++;
			if(hash[pkey]==def || hash[pkey]==dum){
				hash[pkey]=val;
				return;
			}
		}
		printf("Hash Table Full\n");
	}
}
void print(int hash[]){
	printf("Printing Hash Table\n");
	for(int i=0;i<size;i++){
		printf("%d %d\n",i,hash[i]);
	}
	printf("Printed\n");
}
void search(int val,int hash[]){
	int key=val%size;
	int found=0,last_key=-1;
	int lazy_key=-1;
	if(hash[key]==val){
		printf("Found at %d\n",key);
		return;
	}
	else{
		if(hash[key]==dum){
			lazy_key=key;
		}
		int count=1;
		while(count!=size){
			int pkey=(key+count*count)%size;
			if(hash[pkey]==val){
				printf("Found at: %d\n",pkey);
				found=1;
				last_key=pkey;
			}
			else if(hash[pkey]!=def && hash[pkey]!=dum){
				last_key=pkey;
			}
			else if(hash[pkey]==def){
				break;
			}
			else if(hash[pkey]==dum && lazy_key==-1){
				lazy_key=pkey;
			}
			count++;
		}
	}
	if(found==1){
		printf("HOHO %d %d\n",last_key,lazy_key);
		hash[lazy_key]=hash[last_key];
		hash[last_key]=def;
		return;
	}
	printf("Not Found\n");
}
void delete(int val,int hash[]){
	int key=val%size;
	if(hash[key]==val){
		hash[key]=dum; //putting the dummy
		return;
	}
	else{
		int count=1;
		while(count!=size){
			int pkey=(key+count*count)%size;
			if(hash[pkey]==val){
				hash[pkey]=dum;
				return;
			}
			else if(hash[pkey]==def){
				//ie. gap is found and not dummy to carry over
				break;
			}
			count++;
		}
	}
	printf("Not Found\n");
}