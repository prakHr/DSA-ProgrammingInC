#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void rollback(char word[]);
void match_phon(char word[]);

int main(){
	// char t[20]={'a',' ','k',' ','d','\0'};
	// printf("%s\n",t);
	// rollback(t);
	// printf("%s\n",t);

	char file[100];
	scanf("%[^\n]s",file);
	char k[100];
	scanf(" %[^\n]s",k);
	match_phon(k);

	// char d[100];
	// scanf(" %[^\n]s",d);
	// match_phon(d);


	// for(int i=0;i<4;i++){
	// 	printf("%c %c\n",k[i],d[i]);
	// }


	
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
		printf("FILE not found\n");
		return 0;
	}
	char ch=fgetc(fp);
	char word[100]={'\0'}; //assuming typical word length=100
	int arr[100]={0}; //Assuming that max line in file is 100;
	int flag=1;
	int counter=0;
	int line=0;
	while(ch!=EOF){
		if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)){
			flag=0;
			word[counter]=ch;
			counter++;
		}
		else if((ch==' ' || ch=='\n' || 
				ch=='\0' || ch=='.') && flag==0){
			flag=1;
			counter=0;
			match_phon(word);
			int m_flag=1;
			for(int i=0;i<4;i++){
				if(k[i]!=word[i]){
					m_flag=0;
					break;
				}
			}
			if(m_flag==1){
				printf("%d %s\n",line,word);
				arr[line]=1;
			}
			int len=strlen(word);
			for(int i=0;i<len;i++){
				word[i]='\0';
			}
		}
		if(ch=='\n' || ch=='\0'){
			line++;
		}
		ch=fgetc(fp);//read teh next char
	}
	fclose(fp);
	printf("Done Kalpana said!!\n");
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("FILE not found\n");
		return 0;
	}
	ch=fgetc(fp);
	line=0;
	while(ch!=EOF){
		if(arr[line]==1){
			printf("%c",ch);
		}
		if(ch=='\n'){
			line++;
		}
		ch=fgetc(fp);
	}

	return 0;
}

void match_phon(char word[]){
	//48:0 65:A 97:a
	int len=strlen(word);
	for(int i=0;i<len;i++){
		if(word[i]>=97 && word[i]<=122){
			word[i]=(word[i]-97)+65;
		}
	}
	for(int i=0;i<len;i++){
		if(word[i]=='D' && word[i+1]=='G'){
			word[i]='G';
			word[i+1]=' ';
			rollback(word);
		}
		else if(i!=0 && word[i]=='G' && word[i+1]=='H'){
			word[i]='H';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='G' && word[i+1]=='N'){
			word[i]='N';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='K' && word[i+1]=='N'){
			word[i]='N';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='P' && word[i+1]=='H'){
			word[i]='F';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='M' && word[i+1]=='P' &&
				(word[i+2]=='S' || word[i+2]=='Z'
				|| word[i+2]=='T')){
			word[i]='M';
			word[i+1]=' ';
			rollback(word);
		}
		else if(i==0 && word[i]=='P' && word[i+1]=='S'){
			word[i]='S';
			word[i+1]=' ';
			rollback(word);
		}
		else if(i==0 && word[i]=='P' && word[i+1]=='F'){
			word[i]='F';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='M' && word[i+1]=='B'){
			word[i]='M';
			word[i+1]=' ';
			rollback(word);
		}
		else if(word[i]=='T' && word[i+1]=='C' && word[i+2]=='H'){
			word[i]='C';
			word[i+1]='H';
			word[i+2]=' ';
			rollback(word);
		}
	}

	len=strlen(word);//getting the new len after all the rollback
	for(int i=1;i<len;i++){
		if(word[i]=='A' || word[i]=='E' || 
			word[i]=='I' || word[i]=='O' ||
			word[i]=='U' || word[i]=='H' ||
			word[i]=='W' || word[i]=='Y'){
			word[i]=48;
		}
		else if(word[i]=='B' || word[i]=='F' || 
				word[i]=='P' || word[i]=='V' ){
			word[i]=48+1;
		}
		else if(word[i]=='C' || word[i]=='Q' || 
				word[i]=='G' || word[i]=='S' ||
				word[i]=='J' || word[i]=='X' ||
				word[i]=='K' || word[i]=='Z'){
			word[i]=48+2;
		}
		else if(word[i]=='D' || word[i]=='T'){
			word[i]=48+3;
		}
		else if(word[i]=='L'){
			word[i]=48+4;
		}
		else if(word[i]=='M' || word[i]=='N'){
			word[i]=48+5;
		}
		else if(word[i]=='R'){
			word[i]=48+6;
		}
	}
	for(int i=1;i<len;i++){
		if(word[i]==word[i+1]){
			word[i+1]=' ';
			rollback(word);
		}
	}
	len=strlen(word);
	for(int i=1;i<len;i++){
		if(word[i]==48){
			word[i]=' ';
			rollback(word);
		}
	}
	for(int i=1;i<=3;i++){//default size of word will be atleast 20.Dont worry
		if(word[i]=='\0'){
			word[i]=48;
		}
	}
}

void rollback(char word[]){
	int len=strlen(word);
	for(int i=0;i<len;i++){
		if(word[i]==' '){
			for(int j=i+1;j<=len;j++){
				word[j-1]=word[j];
			}
		}
	}
}