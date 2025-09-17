/*
============================================================================================
 * Name: 20.c
 * Author: Devdeep Sarkar
 * Description: Find out the priority of your running program. Modify the priority with nice command.
 * Date: 4th Sept, 2025
============================================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority;

    // process id of current process
    pid_t pid = getpid();

    // priority of current process
    priority = getpriority(PRIO_PROCESS, pid);
 

    printf("Process ID of current process: %d\n", pid);
    printf("Current priority (nice value) of current process: %d\n", priority);

    // Keep process running to check priority externally
    sleep(3000);

    return 0;
}

/*

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	./20_exe
	Process ID of current process: 9111
	Current priority (nice value) of current process: 0


devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	nice -n 15 ./20_exe
	Process ID of current process: 9196
	Current priority (nice value) of current process: 15


devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ sudo nice -n -5 ./20_exe
	[sudo] password for devdeep:
	Process ID of current process: 9214
	Current priority (nice value) of current process: -5


devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	top
    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
   9173 devdeep   20   0    2680   1624   1624 S   0.0   0.0   0:00.00 20_exe 
   9196 devdeep   35  15    2680   1624   1624 S   0.0   0.0   0:00.00 20_exe 
   9214 root      15  -5    2680   1624   1624 S   0.0   0.0   0:00.00 20_exe

*/
