#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n,sum_p=0, sum_s=0, a_i, a_j; 
    scanf("%d",&n);
    int a[n][n];
    for( a_i = 0; a_i < n; a_i++){
       for(a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
       }
    }
    
    for(a_i = 0, a_j = 0; (a_i < n), (a_j < n); a_i++, a_j++) {
	    sum_p += a[a_i][a_j];
	    sum_s += a[a_i][n-a_i-1];
    }
    printf("\n%d\n", abs(sum_p - sum_s));
    
    return 0;
}
