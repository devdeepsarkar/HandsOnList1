/*
============================================================================================
 * Name: 3.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to create a file and print the file descriptor value. Use creat ( ) system call
 * Date: 20th Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>	// for open() system call
#include <unistd.h>	// for close() system call

int main(void){
	int msg1, msg2;
       	msg1 = creat("ffiillee1.txt", 0666);
	msg2 = creat("ffiillee2.txt", 0666);

	if(msg1 == -1 || msg2 == -1) {
		printf("error");
		return 1;
	}
	else{
		printf("file descriptor1: %d \n",msg1);
		printf("file descriptor2: %d \n",msg2);
		close(msg1);
		int msg3 = creat("ffiillee3.txt",0666);
		printf("file descriptor3 after closing file1: %d \n", msg3);
		close(msg2);
		close(msg3);
	}


	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./3_exe
	file descriptor1: 3 
	file descriptor2: 4 
	file descriptor3 after closing file1: 3

*/
