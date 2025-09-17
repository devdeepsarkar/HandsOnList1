/*
============================================================================
Name : 21.c
Author : Devdeep Sarkar
Description : Write a program, call fork and print the parent and child process id.
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h> // to import fork()
#include <sys/wait.h> // to import wait()

int main() {
	int pid = fork();

	if (pid == 0) {
		printf("Child process ID: %d\n", getpid());
	} else {
		// wait for child process to finish
		wait(NULL);
		printf("Parent process ID: %d\n", getpid());
	}

	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./21_exe
Child process ID: 11710
Parent process ID: 11709
*/
