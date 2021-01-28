Command to Run:
gcc static_function.c helper_function.c -o static_function


Static function limits the function scope to a particular translation unit. Hence 
the function call in the main function in static_function.c file results in error as
the defintion is limited to helper.c file.


In file included from static_function.c:1:
static_function.h:1:12: warning: ‘myStaticFunction’ used but never defined
    1 | static int myStaticFunction();
      |            ^~~~~~~~~~~~~~~~
/usr/bin/ld: /tmp/ccF8JLqw.o: in function `main':
static_function.c:(.text+0xe): undefined reference to `myStaticFunction'
collect2: error: ld returned 1 exit status

