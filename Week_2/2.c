#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char c_num[100]; //Assuming the max dig len=100
	scanf("%[^\n]s",c_num);
	int len=strlen(c_num);
	//printf("%d",len);
	int check_dig=c_num[len-1]-48;
	printf("check_dig: %d\n",check_dig);
	int sum=0;
	for(int i=0;i<(len-1);i++){
		int num=c_num[i]-48;
		if((len-1)%2==0){//then the position o/ev will change
			printf("act_sublen EVEN\n");
			if((i+1)%2==0){//they will come to odd
				num=num*2;
				if(num>9){
					int ones=num%10;
					int tens=num/10;
					sum=sum+ones+tens;
				}
				else{
					sum+=num;
				}
			}
			else{
				sum+=num;
			}
		}
		else{
			printf("actual sublen ODD\n");
			if((i+1)%2!=0){//they will come to odd
				printf("   %d\n",num);
				num=num*2;
				if(num>9){
					int ones=num%10;
					int tens=num/10;
					sum=sum+ones+tens;
				}
				else{
					sum+=num;
				}
			}
			else{
				sum+=num;
			}
			printf("sum: %d\n",sum);
		}
	}

	if((sum+check_dig)%10==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}