#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	int lr[n][2];//0 mein l and 1 mein r
	int time_min=-1;
	int time_max=-1;
	int done_flag[n];//either gone or taken
	int time_flag[n];//time at which he takes
	for(int i=0;i<n;i++){
		scanf(" %d %d",&lr[i][0],&lr[i][1]);
		if(i==0){
			time_max=lr[i][0]+lr[i][1];
		}
		else if((lr[i][0]+lr[i][1])>time_max){
			time_max=lr[i][0]+lr[i][1];
		}
		done_flag[i]=0;//not yet ("done" taking or fed up and gone)
		time_flag[i]=0;//default time
	}
	time_min=lr[0][0];

	for(int i=time_min;i<=time_max;i++){
		int give_flag=0;
		int count=0;
		for(int j=0;j<n;j++){
			if(done_flag[j]==1){
				count++;
			}
			if(give_flag==0 && done_flag[j]==0 && lr[j][1]>0){
				done_flag[j]=1;
				time_flag[j]=i;
				give_flag=1;
				count++;
			}
			if(done_flag[j]==0){//jo abhi nahi "done" hue unka time kam karo
				lr[j][1]--;
			}
			if(lr[j][1]==0 && done_flag[j]==0){
				done_flag[j]=1;
				count++;
			}
		}
		if(count==n){
			printf("Time of break: %d\n",i);
			break;
		}
	}

	for(int i=0;i<n;i++){
		printf("time_%d: %d time_left:%d\n",i,time_flag[i],lr[i][1]);
	}

	return 0;
}