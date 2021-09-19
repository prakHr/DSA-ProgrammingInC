#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void merge_inplace(int N,int K,int step_size,int arr[]);

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	int arr[N*K];//all taken into one single big array

	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			scanf(" %d",&arr[i*K+j]);
		}
	}
	
	merge_inplace(N,K,2*K,arr);

	for(int i=0;i<N*K;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void merge_inplace(int N,int K,int step_size,int arr[]){
	//assuming step_size=2K
	printf("\nstep_size: %d\n",step_size);
	if(step_size>N*K){
		if(N%2!=0){
			printf("Handling\n");
				//handling the case when N is not even multiple of K 
			//extra complexity of NK
			int start=0;
			int mid=(N*K-1)-K; //end of pirst subpart
			int end=N*K-1;
			int temp_arr[N*K];
			int p1=start;
			int p2=mid+1;
			int count=0;
			while(p1<=mid && p2<=end){
				if(arr[p1]<=arr[p2]){
					temp_arr[count]=arr[p1];
					count++;
					p1++;
				}
				else{
					temp_arr[count]=arr[p2];
					count++;
					p2++;
				}
			}
			if(p1>mid){
				for(int i=p2;i<=end;i++){
					temp_arr[count]=arr[i];
					count++;
				}
			}
			else{
				for(int i=p1;i<=mid;i++){
					temp_arr[count]=arr[i];
					count++;
				}
			}

			//rebsubmitting it into array;
			for(int i=start;i<=end;i++){
				arr[i]=temp_arr[i-start];
			}
		}
		return;
	}
	int steps=(N*K)/step_size;
	printf("STEPS: %d\n",steps);
	for(int i=1;i<=steps;i++){
		int start=(i-1)*step_size;
		int end=i*step_size-1;		//actual end
		int mid=start+step_size/2-1;//contains the end of first half 
		
		printf("i:%d start:%d mid:%d end:%d\n",i,start,mid,end);
		int p1=start;
		int p2=mid+1;
		int temp_arr[end-start+1];
		int count=0;
		while(p1<=mid && p2<=end){
			if(arr[p1]<=arr[p2]){
				temp_arr[count]=arr[p1];
				count++;
				p1++;
			}
			else{
				temp_arr[count]=arr[p2];
				count++;
				p2++;
			}
		}
		if(p1>mid){
			for(int j=p2;j<=end;j++){
				temp_arr[count]=arr[j];
				count++;
			}
		}
		else{
			for(int j=p1;j<=mid;j++){
				temp_arr[count]=arr[j];
				count++;
			}
		}

		//rebsubmitting it into array;
		for(int j=start;j<=end;j++){
			arr[j]=temp_arr[j-start];
		}
	}
	merge_inplace(N,K,2*step_size,arr);
}