#include <stdio.h>

static void my_function(int a){
	printf("My Function called with argument = %d\n",a);
}

static int addition(int a, int b) {
	return a + b;
}

static int subtraction(int a, int b) {
	return a - b;
}

static int multiplication(int a, int b) {
	return a * b;
}

int main(){
	void (*my_func_ptr)(int) = my_function; //assigning function to a function pointer

	/* Calling the function with an argument*/
	(my_func_ptr)(10);

	printf("\n--------------\n");

	/* Declare array of function pointers and assign the function names,
	 * (*array_function_pointer[]) is name of array of function pointer,
	 * (int, int) is the type of argument, here it is common,
	 */
	int (*array_function_pointer[])(int, int) = {addition, subtraction, multiplication}; /*Index = 0,1,2 */

	printf("\nEnter a choice, 1.Addition, 2.Subtraction, 3.Multiplication \t");
	int choice = 1;
	scanf("%d",&choice);

	/*Calling function based on choice, choice will be used as index of array */
	printf("Result = %d\n",(*array_function_pointer[choice-1])(30, 20));

	return 0;
}
