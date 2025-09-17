/*
============================================================================
Name : 15.c
Author : Devdeep Sarkar
Description : Write a program to display the environmental variable of the user (use environ).
Date: 3rd Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <string.h>

// global variable pre-defined by OS
extern char **environ;

int main() {
	char **env = environ;

	while(*env) {
		if (strncmp(*env, "USER=", 5) == 0) {
			printf("%s\n", *env);
		} else if (strncmp(*env, "LOGNAME=", 8) == 0) {
			printf("%s\n", *env);
		} else if (strncmp(*env, "USERNAME=", 9) == 0) {
			printf("%s\n", *env);
		} else if (strncmp(*env, "HOME=", 5) == 0) {
			printf("%s\n", *env);
		} else if (strncmp(*env, "SHELL=", 6) == 0) {
			printf("%s\n", *env);
		}
		env++;
	}

	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./15_exe
SHELL=/bin/bash
LOGNAME=devdeep
HOME=/home/devdeep
USERNAME=devdeep
USER=devdeep
*/
