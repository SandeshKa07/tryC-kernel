#include <stdio.h>

static int myVariable = 0;

int myfunction(){
	myVariable = myVariable + 1;
	return myVariable;
}

int main(){
	printf("First Call = %d\n", myfunction()); 
	printf("Second Call = %d\n", myfunction()); 
	printf("Third Call = %d\n", myfunction()); 
	printf("Fourth Call = %d\n", myfunction());
	return 0;
}

