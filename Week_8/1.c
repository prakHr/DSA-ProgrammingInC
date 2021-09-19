#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define max INT_MAX
#define min INT_MIN
struct node{
	int idx;
	struct node *prev;
};
void get_angle(int N,int min_idx,float ang[][2],int arr[][2]);
struct node * push(int idx,struct node *tos);
struct node *pop(struct node *tos);
void merge_sort(int low,int high,float arr[][2]);
float get_angle_cos(int idx1,int idx2,int idx3,int arr[][2]);

int main(){
	int N;
	scanf("%d",&N);
	int arr[N][2];
	int min_idx;
	int min_x=max;
	for(int i=0;i<N;i++){
		scanf(" %d %d",&arr[i][0],&arr[i][1]);
		if(arr[i][0]<min_x){
			min_x=arr[i][0];
			min_idx=i;
		}
	}
	
	//getting the sorted array based on angle from min
	float ang[N-1][2];
	get_angle(N,min_idx,ang,arr);
	merge_sort(0,N-2,ang);
	for(int i=0;i<N-1;i++){
		printf("%0.1f %0.1f\n",ang[i][0],ang[i][1]);
	}

	//now selecting the points based on their angle
	struct node *tos=NULL;
	//push the min three point in stack
	tos=push(min_idx,tos);
	tos=push((int)ang[0][0],tos);
	tos=push((int)ang[1][0],tos);

	int idx1=min_idx;
	int idx2=ang[0][0];
	//to compare the last angle with
	float old_ang=get_angle_cos(idx1,idx2,(int)ang[1][0],arr);	

	for(int i=2;i<N-1;i++){
		int idx3=ang[i][0];
		float new_ang=get_angle_cos(idx1,idx2,idx3,arr);
		//there is still place to leftify
		if(new_ang<old_ang){
			tos=pop(tos);
			tos=push(idx3,tos);
			old_ang=new_ang;
		}
		//time to pivot
		else if(ang[i][1]>ang[tos->idx][1]){
			idx1=idx2;
			idx2=tos->idx;
			tos=push(idx3,tos);
		}
	}

	while(tos!=0){
		printf("included id: %d\n",tos->idx);
		tos=pop(tos);
	}
	return 0;
}
void get_angle(int N,int min_idx,float ang[][2],int arr[][2]){
	for(int i=0;i<N-1;i++){
		ang[i][1]=0;
	}
	int count=0;
	for(int i=0;i<N;i++){
		if(i==min_idx){
			continue;
		}
		float base=arr[i][0]-arr[min_idx][0];
		float heig=arr[i][1]-arr[min_idx][1];

		ang[count][0]=i;
		if(base==0){
			if(heig<0){
				ang[count][1]=min;
			}
			else{
				ang[count][1]=max;
			}
			count++;
			continue;
		}
		ang[count][1]=heig/base;
		count++;
	}
}
struct node * push(int idx,struct node *tos){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->idx=idx;
	temp->prev=tos;
	return temp;
}
struct node *pop(struct node *tos){
	struct node *temp=tos->prev;
	free(tos);
	return temp;
}

void merge_sort(int low,int high,float arr[][2]){
	//handling the base case
	if(high==low){
		return;
	}

	//dividing step
	int mid=(high+low)/2;
	merge_sort(low,mid,arr);
	merge_sort(mid+1,high,arr);

	//combining step
	int p1=low;
	int p2=mid+1;
	float temp[high-low+1][2];
	int count=0;
	while(p1<=mid && p2<=high){
		if(arr[p1][1]>arr[p2][1]){
			temp[count][1]=arr[p2][1];
			temp[count][0]=arr[p2][0];
			p2++;
			count++;
		}
		else{
			temp[count][1]=arr[p1][1];
			temp[count][0]=arr[p1][0];
			p1++;
			count++;
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp[count][1]=arr[p2][1];
			temp[count][0]=arr[p2][0];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp[count][1]=arr[p1][1];
			temp[count][0]=arr[p1][0];
			count++;
		}
	}
	for(int i=low;i<=high;i++){
		arr[i][0]=temp[i-low][0];
		arr[i][1]=temp[i-low][1];
	}
}

//will be less when angle is low
float get_angle_cos(int idx1,int idx2,int idx3,int arr[][2]){
	float x1=arr[idx1][0]-arr[idx2][0];
	float y1=arr[idx1][1]-arr[idx2][1];

	float x2=arr[idx3][0]-arr[idx2][0];
	float y2=arr[idx3][1]-arr[idx2][1];

	float cos=(x1*x2+y1*y2)/pow((pow(x1,2)+pow(y1,2))*(pow(x2,2)+pow(y2,2)),0.5);

	return cos;
}