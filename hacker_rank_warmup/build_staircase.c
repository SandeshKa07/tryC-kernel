#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int base, height,n=0; 
    printf("Enter Base/Height : ");
    scanf("%d",&base);
    height = base;
    for(int i = 1; i <= height; i++){
        for (int k = 1; k < (base - n) ; k++){
                printf(" ");
            } 
        for (int j = 1; j <= i ; j++)
        {           
            printf("#");
        }
        printf("\n");
        n++;
    }
    
    return 0;
}
