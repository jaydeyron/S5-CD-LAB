%{ 
#include<stdio.h>
%}

%%
[A-Z] {printf("%s is an uppercase\n",yytext);}
[a-z] {printf("%s is a lowercase\n",yytext);}

[\t|\n];
%%

int main()
{
	printf("Enter string: ");
	yylex();
}

int yywrap()
{
	return 1;
}