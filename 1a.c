/*
============================================================================================
 * Name: 1a.c 
 * Author: Devdeep Sarkar
 * Description: 1. Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call) 
 * Date: 20th Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <unistd.h> 	// for symlink() system call

int main(void) {
	char* target = "./file1.txt";
	char* linkpath = "sftlnk";
	int msg = symlink(target, linkpath);
	if(!msg)	printf("Softlink successfully created!");
	else	{
		printf("Softlink creation failed!");
	}

	return 0;
}


/*
  	 devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./1_a_exe
   	 Softlink successfully created!
*/

