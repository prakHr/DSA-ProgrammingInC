#include <stdio.h>
#include <string.h>
#include <math.h> //ceil,floor
#include <stdlib.h>//srand,rand
#include <time.h> //time
long long int med_of_med(int n,long long int arr[]);
void insertion_sort(int start,int end,long long int arr[]);
void find_kth_largest(long long int *num,int mid,int n,long long int arr[]);

int main(){
	int n;
	scanf("%d",&n);
	//giving the seed to the random number generator
	srand((unsigned int)time(0));

	long long int arr[n];
	for(int i=0;i<n;i++){
		//arr[i]=rand();
		scanf(" %lld",&arr[i]);
	}
	for(int i=0;i<n;i++){
		//printf("%lld ",arr[i]);
	}
	//printf("\n");
	//insertion_sort(0,n-1,arr);
	for(int i=0;i<n;i++){
		printf("%lld ",arr[i]);
	}
	printf("\n");
	long long int med=-1;
	find_kth_largest(&med,n/2+1,n,arr);
	printf("MED: %lld\n",med);

	return 0;
}

void find_kth_largest(long long int *num,int mid,int n,long long int arr[]){
	long long int med=med_of_med(n,arr);
	int l_count=0;//lower than the median
	for(int i=0;i<n;i++){
		if(arr[i]<med){//assuming there are no multiple elemets of medain
			l_count++;
		}
	}
	if(l_count==mid-1){
		*num=med;
		return;
	}
	else if(l_count>=mid){
		printf("Inside lower side:\n");
		printf("lc:%d med:%lld mid:%d n:%d\n",l_count,med,mid,n);
		long long int split_arr[l_count];
		l_count=0;
		for(int i=0;i<n;i++){
			if(arr[i]<med){
				split_arr[l_count]=arr[i];
				l_count++;
			}
		}
		find_kth_largest(num,mid,l_count,split_arr);
	}
	else if(l_count<mid-1){
		printf("Inside upper side:\n");
		printf("lc:%d med:%lld mid:%d n:%d\n",l_count,med,mid,n);
		long long int split_arr[n-l_count-1];
		int u_count=0;
		for(int i=0;i<n;i++){
			if(arr[i]>med){
				split_arr[u_count]=arr[i];
				u_count++;
			}
		}
		find_kth_largest(num,mid-(l_count+1),u_count,split_arr);
	}

}

long long int med_of_med(int n,long long int arr[]){
	printf("Printing array:\n");
	for(int i=0;i<n;i++){
		printf("%lld\n",arr[i]);
	}
	int bucket_size=5;//WHY????
	int num_buckets=(int)ceil((float)n/bucket_size);
	if(num_buckets==1){
		insertion_sort(0,n-1,arr);
		return arr[n/2];
	}

	//sorting each bucket O(N) actually ~2N
	for(int i=0;i<num_buckets;i++){
		int start=i*5;
		int end=start+5-1;
		if(end>(n-1)){
			end=n-1;
		}
		insertion_sort(start,end,arr);
	}

	//~O(N/5)
	long long int med_arr[num_buckets];
	for(int i=0;i<num_buckets;i++){
		if(i==num_buckets-1){
			int num_last=n%5;
			//Doubt in choosing
			med_arr[i]=arr[i*5+num_last/2]; //taking the middle ele even if it might contain even ele
		}
		else{
			med_arr[i]=arr[i*5+2];
		}
	}

	printf("Printing med arr:\n");
	for(int i=0;i<num_buckets;i++){
		printf("%lld ",med_arr[i]);
	}
	printf("\n");

	return med_of_med(num_buckets,med_arr);
}


void insertion_sort(int start,int end,long long int arr[]){//in zero based indexing
	for(int i=start+1;i<=end;i++){
		for(int j=i-1;j>=start;j--){
			int flag=0;
			if(arr[j+1]<arr[j]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
			if(flag==0){
				break;
			}
		}
	}
}