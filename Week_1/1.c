#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int count_length(int r,char str[][101]);
int check_pal(int k,char tabl[][k],char *str);

int main(){
	int n;
	scanf("%d",&n);
	char str[n][101];
	for(int i=0;i<n;i++){
		scanf(" %[^\n]s",str[i]);
	}
	printf("######\n");
	// for(int i=0;i<n;i++){
	// 	printf("%s\n",str[i]);
	// }
	for(int i=0;i<n;i++){
		int len=count_length(i,str);
		printf("%d\n",len);
		int k=pow(len,0.5);
		printf("K=%d\n",k);
		if(pow(k,2)!=len){
			printf("NO\n");
		}
		else{
			char tabl[k][k];
			for(int m=0;m<k;m++){
				for(int n=0;n<k;n++){
					tabl[m][n]=str[i][m*k+n];
					printf("%c ",tabl[m][n]);
				}
				printf("\n");
			}
			printf("#######\n");
			int flag=check_pal(k,tabl,str[i]);
			if(flag==0){
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}
		}
	}
	return 0;
}
int count_length(int r,char str[][101]){
	int length=0,i=0;
	while(str[r][i] != '\0'){
		//Dont use double quotes. Its not python
		//printf("%c ",str[r][i]);
		length++;
		i++;
	}
	return length;
}

int check_pal(int k,char tabl[][k],char *str){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			printf("\n%d %d",i,j);
			if(*(str+i*k+j) != tabl[j][i]){
				printf("1. %c %c\n",*(str+i*k+j),tabl[j][i]);
				return 0;
			}
			if(*(str+i*k+j) != tabl[k-i-1][k-j-1]){
				printf("2. %c %c\n",*(str+i*k+j),tabl[k-i-1][k-j-1]);
				return 0;
			}
			if(*(str+i*k+j) != tabl[k-j-1][k-i-1]){
				printf("3. %c %c\n",*(str+i*k+j),tabl[k-j-1][k-i-1]);
				return 0;
			}
		}
	}

	return 1;
}