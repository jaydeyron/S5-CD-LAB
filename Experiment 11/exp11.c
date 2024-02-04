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

// main
int main(){
    int n;
    printf("\nEnter the number of 3 address code statements:\t");
    scanf("%d",&n);
    char ipcode[n][100];
    for(int i=0;i<n;i++){
        printf("Enter the 3 address code statement no. %d:\t",i+1);
        scanf("%s",ipcode[i]);
    }
    printf("\nTarget code :\n\n");
    char opr[10];
    for(int i=0;i<n;i++){
        (ipcode[i][3]=='+')?strcpy(opr,"ADD"):(ipcode[i][3]=='-')?strcpy(opr,"SUB"):(ipcode[i][3]=='*')?strcpy(opr,"MUL"):strcpy(opr,"DIV");
        /*if(ipcode[i][3]=='+'){        // alternate way
            strcpy(opr,"ADD");
        }
        else if(ipcode[i][3]=='-'){
            strcpy(opr,"SUB");
        }
        else if(ipcode[i][3]=='*'){
            strcpy(opr,"MUL");
        }
        else if(ipcode[i][3]=='/'){
            strcpy(opr,"DIV");
        }*/
        printf("MOV %c,R%d\n",ipcode[i][2],i);
        printf("%s %c,R%d\n",opr,ipcode[i][4],i);
        printf("MOV R%d,%c\n\n",i,ipcode[i][0]);
    }
    return 29;
}