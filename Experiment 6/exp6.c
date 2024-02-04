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
int n;
const char divider[2]="|";
char first[200][100]={""};

// functions
int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int findFirst(char A, char lhs[][100], char rhs[][100]){
    int i;
    for(int j=0;j<n;j++){
        if(lhs[j][0]==A){i=j; break;}
    }
    char *div=strtok(rhs[i],divider);
    while(div!=NULL){
        int j=0;
        while(j<strlen(div)){
            printf("%c\n",div[j]);
            if(div[j]=='#'){
                strcat(first[A],"#");
                strcat(first[A],",");
                return 0;
            }
            else if(div[j]<'A' || div[j]>'Z'){
                strcat(first[A],div);
                strcat(first[A],",");
            }
            else{
                if(findFirst(div[j],lhs,rhs)){
                    strcat(first[A],first[div[j]]);
                    break;
                }
                else{
                    strcat(first[A],first[div[j]]);
                }
            }
            j++;
        }
        div=strtok(NULL,divider);
    }
    return 1;
}

void First(int i, int left, char lhs[][100], char rhs[][100]){
    char *div=strtok(rhs[i],divider);
    while(div!=NULL){
        int j=0;
        while(j<strlen(div)){
            printf("%c\n",div[j]);
            if(div[j]=='#'){
                strcat(first[left],"#");
                strcat(first[left],",");
                break;
            }
            else if(div[j]<'A' && div[j]>'Z'){
                strcat(first[left],div);
                strcat(first[left],",");
                break;
            }
            else{
                if(findFirst(div[j],lhs,rhs)){
                    strcat(first[left],first[div[j]]);
                    break;
                }
                else{
                    strcat(first[left],first[div[j]]);
                }
            }
            j++;
        }
        div=strtok(NULL,divider);
    }
}

// main
int main(){
    printf("Enter the number of production rules:\t");
    scanf("%d",&n);
    char prod[100];
    char lhs[n][100],rhs[n][100];
    const char delimiter[3]="->";
    for(int i = 0;i < n;i++){
        printf("Enter the production rule no. %d:\t",i+1);
        scanf("%s",prod);
        char *left=strtok(prod,delimiter);
        char *right=strtok(NULL,delimiter);
        strcpy(lhs[i],left);
        strcpy(rhs[i],right);
    }
    char temp[100];
    for(int i=0;i<n;i++){
        if(strlen(first[lhs[i][0]])==0){
            First(i,lhs[i][0],lhs,rhs);
        }
        printf("First(%s) = {%s}\n",lhs[i],first[lhs[i][0]]);
    }
    return 29;
}

// ----------------------------------
// test cases

// 1)
// Input :
// E->TR
// R->+TR|#
// T->FY
// Y->*FY|#
// F->(E)|i

// Output :
// First(E) = { (, i }
// First(R) = { +, # }
// First(T) = { (, i }
// First(Y) = { *, # }
// First(F) = { (, i }

// Follow(E) = { $, ) }
// Follow(R) = { $, ) }
// Follow(T) = { +, $, ) }
// Follow(Y) = { +, $, ) }
// Follow(F) = { *, +, $, ) }

// 2)
// Input :
// S->ABCDE
// A->a|#
// B->b|#
// C->c
// D->d|#
// E->e|#

// Output :
// First(S) = { a, b, c, # }
// First(A) = { a, # }
// First(B) = { b, # }
// First(C) = { c }
// First(D) = { d, # }
// First(E) = { e, # }

// Follow(S) = { $ }
// Follow(A) = { b, c }
// Follow(B) = { d }
// Follow(C) = { d, e, $ }
// Follow(D) = { e, $ }
// Follow(E) = { $ }