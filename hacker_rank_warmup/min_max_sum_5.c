#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

int main() {
    long arr[5];
    long temp=0, min_sum=0, max_sum=0;

    for(int arr_i = 0; arr_i < 5; arr_i++){
       scanf("%ld",&arr[arr_i]);
    }

    for(int i = 0; i < 5; i++) {
	    for(int j = i+1; j < 5 ; j++) { 
		    if(arr[i] > arr[j]) {
			    temp = arr[i];
			    arr[i] = arr[j];
			    arr[j] = temp;
		    }
	    }	   
    }

    for(int i = 0; i < 4; i++)
	    min_sum += arr[i];

    for(int i = 1; i <= 4; i++)
	    max_sum += arr[i];

    printf("%ld ", min_sum);
    printf("%ld", max_sum);

    return 0;
}
