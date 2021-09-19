#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void merge_sort(int low,int high,int sortid,int arr[][2]);
void div_conq_pt(int *p1,int *p2,int low,int high,int N,int xarr[][2],int yarr[][2]);
float get_distance(int p1,int p2,int xarr[][2]);

int main(){
	int N;
	scanf("%d",&N);
	int xarr[N][2];
	int yarr[N][2];
	for(int i=0;i<N;i++){
		scanf(" %d %d",&xarr[i][0],&xarr[i][1]);
		yarr[i][0]=xarr[i][0];
		yarr[i][1]=xarr[i][1];
	}

	merge_sort(0,N-1,1,xarr);
	merge_sort(0,N-1,2,yarr);
	
	int p1=-1,p2=-1;
	div_conq_pt(&p1,&p2,0,N-1,N,xarr,yarr);
	printf("%d %d\n",p1,p2);

	return 0;
}

void merge_sort(int low,int high,int sortid,int arr[][2]){
	//handling the base case
	if(high==low){
		return;
	}

	//Dividing the Problem
	int mid=(high+low)/2;
	merge_sort(low,mid,sortid,arr);
	merge_sort(mid+1,high,sortid,arr);

	//Merging the problem
	int p1=low;
	int p2=mid+1;
	int temp[high-low+1][2];
	int count=0;
	while(p1<=mid && p2<=high){
		if(sortid==1){//sort by xaxis
			if(arr[p1][0]>arr[p2][0]){
				temp[count][0]=arr[p2][0];
				temp[count][1]=arr[p2][1];
				count++;
				p2++;
			}
			else{
				temp[count][0]=arr[p1][0];
				temp[count][1]=arr[p1][1];
				count++;
				p1++;
			}
		}
		else{
			if(arr[p1][1]>arr[p2][1]){
				temp[count][0]=arr[p2][0];
				temp[count][1]=arr[p2][1];
				count++;
				p2++;
			}
			else{
				temp[count][0]=arr[p1][0];
				temp[count][1]=arr[p1][1];
				count++;
				p1++;
			}
		}
	}
	if(p1>mid){
		for(int i=p2;i<=high;i++){
			temp[count][0]=arr[i][0];
			temp[count][1]=arr[i][1];
			count++;
		}
	}
	else{
		for(int i=p1;i<=mid;i++){
			temp[count][0]=arr[i][0];
			temp[count][1]=arr[i][1];
			count++;
		}
	}

	//saving the solution
	for(int i=low;i<=high;i++){
		arr[i][0]=temp[i-low][0];
		arr[i][1]=temp[i-low][1];
	}
}


void div_conq_pt(int *p1,int *p2,int low,int high,int N,int xarr[][2],int yarr[][2]){
	//handling the base case
	if(high==low){//high and low are index so it means that we came to end
		*p1=low;	//its min with itself
		*p2=low;	//they are the index of the points
		return;
	}

	//dividing the problem
	int mid=(high+low)/2;
	int tp1,tp2,tp3,tp4;
	tp1=tp2=tp3=tp4=-1;
	div_conq_pt(&tp1,&tp2,low,mid,N,xarr,yarr);
	div_conq_pt(&tp3,&tp4,mid+1,high,N,xarr,yarr);

	//conquering
	float d1=get_distance(tp1,tp2,xarr);
	float d2=get_distance(tp3,tp4,xarr);
	float d = d1<d2 ? d1:d2;

	if(d1==0){
		d=d2;
	}
	else if(d2==0){
		d=d1;
	}
	printf("l:%d m:%d h:%d\n",low,mid,high);
	printf("p1:%d p2:%d p3:%d p4:%d\n",tp1,tp2,tp3,tp4);
	printf("%f\n",d);

	if(tp1==tp2 && tp3==tp4){
		*p1=tp1;
		*p2=tp3;
		return;//if only two points are there
	}
	
	int found=0;
	//here each time we are running O(n). Will this still make nlogn overall
	//i guess yeas. or fing better way. even first getting the points in that 
	//range will take  O(n) time
	for(int i=N-1;i>=0;i--){
		int j=i-1;
		float dist=d-1;
		while(dist<d && j>=0){
			printf("i:%d j:%d\n",i,j);
			dist=get_distance(i,j,yarr);
			if(dist<d){
				d=dist;
				tp1=i;	//for now saving in tp1 as the answer is this or in this loop now
				tp2=j;
				found=1;
			}
			j--;
		}
	}
	printf("%d p1:%d p2:%d\n",found,tp1,tp2);
	//saving the result in tp3 and tp4
	if(found==1){
		for(int i=0;i<N;i++){
			if(xarr[i][0]==yarr[tp1][0] && xarr[i][1]==yarr[tp1][1]){
				tp3=i;
			}
			if(xarr[i][0]==yarr[tp2][0] && xarr[i][1]==yarr[tp2][1]){
				tp4=i;
			}
		}
	}
	else{
		if(d2==0 || (d1<d2 && d1!=0)){
			tp3=tp1;
			tp4=tp2;
		}
	}

	//finally putting the point in p1 and p2
	*p1=tp3;
	*p2=tp4;
	printf("p3:%d p4:%d\n\n",tp3,tp4);
	return;
}

float get_distance(int p1,int p2,int xarr[][2]){
	//even the square of the distance will be fine for comparison
	float dist=pow((xarr[p1][0]-xarr[p2][0]),2)+pow((xarr[p1][1]-xarr[p2][1]),2);
	return dist;
}
