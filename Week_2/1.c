#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int get_seq_val(int ops[]);
int perform_op(int val,int start,int end,int op);
void find_sequence(int op_idx,int ops[]);
void print_sequence(int ops[]);

int main(){
	int ops[8];
	//int op_done_flag[8][3]={0};
	for(int i=0;i<8;i++){
		ops[i]=1;//initialization with all addition
	}
	//ops[2]=2;
	//ops[6]=3; //this yields 100
	//Testing for the all sum seq
	printf("Testing\n");
	int val=get_seq_val(ops);
	printf("Initial value: %d\n",val);

	//Brute Force Approach(O(n^8))
	find_sequence(0,ops);
	printf("\n");
	return 0;
}

int perform_op(int val,int start,int end,int op){
	int b=0,temp=1;
	for(int i=end;i>=start;i--){
		//(i+2)is the second argument given the op index i
		b=b+(i+2)*temp;
		temp=temp*10;
	}
	if(op==1){//add
		return val+b;
	}
	else if(op==2){//subs
		return val-b;
	}
	else if(op==3){//nothing
		return (start+1)*temp+b; //automatically temp has nect factor of 10 to multiply
		//this case is only possible when the first op is augment, else never
	}
	return 0;
}

int get_seq_val(int ops[]){
	int val=1;//first element
	for(int i=0;i<8;i++){
		//printf("\nOperation %d %d\n",i,ops[i]);
		int j=i;
		do{
			j=j+1;
		}while(ops[j]==3);
		j=j-1; //for getting the next
		//printf("j=%d\n",j);
		val=perform_op(val,i,j,ops[i]);
		//printf("val: %d\n",val);
		i=j;//necessary(to move the pointer of op)
	}
	return val;
}

void find_sequence(int op_idx,int ops[]){
	//Copy the op for not changing in recursive step
	int new_ops[8];
	for(int i=0;i<8;i++){
		new_ops[i]=ops[i];
	}

	if(op_idx==8){
		int val=get_seq_val(new_ops);
		if(val==100){
			print_sequence(new_ops);
		}
		return;
	}
	else{
		for(int i=1;i<=3;i++){
			new_ops[op_idx]=i;
			find_sequence(op_idx+1,new_ops);
		}
	}
}

void print_sequence(int ops[]){
	printf("\n");
	for(int i=0;i<8;i++){
		printf("%d ",i+1);
		if(ops[i]==1){
			printf("%c ",'+');
		}
		else if(ops[i]==2){
			printf("%c ",'-');
		}
		else if(ops[i]==3){
			printf("%c ",' ');
		}
	}
	printf("%d",9);
}