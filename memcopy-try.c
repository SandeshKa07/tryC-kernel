#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *ptr1=NULL, *ptr2=NULL, *ptr3=NULL;
	ptr1 = malloc(1); /* allocate memory pointed by the pointers */
	ptr2 = malloc(1);
	ptr3 = malloc(1);
	*ptr1 = 'A'; /* initialize the data in the above created memory */
        *ptr2 = 'B'; /* location */
	printf("Address of ptr1 is %p\n", ptr1);
	printf("Address of ptr2 is %p\n", ptr2);
	printf("Data in ptr1=%p is %c\n", ptr1, *ptr1);
	printf("Data in ptr2=%p is %c\n", ptr2, *ptr2);
	printf(" Copying the data from ptr1=%p to ptr2=%p\n", ptr1, ptr2);
	memcpy(ptr3, ptr1, 1); /* exchange the data in the very old method */
	memcpy(ptr1, ptr2, 1); /* by using the 3rd varibale, which is not a */
	memcpy(ptr2, ptr3, 1); /* pro-programmer way :P */
	printf("\nAfter copying .................\n");
	printf("Data in ptr1=%p is %c\n", ptr1, *ptr1);
	printf("Data in ptr2=%p is %c\n", ptr2, *ptr2);	
	return 0;
}
