/*
============================================================================================
 * Name: 28.c
 * Author: Devdeep Sarkar
 * Description: Write a program to get maximum and minimum real time priority. 
 * Date: 5th Sept, 2025
=============================================================================================
*/


#include <stdio.h>
#include <sched.h>

int main() {
	int max = sched_get_priority_max(SCHED_FIFO);
	int min = sched_get_priority_min(SCHED_FIFO);

	printf("Min Priority: %d, Max Priority: %d\n", min, max);

	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./28_exe

	Min Priority: 1, Max Priority: 99
*/

