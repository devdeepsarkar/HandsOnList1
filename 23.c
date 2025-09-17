/*
============================================================================
Name : 23.c
Author : Devdeep Sarkar
Description : Write a program to create a Zombie state of the running program.
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import fork(), sleep() and getpid()
#include <sys/wait.h>

int main() {
	int pid = fork();
	
	if (pid == 0) {
		printf("Child process with PID: %d is running.\n", getpid());
		exit(0);
	} else {
		printf("Parent process with PID: %d is running.\n", getpid());
		sleep(30);
	}

	return 0;
}

/*
Terminal-1:
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./23_exe
Parent process with PID: 11797 is running.
Child process with PID: 11798 is running.



Terminal-2:
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ps -el | grep Z
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
1 Z  1000   11798   11797  0  80   0 -     0 -      pts/2    00:00:00 23_exe

*/
