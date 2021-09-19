#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define maxi 100

void gotta_print_them_all(int *count,int low,int high,char str[],int len,int plen[][len]);
int check_palindrom(int low,int high,char str[]);
void fill_plen_matrix(char str[],int len,int plen[][len]);

int main(){
	char str[maxi];
	scanf("%[^\n]s",str);
	int len=strlen(str);

	int plen[len][len];
	fill_plen_matrix(str,len,plen);
	int count=0;
	gotta_print_them_all(&count,0,len-1,str,len,plen);
	printf("Minimum sub-str: %d\n",count);
	return 0;
}
int check_palindrom(int low,int high,char str[]){
	int i,j;
	for(i=low,j=high; i<=j; i++,j--){
		if(str[i]!=str[j]){
			return 0;
		}
	}
	return 1;
}

void fill_plen_matrix(char str[],int len,int plen[][len]){
	//minimum length of palindrom will be on
	//ie. with itself
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			int flag=check_palindrom(i,j,str);
			if(flag==1){
				plen[i][j]=j-i+1;
				plen[j][i]=j-i+1;
			}
			else{
				plen[i][j]=plen[j][i]=0;
			}
		}
	}

	//printing the matrix
	printf("Printing the Matrix\n");
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			printf("%d ",plen[i][j]);
		}
		printf("\n");
	}
}

void gotta_print_them_all(int *count,int low,int high,char str[],int len,int plen[][len]){
	//handling the abse case
	if(low>high){
		return;
	}
	else if(low==high){
		*count+=1;
		printf("%c\n",str[low]);
		return;
	}

	//(ASK swami)
	//Taking greedy route to get the max possible length 
	//substring as palindrom
	int max=0;
	int midi=-1;
	int midj=-1;
	for(int i=low;i<=high;i++){
		for(int j=i;j<=high;j++){
			if(plen[i][j]>max){
				max=plen[i][j];
				midi=i;
				midj=j;
			}
		}
	}
	*count+=1;
	for(int i=midi;i<=midj;i++){
		printf("%c",str[i]);//printing the sub string
	}
	//plen[midi][midj]=0;//removing this as printed(no need)
	//plen[midj][midi]=0;
	printf("\n");
	//in worst case we will always get a letter as palindrom

	//DIVIDING into sub problems
	//left subproblem
	int l1=low;
	int h1=midi-1;
	//printf("l1:%d h1:%d\n",l1,h1);
	gotta_print_them_all(count,l1,h1,str,len,plen);
	//right subproblem
	int l2=midj+1;
	int h2=high;
	//printf("l2:%d h2:%d\n",l2,h2);
	gotta_print_them_all(count,l2,h2,str,len,plen);
}