#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge_sort(int low,int high,int arr[][2]);


int main(){
	int n;
	scanf("%d",&n);
	char str[n][100];
	for(int i=0;i<n;i++){
		scanf(" %[^\n]s",str[i]);
	}
	int num[n][2];
	for(int i=0;i<n;i++){
		num[i][1]=strlen(str[i]);
		num[i][0]=i;//index of the number
	}

	//sorting just by length.
	merge_sort(0,n-1,num);

	//reordering according to length
	char temp_str[n][100];
	for(int i=0;i<n;i++){
		//printf("%d %d\n",num[i][0],num[i][1]);
		strcpy(temp_str[i],str[i]);
	}
	for(int i=0;i<n;i++){
		strcpy(str[i],temp_str[num[i][0]]);
	}
	

	
	//sorting now the elemets of same length;
	//int start=0,end=0;
	for(int i=0;i<n;i++){
		// start=i;
		// end=i;
		int j=i,flag=0;
		do{
			j++;
			if(j==n){
				flag=1;
			}
			if(num[j][1]!=num[j-1][1]){
				flag=1;
			}
		}while(flag==0);
		j--;//the end point of common

		printf("    start and end: %d %d\n",i,j);
		
		//now checking all the digits and then sorting
		int len=strlen(str[i]);
		for(int l=0;l<len;l++){
			int arr[j-i+1][2];
			for(int k=i;k<=j;k++){
				arr[k-i][0]=k;//index
				arr[k-i][1]=str[k][l]-48;//number
				//printf("index: %d %d\n",arr[k-i][0],arr[k-i][1]);
			}
			merge_sort(0,j-i+1-1,arr);
			//Reshuffling according to this columns number
			char temp[j-i+1][100];
			for(int k=i;k<=j;k++){
				strcpy(temp[k-i],str[k]);
			}
			for(int k=i;k<=j;k++){
				strcpy(str[k],temp[arr[k-i][0]-i]);
			}
			
		}
		i=j;
	}

	for(int i=0;i<n;i++){
		printf("%s\n",str[i]);
	}

	return 0;
}

void merge_sort(int low,int high,int arr[][2]){
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
	int temp_arr[high-low+1][2];
	int count=0;
	while(p1<=mid && p2<=high){
		//*cp=*cp+1;
		if(arr[p1][1]>arr[p2][1]){
			temp_arr[count][0]=arr[p2][0];
			temp_arr[count][1]=arr[p2][1];
			p2++;
			count++;
		}
		else{
			temp_arr[count][0]=arr[p1][0];
			temp_arr[count][1]=arr[p1][1];
			p1++;
			count++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp_arr[count][0]=arr[i][0];
			temp_arr[count][1]=arr[i][1];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp_arr[count][0]=arr[i][0];
			temp_arr[count][1]=arr[i][1];
			count++;
		}
	}
	for(int i=low;i<=high;i++){
		arr[i][0]=temp_arr[i-low][0];
		arr[i][1]=temp_arr[i-low][1];
	}
}