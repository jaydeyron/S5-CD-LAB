// headers and macros
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>

// macros
#define intmax INT_MAX

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*   ignore above, template stuff   */

// global variables
char type[7][100]={{"Identifier"},{"Operator"},{"Keyword"},{"Special symbol"},{"Punctuation"},{"Opening bracket"},{"Closing bracket"}};

// functions
int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int typeCheck(char token[]){
	char operators[15][10] = {"+","-","*","/","%","=","==","<=","<",">=",">"}; // operators
	char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default","do", "double", "else", "enum", "extern", "float", "for",
    "goto", "if", "int", "long", "register", "return", "short","signed", "sizeof", "static", "struct",
    "switch", "typedef","union", "unsigned", "void", "volatile", "while"}; // keywords
	char specialSymbols[15][10] = {"&","~","^","|","<<",">>","#"}; // special symbols
	char punctuation[10][10] = {",",";",".","?","!","\"","'"}; // punctuation
	char openingBracket[10][10] = {"{","[","("}; // opening brackets
	char closingBracket[10][10] = {"}","]",")"}; // closing brackets
	for(int i=0;i<15;i++){
		if(strcmp(token,operators[i])==0){ return 1; }
	}
	for(int i=0;i<32;i++){
		if(strcmp(token,keywords[i])==0){ return 2; }
	}
	for(int i=0;i<15;i++){
		if(strcmp(token,specialSymbols[i])==0){ return 3; }
	}
	for(int i=0;i<10;i++){
		if(strcmp(token,punctuation[i])==0){ return 4; }
	}
	for(int i=0;i<10;i++){
		if(strcmp(token,openingBracket[i])==0){ return 5; }
	}
	for(int i=0;i<10;i++){
		if(strcmp(token,closingBracket[i])==0){ return 6; }
	}
	return 0;
}

// main
int main(){
	FILE *file=fopen("exp1.txt","r");
	if(file==NULL){	printf("Error opening file\n\n");}
	char line[100];
	int currentLine=1;
	printf("\n| %-25s| %-25s| %10s","Token","Type","Line no.\n");
	printf("| %-25s| %-25s| %10s","-----","----","--------\n");
	while(fgets(line,sizeof(line),file)){
		char* token=strtok(line," \t\n");
		while(token!=NULL){
			printf("| %-25s| %-25s| %10d\n",token,type[typeCheck(token)],currentLine);
			token=strtok(NULL," \t\n");
		}
		currentLine++;
	}
	printf("\n");
	fclose(file);
	return 29;
}