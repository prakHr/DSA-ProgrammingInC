#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int M,N;
	scanf("%d %d",&M,&N);
	int folder[M];
	for(int i=0;i<M;i++){
		scanf(" %d",&folder[i]);
	}

	if(M-1<N-1){
		printf("Not possible to use allfriends\n");
		return 0;
	}
	
	int part[N][3];//N partition and their attributes
	for(int i=0;i<N;i++){
		//putting the initial bars one after another
		//later they will flow like heat.
		part[i][0]=folder[i];//contain cumulative sum.
		part[i][1]=i;//starting point(inclusive)
		part[i][2]=i+1;//end of partition(exclusive)
		if(i==N-1){
			part[i][0]=folder[i];
			part[i][1]=i;
			for(int j=N;j<M;j++){
				part[i][0]+=folder[j];
			}
			part[i][2]=M;//exclusive of last just like before.
		}
	}

	for(int i=0;i<N;i++){
		printf("%d %d %d\n",part[i][0],part[i][1],part[i][2]);
	}

	
	return 0;
}

void flow_heat(int N,int part[][3],int folder[]){

}

int transfer(int N,int dir_flag,int which,int part[][3],int folder[]){
	//dir1:right_decrement
	//dir0:left_decrement
	int max_temp=part[which][0];
	if(dir_flag==0){
		int ok_flag=1;
		for(int i=which;i>0;i--){
			int heat_in=folder[part[i][1]];
			int heat_out=folder[part[i-1][1]];
			int c_temp=part[i-1][0];
			if(i==1 && (c_temp)+heat_in>max_temp){
				ok_flag=0;
			}
			else if(c_temp+heat_in-heat_out>max_temp){
				ok_flag=0;
				break;
			}
		}
		if(ok_flag==1){//meaning the flow is fine and dosent increase the max_temp
			int max_heat_out=folder[part[i][1]];
			part[which][0]=max_temp-max_heat_out;
			part[which][1]+=1;
			for(int i=which;i>0;i--){
				int heat_in=folder[part[i][1]];
				int heat_out=folder[part[i-1][1]];
				int c_temp=part[i-1][0];
				if(i==1){
					part[i-1][0]=c_temp+heat_in;
					part[i-1][2]+=1;
				}
				else{
					part[i-1][0]=c_temp+heat_in-heat_out;
					part[i-1][2]+=1;
					part[i-1][1]+=1;
				}
			}
		}
		return ok_flag;
	}
	else{
		int ok_flag=1;
		for(int i=which;i<N-1;i++){//moving to last partitons 
			int heat_in=folder[part[i][2]-1];
			int heat_out=folder[part[i+1][2]-1];
			int c_temp=part[i+1][0];
			if(i==N-2 && (c_temp+heat_in)>max_temp){
				ok_flag=0;
			}
			else if(c_temp+heat_in-heat_out>max_temp){
				ok_flag=0;
				break;
			}
		}
		if(ok_flag==1){
			int max_heat_out=folder[part[which][2]-1];
			part[which][0]=max_temp-max_heat_out;
			part[which][2]-=1;
			for(int i=which;i<N-1;i++){
				int heat_in=folder[part[i][2]-1];
				int heat_out=folder[part[i+1][2]-1];
				int c_temp=part[i+1][0];
				if(i==N-2){
					part[i+1][0]=c_temp+heat_in;
					part[i+1][1]-=1;
				}
				else{
					part[i+1][0]=c_temp+heat_in-heat_out;
					part[i+1][1]-=1;
					part[i+1][2]-=1;
				}
			}
		}
	}
}