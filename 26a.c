/*
============================================================================================
 * Name: 26a.c
 * Author: Devdeep Sarkar
 * Description: Write a program to execute an executable program.
		a. use some executable program
 * Date: 5th Sept, 2025
=============================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    	printf("Before exec: This is sample line.\n");

    	// Replacing with "cat ./file26a"
    	char *args[] = {"cat", "./file26a", NULL};

    	execvp(args[0], args);
	
	return 1;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./26_exe
	Before exec: This is sample line.
	After exec:
	hello 
	this is me
	:how are you?
	all good...
*/
