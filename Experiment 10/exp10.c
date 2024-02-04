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


// functions
int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int isOp(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/')? 1:0; // if operator returns true, else false
}

void infixToPostfix(char infix[], char postfix[]){
    char item[100];
    int top=-1,postCur=0;
    int prec[200];
    prec['+']=1,prec['-']=1,prec['*']=2,prec['/']=2;
    for(int i=0;i<strlen(infix);i++){
        if(isOp(infix[i])){
            if(top==-1){
                item[++top]=infix[i];
            }
            else{
                while(top!=-1 && prec[item[top]]>=prec[infix[i]]){
                    postfix[postCur]=item[top];
                    postCur++;
                    top--;
                }
                item[++top]=infix[i];
            }
        }
        else{
            postfix[postCur]=infix[i];
            postCur++;
        }
    }
    while(top>-1){
        postfix[postCur]=item[top];
        postCur++;
        top--;
    }
    printf("\nPostfix expression:\t%s\n\n",postfix);
}

void postfixToThreeAddressCode(char postfix[], char threeAddressCode[][100], int *codeSize){
    char item[100],buffer[100];
    char temp='A';
    int top=-1,current=0;
    printf("Generated three address code:\n");
    for(int i=0;i<strlen(postfix);i++){
        if(isOp(postfix[i])){
            sprintf(buffer,"%c=%c%c%c",temp,item[top-1],postfix[i],item[top]);
            printf("%s\n",buffer);
            strcpy(threeAddressCode[current],buffer);
            item[--top]=temp;
            temp++;
            current++; 
        }
        else{
            item[++top]=postfix[i];
        }
    }
    *codeSize=current-1;
}

void codeRepresentations(char threeAddressCode[][100], int codeSize){
    printf("\nQuadruple format:\n\n");
    printf("|%-10s|%-10s|%-10s|%-10s|%-10s|\n","No.","Operator","Operand 1","Operand 2","Result");
    printf("|----------|----------|----------|----------|----------|\n");
    for(int i=0;i<=codeSize;i++){
        printf("|%-10d|%-10c|%-10c|%-10c|%-10c|\n",i,threeAddressCode[i][3],threeAddressCode[i][2],threeAddressCode[i][4],threeAddressCode[i][0]);
    }
    printf("\nTriple format:\n\n");
    printf("|%-10s|%-10s|%-10s|%-10s|\n","No.","Operator","Operand 1","Operand 2");
    printf("|----------|----------|----------|----------|\n");
    for(int i=0;i<=codeSize;i++){
        printf("|%-10d", i);
        (threeAddressCode[i][3] >= 'A' && threeAddressCode[i][3] <= 'Z') ? printf("|%-10d",threeAddressCode[i][3] - 'A') : printf("|%-10c",threeAddressCode[i][3]);
        (threeAddressCode[i][2] >= 'A' && threeAddressCode[i][2] <= 'Z') ? printf("|%-10d",threeAddressCode[i][2] - 'A') : printf("|%-10c",threeAddressCode[i][2]);
        (threeAddressCode[i][4] >= 'A' && threeAddressCode[i][4] <= 'Z') ? printf("|%-10d\n",threeAddressCode[i][4] - 'A') : printf("|%-10c\n",threeAddressCode[i][4]);       
    }
    printf("\nIndirect triple format:\n\n");
    printf("|%-10s|%-10s|\n","No.","Pointer");
    printf("|----------|----------|\n");
    for(int i=0;i<=codeSize;i++){
        printf("|%-10d|%-10d|\n",i,i+23);
    }
    printf("\n");
}

// main
int main(){
    char infix[100],postfix[100],threeAddressCode[100][100];
    int codeSize=0;
    printf("\nEnter Infix expression:\t");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    postfixToThreeAddressCode(postfix,threeAddressCode,&codeSize);
    codeRepresentations(threeAddressCode,codeSize);
    return 29;
}