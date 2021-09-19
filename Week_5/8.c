#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void stable_sort(int max,int n,int sum[][2]);
int get_Kay(int num);


int main(){
	int n;
	scanf("%d",&n);
	char str[n][100]; //assuming 100 to the max
	for(int i=0;i<n;i++){
		scanf(" %[^\n]s",str[i]);
	}
	int sum[n][2];
	int max=0;
	for(int i=0;i<n;i++){
		int len=strlen(str[i]);
		int sum_str=0;
		for(int j=0;j<len;j++){
			sum_str+=str[i][j];
		}
		sum[i][0]=i; 				//holding index
		//sum[i][1]=sum_str;		//holding the ascii sum(not needed to store)
		sum[i][1]=get_Kay(sum_str); //holding the number of ones
		printf("%d %d %d\n",len,sum_str,sum[i][1]);
		if(i==0){
			max=sum[i][1];
		}
		else if(sum[i][1]>max){
			max=sum[i][1];
		}
	}
	printf("Done Preprocessing\n");

	//Stable sorting with index
	stable_sort(max,n,sum);
	printf("Printing the sorted str\n");
	for(int i=0;i<n;i++){
		printf("%s",str[sum[i][0]]);
		printf("\n");
	}
	return 0;
}

int get_Kay(int num){
	int count=0;
	while(num!=0){
		if(num%2==1){
			count++;
		}
		num=num/2;
	}
	return count;
}

void stable_sort(int max,int n,int sum[][2]){
	int count[max+1]; //taking 0 also as possible due to empty string
	for(int i=0;i<=max;i++){
		count[i]=0;
	}
	//getting the count of each number
	for(int i=0;i<n;i++){
		count[sum[i][1]]+=1;
	}
	//getting cumulative sum
	for(int i=1;i<=max;i++){
		count[i]+=count[i-1];
	}
	printf("Priting cumulative sum:\n");
	for(int i=0;i<=max;i++){
		printf("%d\n",count[i]);
	}

	//now sorting stably.
	int temp_arr[n][2];
	for(int i=n-1;i>=0;i--){
		int prev=count[sum[i][1]]-1;//1 extra minus for zero indexed place
		temp_arr[prev][0]=sum[i][0];
		temp_arr[prev][1]=sum[i][1];
		count[sum[i][1]]--;
	}

	//copying back to sum;
	for(int i=0;i<n;i++){
		sum[i][0]=temp_arr[i][0];
		sum[i][1]=temp_arr[i][1];
	}
}