#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *fp=fopen("input.txt","r");
	//char *c=*fp;
	char buffer[1024];
	fgets(buffer, sizeof(buffer), fp);
	char *tok=strtok(buffer," +-/*.,");
	while(tok!=NULL){
		printf("%s\n",tok);
		tok=strtok(NULL," +-/*.,");
	}
	fclose(fp);
	return 0;
}


//Input file content

//Hello,this is the.test/file-for+code*given in,sd
