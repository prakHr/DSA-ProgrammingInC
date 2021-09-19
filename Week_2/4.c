#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d",&N);
	int dig[4]={0};
	int temp=10;
	for(int i=0;i<4;i++){
		if(i==0){
			dig[i]=N%temp;
			temp=temp*10;
		}
		else{
			dig[i]=(N%temp)/(temp/10);
			temp=temp*10;
		}
		//printf("%d ",dig[i]);
	}
	for(int i=3;i>=0;i--){
		if(dig[i]!=0 && i!=1){
			switch(dig[i]){
				case 1:
					printf("One");
					break;
				case 2:
					printf("Two");
					break;
				case 3:
					printf("Three");
					break;
				case 4:
					printf("Four");
					break;
				case 5:
					printf("Five");
					break;
				case 6:
					printf("Six");
					break;
				case 7:
					printf("Seven");
					break;
				case 8:
					printf("Eight");
					break;
				case 9:
					printf("Nine");
					break;
				default:
					printf("");

			}

			switch(i){
				case 3:
					printf(" Thousand ");
					break;
				case 2:
					printf(" Hundread ");
					break;
				default:
					printf("");

			}

		}
		if(dig[i]!=0 && i==1){
			switch(dig[i]){
				case 1:
					if(dig[0]==0){
						printf("and Ten");
					}
					else if(dig[0]==1){
						printf("and Eleven");
					}
					else if(dig[0]==2){
						printf("and Twelve");
					}
					else if(dig[0]==3){
						printf("and Thirteen");
					}
					else if(dig[0]==4){
						printf("and Fourteen");
					}
					else if(dig[0]==5){
						printf("and Fifteen");
					}
					else if(dig[0]==6){
						printf("and Sixteen");
					}
					else if(dig[0]==7){
						printf("and Seventeen");
					}
					else if(dig[0]==8){
						printf("and Eighteen");
					}
					else if(dig[0]==9){
						printf("and Nineteen");
					}
					break;
				case 2:
					printf("and Twenty ");
					break;
				case 3:
					printf("and Thirty ");
					break;
				case 4:
					printf("and Fourty ");
					break;
				case 5:
					printf("and Fifty ");
					break;
				case 6:
					printf("and Sixty ");
					break;
				case 7:
					printf("and Seventy ");
					break;
				case 8:
					printf("and Eightty ");
					break;
				case 9:
					printf("and Ninety ");
					break;
				default:
					printf("");

			}
		}
	}
	return 0;
}