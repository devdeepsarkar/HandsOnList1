/*
============================================================================================
 * Name: 14.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to find the type of a file.
			a. Input should be taken from command line.
			b. program should be able to identify any type of a file. 
 * Date: 3rd sept, 2025
=============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	struct stat fileinfo;

	lstat(argv[1], &fileinfo);
	printf("FileName: %s\n", argv[1]);

	if(S_ISREG(fileinfo.st_mode))
		printf("Regular file\n");
	else if(S_ISDIR(fileinfo.st_mode))
		printf("Directory\n");
	else if(S_ISCHR(fileinfo.st_mode))
		printf("Character Device");
	else if(S_ISBLK(fileinfo.st_mode))
		printf("Block Device\n");
	else if(S_ISFIFO(fileinfo.st_mode))
		printf("FIFO\n");
	else if(S_ISLNK(fileinfo.st_mode))
		printf("Symbolic link\n");
	else if(S_ISSOCK(fileinfo.st_mode))
		printf("Socket\n");
	else
		printf("Unknown\n");

	return 0;
}

 
/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./14_exe sftlnk
	FileName: sftlnk
	Symbolic link

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./14_exe ../file10.txt
	FileName: ../file10.txt
	Regular file
*/
