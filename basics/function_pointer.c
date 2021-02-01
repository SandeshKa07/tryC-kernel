#include <stdio.h>

static void my_function(int a){
	printf("My Function called with argument = %d\n",a);
}

int main(){
	void (*my_func_ptr)(int) = my_function; //assigning function to a function pointer

	/* Calling the function with an argument*/
	(my_func_ptr)(10);

	return 0;
}
