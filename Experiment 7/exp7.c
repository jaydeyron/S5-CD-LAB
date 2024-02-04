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
    char str[100];
    printf("\nEnter the string:\t");
    scanf("%s",str);
    int ac=0,bc=0,ba=0;
    for(int i=0;i<strlen(str);i++){
        (str[i]=='a')?ac++:bc++;
        if(i!=strlen(str)-1 && str[i]=='b' && str[i+1]=='a'){
            ba++;
        }
    }
    if(ac==1 && bc==0 && str[0]=='a'){
        printf("String accepted under rule 'a'");
    }
    else if(ac==1 && bc==2 && ba==0){
        printf("String accepted under rule 'abb'");
    }
    else if(ac>=0 && bc>=1 && ba==0){
        printf("String accepted under rule 'a*b+'");
    }
    else{
        printf("String not recognised");
    }
    printf("\n\n");
    return 29;
}