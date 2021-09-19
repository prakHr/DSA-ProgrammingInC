#include <stdio.h>
#include <math.h>
#include <stdlib.h> //int abs(int)
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int N;
		scanf("%d",&N);
		int height[N],cost[N];
		//printf("N %d\n",N);
		for(int i=0;i<N;i++){
			scanf("%d",&height[i]);
			//printf("height: %d\n",height[N]);
		}
		for(int i=0;i<N;i++){
			scanf("%d",&cost[i]);
		}

		//O(n)*O(max_height-min_height)=O(20000N)=O(N)here
		//Finding the maximum and minimum elements
		int max=0;
		int min=20000; //max height
		for(int i=0;i<N;i++){
			if(height[i]>max){
				max=height[i];
			}
			if(height[i]<min){
				min=height[i];
			}
		}
		//printf("min: %d max: %d\n",min,max);
		//now iterating through all those heights
		int min_cost=0;
		for(int i=min;i<=max;i++){
			int tot_cost=0;
			for(int j=0;j<N;j++){
				int dist=abs(height[j]-i);
				tot_cost+=dist*cost[j];
			}
			if(i==min){
				min_cost=tot_cost;
			}
			else if(tot_cost<min_cost){
				min_cost=tot_cost;
			}
		}
		printf("Cost: %d\n",min_cost);
	}
	return 0;
}