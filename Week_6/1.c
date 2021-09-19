#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HMAX 10


int main(){
	srand((unsigned int)time(0));
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf(" %d",&arr[i]);
	}
	for(int i=0;i<N;i++){
		printf("%d\n",arr[i]);
	}
	//Initializing requred memory spaces
	int carr[HMAX][3];
	int minarr[HMAX][2];
	int maxarr[HMAX][2];
	for(int i=0;i<HMAX;i++){
		//initializing count array
		carr[i][0]=0;
		carr[i][1]=N;	//min index
		carr[i][2]=-1;	//max index

		//initializing min_arr
		minarr[i][0]=N;	//min ka min
		minarr[i][1]=-1;	//min ka max

		//initializing max arr
		maxarr[i][0]=N;	//max ka min
		maxarr[i][1]=-1;	//max ka max
	}
	printf("DONE1!!!\n");
	//filling the count array
	for(int i=0;i<N;i++){
		carr[arr[i]-1][0]+=1;
		if(carr[arr[i]-1][1]>i){
			carr[arr[i]-1][1]=i;
		}
		if(carr[arr[i]-1][2]<i){
			carr[arr[i]-1][2]=i;
		}
	}
	
	//filling min and max arr
	minarr[0][0]=carr[0][1];
	minarr[0][1]=carr[0][1];
	maxarr[0][0]=carr[0][2];
	maxarr[0][1]=carr[0][2];
	for(int i=1;i<HMAX;i++){
		if(carr[i][0]!=0 && minarr[i-1][0]>=carr[i][1]){
			minarr[i][0]=carr[i][1];
		}
		else{
			minarr[i][0]=minarr[i-1][0];
		}

		if(carr[i][0]!=0 && minarr[i-1][1]<=carr[i][1]){
			minarr[i][1]=carr[i][1];
		}
		else{
			minarr[i][1]=minarr[i-1][1];
		}

		if(carr[i][0]!=0 && maxarr[i-1][0]>=carr[i][2]){
			maxarr[i][0]=carr[i][2];
		}
		else{
			maxarr[i][0]=maxarr[i-1][0];
		}

		if(carr[i][0]!=0 && maxarr[i-1][1]<=carr[i][2]){
			maxarr[i][1]=carr[i][2];
		}
		else{
			maxarr[i][1]=maxarr[i-1][1];
		}
	}

	for(int i=0;i<HMAX;i++){
		//printf("%d %d %d %d %d %d %d\n",carr[i][0],carr[i][1],carr[i][2],minarr[i][0],minarr[i][1],maxarr[i][0],maxarr[i][1]);
	}
	printf("%d\n",1000000007);
	//checking the area of common.
	// int max=0;
	// for(int i=0;i<N;i++){
	// 	int num=arr[i]-1;

	// 	int start=0;
	// 	int end=N;
	// 	int temp_area=0;

	// 	if(num==0){
	// 		temp_arr=N;
	// 	}
	// 	else{
	// 		if(i>minarr[num-1][1]){
	// 			start=minarr[num-1][1];
	// 		}
	// 		else if(i>)
	// 	}
		
	// }

	return 0;
}