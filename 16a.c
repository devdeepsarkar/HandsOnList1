/*
============================================================================================
 * Name: 16.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to perform mandatory locking.
		a. Implement write lock
 * Date: 3rd Sept, 2025
=============================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

	int fp = open(argv[1], O_RDWR, 0666);

	// define and acquire lock on entire file
	struct flock wrlock;
	wrlock.l_type = F_WRLCK;
	wrlock.l_whence = SEEK_SET;
	wrlock.l_start = 0;
	wrlock.l_len = 0;
	
	printf("Acquiring Lock\n");
	
	int msg = fcntl(fp, F_SETLK, &wrlock);
	if(msg != -1)
		printf("Write lock Acquired\n");
	else{
		printf("Error accessing");
		return 1;
	}

	printf("Press enter to release lock: \n");
	getchar();


	wrlock.l_type = F_UNLCK;
	if(fcntl(fp, F_SETLK, &wrlock) != -1)
                printf("Lock Released\n");

	close(fp);

	return 0;
}

/*
Terminal 1:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./16_exe ../newfile16.txt
		Acquiring Lock
		Write lock Acquired
		Press enter to release lock: 


Terminal 2:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./16_exe ../newfile16.txt
	Acquiring Lock
	Error accessing

Terminal 1:
		Press enter to release lock:

		Lock Released
*/
