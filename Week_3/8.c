#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void merge_sort(int low,int high,int arr[]);

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int score[n];
	int success[n];
	for(int i=0;i<n;i++){
		scanf(" %d",&score[i]);
		success[i]=-14;
		printf("%d ",score[i]);
	}
	printf("\n");
	int start=0;
	int end=-1;//so that after m cycle the index is at m-1(0 based)
	for(int i=0;i<n;i++){
		printf("       i:%d start:%d end:%d\n",i,start,end);
		if(i<m){
			end++;
			success[i]=-1;
		}
		else{
			int first_num=score[start];
			if(i==m){
				merge_sort(start,end,score);//O(mlogm) but just for one case
				for(int j=0;j<n;j++){
					printf("%d ",score[j]);
				}
				printf("\n");
			}
			else{//O(m)
				for(int j=end;j>start;j--){
					if(score[j]<score[j-1]){
						int temp=score[j];
						score[j]=score[j-1];
						score[j-1]=temp;
					}
				}
				for(int j=0;j<n;j++){
					printf("%d ",score[j]);
				}
				printf("\n");
			}
			//Finding out the median.(O(1))
			int median;
			printf("calculating Median:\n");
			if(m%2==0){
				int num1=score[start+((end-start)/2)];
				int num2=score[start+((end-start)/2)+1];
				median=(num1+num2)/2;
				
			}
			else{
				median=score[start+(end-start)/2];
			}
			printf("Median: %d\n",median);

			//updaticng the success/faluire flag(O(1))
			if(score[i]>3*median){
				success[i]=1;
			}
			else{
				success[i]=0;
			}
			printf("Success: %d\n",success[i]);
			//Post processing work(O(m)) only cuz it will run for only
			for(int k=start;k<=end;k++){
				if(score[k]==first_num){
					//removing this element and sliding rest num forward.
					for(int j=k;j>start;j--){
						score[j]=score[j-1];
					}
					break;
				}
			}
			for(int j=0;j<n;j++){
				printf("%d ",score[j]);
			}
			printf("\n");
			start++;
			end++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",success[i]);
	}
	printf("\n");
	return 0;
}

void merge_sort(int low,int high,int arr[]){
	if(high==low){
		return;
	}

	//Dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//Merging step
	int p1=low;
	int p2=mid+1;
	int temp_arr[high-low+1];
	int count=0;
	while(p1<=mid && p2<=high){
		//*cp=*cp+1;
		if(arr[p1]>arr[p2]){
			temp_arr[count]=arr[p2];
			p2++;
			count++;
		}
		else{
			temp_arr[count]=arr[p1];
			p1++;
			count++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
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
	for(int i=low;i<=high;i++){
		arr[i]=temp_arr[i-low];
	}
}