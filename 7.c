/*
============================================================================================
 * Name: 7.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to copy file1 into file2 ($cp file1 file2). 
 * Date: 23rd Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>      // for O_CREAT, O_WRONLY file control options
#include <unistd.h>     // for write() and close() system call
#include <string.h>     // for strlen()
#include <stdlib.h>

int main(){

	// writing into file
	int fp = open("mysamplefile7.txt", O_CREAT | O_WRONLY, 0664);

	if(fp == -1){
		printf("Error opening file");
		return 1;
	}
	char data[] = "Hiiiiiiiiiiiiiiiiiii";
	int msg = write(fp, data, strlen(data));
	if(msg == -1){
		printf("Error writing on file\n");
		return 1;
	}

	
	int msg2 = system("cp mysamplefile7.txt file7.txt");
	if(msg2 == -1){
		printf("Error Copying");
	}
	else{
		printf("Successfully copied mysamplefile7.txt into file7.txt");
	}
	close(fp);
	

	return 0;
}


/*
	 devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./7_exe
	 Successfully coppied mysamplefile7.txt into file7.txt

	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ cat file7.txt
	Hiiiiiiiiiiiiiiiiiii			
	
*/
