#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

/* Binding a task to the particular core */
int main(int argc, char *argv[])
{
	pid_t processID = getpid();
        cpu_set_t my_cpu_set;
	int retStatus=0, iter=0;
	char cpu_number[4]=" ";

	/* clear the CPU set to zero so that it will not contain any particular
           core in the cpuset */
	CPU_ZERO(&my_cpu_set);

	/* Add the particular core to the cpuset which handles the current 
	   thread or task */
	CPU_SET(1, &my_cpu_set);

	/*   set_sched_affinity sets affinity mask [binding mask] to particular
	 *  core where the task is handled.
	 *  if pid is set to ZERO in argument list then pid of current task is
	 *  taken
	 */
	retStatus = sched_setaffinity(0, sizeof(my_cpu_set), &my_cpu_set);

	/* find out the cpu_number which has affinity to current task.
	   Here it is hardcoded above as CPU0 */

	while(iter < CPU_SETSIZE)
	{
		if(CPU_ISSET(iter,&my_cpu_set))
		 {
			 char temp[4]=" ";
			 sprintf(temp, "%d", iter);
       			 strcat(cpu_number,temp);
		 }
	       	 iter++;
	}
	
	printf ("\n Current task %s with process ID %d has affinity to %s CPU\n",
		argv[0], processID, cpu_number);
	
	return 0;
}
