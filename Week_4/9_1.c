#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void handle_other_cases(int n,char num[]);

int main(){
	char num[1000000];
	scanf("%[^\n]s",num);
	int len=strlen(num);

	//Case1:
	int all_flag=1;
	for(int i=0;i<len;i++){
		if(num[i]!='9'){
			all_flag=0;
			break;
		}
	}
	if(all_flag==1){
		printf("1");
		for(int i=0;i<len-1;i++){
			printf("0");
		}
		printf("1\n");
		return 0;
	}
	//Case 2 and 3
	else{
		handle_other_cases(len,num);
	}
	printf("%s\n",num);
	return 0;
}
void handle_other_cases(int n,char num[]){
	//n=len here
	int mid=n/2;
	int lp=mid-1;
	int rp;
	if(n%2==1){//means when its odd(len-1 is not taken)
		rp=mid+1;
	}
	else{
		rp=mid;//cuz well automatically
	}

	while(lp>=0 && num[lp]==num[rp]){
		lp--;
		rp++;
	}

	int mid_flag=0;
	if(lp<0 || num[lp]<num[rp]){ //first case will arise when its already palindrom
		mid_flag=1;
	}
	
	while(lp>=0){
		num[rp]=num[lp];//will automatically handle the num[p1] greater than num[p2]
		rp++;
		lp--;
	}
	//hindling the change mid condition
	if(mid_flag==1){
		lp=mid-1;
		int carry=1;
		if(n%2==1){
			num[mid]+=carry;
			if((num[mid]-48)>9){
				carry=1;
				num[mid]='0';
			}
			else{
				carry=0;
			}
			rp=mid+1;
		}
		else{
			rp=mid;
			while(lp>=0){
				num[lp]+=carry;
				if((num[lp]-48)>9){
					carry=1;
					num[lp]='0';
				}
				else{
					carry=0;
				}
				num[rp]=num[lp];
				rp++;
				lp--;
			}
		}
	}
}