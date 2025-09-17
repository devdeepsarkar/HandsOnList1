/*
============================================================================================
 * Name: 1b.c 
 * Author: Devdeep Sarkar
 * Description: 1. Create the following types of a files using (i) shell command (ii) system call
		b. hard link (link system call) 
 * Date: 26th Aug, 2025
=============================================================================================
*/




#include <stdio.h>
#include <unistd.h>	//	for link() system call

int main(void) {
	char* target = "./file2";
	char* linkpath = "hrdlnk";
	int msg = link(target, linkpath);
	if(!msg)	printf("Hardlink successfully created!");
	else	{
		printf("Hardlink creation failed!");
	}

	return 0;
}


/*
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./1_b_exe
	Hardlink successfully created!		
*/
