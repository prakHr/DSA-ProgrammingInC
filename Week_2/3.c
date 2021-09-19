#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;//n is the lines in a program
	scanf("%d",&n);
	char prog[n][500]; //assuming the bredth of the program
	//int line_flag[n];
	for(int i=0;i<n;i++){
		scanf(" %[^\n]s",prog[i]);
		//printf("%s",prog[i]);
	}

	int diffL_flag=0;
	int found_flag=1;
	for(int i=0;i<n;i++){
		//printf("HUMPTY");
		for(int j=0;j<500 && prog[i][j]!='\0';j++){
			printf("YOLO");
			if(found_flag==0){
				printf("FOUND FLAG 0 : i= %d diffL_flag=%d\n",i,diffL_flag);
				if(prog[i][j]=='*' && prog[i][j+1]=='/'){
					prog[i][j]=' ';
					prog[i][j+1]=' ';
					found_flag=1;
					break;
				}
				prog[i][j]=' ';
			}
			else if(prog[i][j]=='/'){
				printf("%d\n",i);
				if(prog[i][j+1]=='/'){
					prog[i][j]='\0';
					break;
				}
				else if(prog[i][j+1]=='*'){
					prog[i][j]=' ';
					prog[i][j+1]=' ';
					found_flag=0;
					diffL_flag=0;
					//prog[i][j]='\0';
					j+=1;
				}
			}
		}
		if(found_flag==0 && diffL_flag==1){
			prog[i][0]='\0';
		}
		diffL_flag=1;
	}

	printf("\n\n");
	for(int i=0;i<n;i++){
		if(prog[i][0]!='\0'){
			printf("%d ",i);
			printf("%s\n",prog[i]);
		}
	}


	/*abh*/return 0;
}