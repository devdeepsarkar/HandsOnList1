/*
============================================================================
Name : 25.c
Author : Devdeep Sarkar
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import fork(), sleep() and getpid()
#include <sys/wait.h> // to import wait()

int main() {
	pid_t c1, c2, c3;

	// 1st child
	c1 = fork();
	if (c1 == 0) {
		printf("Child 1 (PID: %d)\n", getpid());
		sleep(2);
		exit(0);
	}

	// 2nd child
	c2 = fork();
	if (c2 == 0) {
		printf("Child 2 (PID: %d)\n", getpid());
		sleep(4);
		exit(0);
	}

	// 3rd  child
	c3 = fork();
	if (c3 == 0) {
		printf("Child 3 (PID: %d)\n", getpid());
		sleep(6);
		exit(0);
	}

	printf("\nParent (PID: %d)\n", getpid());

	int status;
	pid_t waited = waitpid(c2, &status, 0);

	printf("Parent waited for Child 2 (PID: %d). Exit status = %d\n", waited, WEXITSTATUS(status));

	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./25_exe
Child 1 (PID: 11841)

Parent (PID: 11840)
Child 2 (PID: 11842)
Child 3 (PID: 11843)
Parent waited for Child 2 (PID: 11842). Exit status = 0

*/
