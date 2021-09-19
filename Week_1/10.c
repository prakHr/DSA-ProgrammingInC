#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void multiply_next(int mul,int ans[]);

int main(){
	int n;
	scanf("%d",&n);
	int ans[600]={0}; // Max possible digit.
	ans[599]=1;
	for(int i=1;i<n;i++){
		multiply_next(i+1,ans);
		printf("######\n");
	}
	int flag=0;
	for(int i=0;i<600;i++){
		if(ans[i]!=0 && flag==0){
			flag=1;
		}
		if(flag==1){
			printf("%d",ans[i]);
		}
	}
	printf("\n");
	return 0;
}

void multiply_next(int mul,int ans[]){
	int row[3][600]={0};
	int dig[3];
	for(int i=0;i<3;i++){
		dig[i]=(mul%(int)pow(10,i+1))/pow(10,i);
		mul-=dig[i];
		//printf("%d ",dig[i]);
	}
	//We have to revert the order fo teh digit to proper orientation
	int temp=dig[0];
	dig[0]=dig[2];
	dig[2]=temp;
	for(int i=0;i<3;i++){
		//printf("%d ",dig[i]);
	}
	printf("\n");

	for(int i=3-1;i>=0;i--){
		//assuming that the total digit wont ever reach
		//printf("Digit:%d\n",dig[i]);
		for(int j=600-1;j>5;j--){//Contagious memory so upto 5 cuz dont want to change the other row as going upto -1 col below
			int tMul=ans[j]*dig[i]+row[2-i][j-(2-i)];
			int ones=tMul%10;
			int tens=tMul/10;
			row[2-i][j-(2-i)]=ones;
			row[2-i][j-(2-i)-1]=tens;
			//printf("DIG: %d TENS:%d ONES:%d ROW:%d COL%d DIG%d NEXT%d\n",tMul,tens,ones,2-i,j-(2-i),row[2-i][j-(2-i)],row[2-i][j-(2-i)+1]);
		}
		//printf("%d\n",row[0][599]);
	}

	for(int i=0;i<600;i++){
		ans[i]=0;
	}
	for(int j=600-1;j>0;j--){
		int tSum=row[0][j]+row[1][j]+row[2][j]+ans[j];
		int ones=tSum%10;
		int tens=tSum/10;
		ans[j]=ones;
		ans[j-1]=tens;
		//printf("ANS %d %d\n",ans[j],ans[j-1]);
	}

}