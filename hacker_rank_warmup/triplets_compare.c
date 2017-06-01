#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int *result_size){
	*result_size = 2;
	int *array = malloc(*result_size);

	if(a0 > b0)
		array[0] += 1;
	else if(b0 > a0)
		array[1] += 1;
	if(a1 > b1)
		array[0] += 1;
	else if(b1 > a1)
		array[1] += 1;
	if(a2 > b2)
		array[0] += 1;
	else if(b2 > a2)
		array[1] += 1;

	return array;
}

int main() {
    int result_i = 0;
    int a0;
    int a1;
    int a2;
    scanf("%d %d %d", &a0, &a1, &a2);
    int b0;
    int b1;
    int b2;
    scanf("%d %d %d", &b0, &b1, &b2);
    int result_size;
    int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
    for (result_i = 0; result_i < result_size; result_i++) {
	if(result_i) {
	    printf(" ");
	}
	printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
