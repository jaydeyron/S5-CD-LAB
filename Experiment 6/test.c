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
    char a[100][100];
    for(int i=0;i<100;i++){
        strcpy(a[i],"hello");
    }
    strcpy(a['A'],"test");
    for(int i=0;i<100;i++){
        printf("%d:\t%s\n",i+1,a[i]);
    }
    return 29;
}