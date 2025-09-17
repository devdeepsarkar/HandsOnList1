/*
============================================================================================
 * Name: 16b.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to perform mandatory locking.
		b. Implement read lock
 * Date: 4th Sept, 2025
=============================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

	int fp = open(argv[1], O_RDWR, 0666);

	// define and acquire lock on entire file
	struct flock rdlock;
	rdlock.l_type = F_RDLCK;
	rdlock.l_whence = SEEK_SET;
	rdlock.l_start = 0;
	rdlock.l_len = 0;
	
	printf("Acquiring Read Lock\n");
	
	int msg = fcntl(fp, F_SETLK, &rdlock);
	if(msg != -1)
		printf("Read lock Acquired\n");
	else{
		printf("Error accessing");
		return 1;
	}

	printf("Press enter to release lock: \n");
	getchar();


	rdlock.l_type = F_UNLCK;
	if(fcntl(fp, F_SETLK, &rdlock) != -1)
                printf("Lock Released\n");

	close(fp);

	return 0;
}

/*
Terminal 1:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./16b_exe ../SampleText.txt
		Acquiring Read Lock
		Read lock Acquired
		Press enter to release lock: 

// Multiple Readers are allowed
Terminal 2:
        devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./16b_exe ../SampleText.txt
                Acquiring Read Lock
                Read lock Acquired
                Press enter to release lock:

// Writer is not allowed
Terminal 3:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./16a_exe ../newfile16.txt
		Acquiring Write Lock
		Error accessing

Terminal 1:
		Press enter to release lock:

		Lock Released

Terminal 2:
                Press enter to release lock:

                Lock Released
*/

