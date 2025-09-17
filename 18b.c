/*
============================================================================================
 * Name: 18b.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to perform Record locking.
                b. Implement read lock

                Create three records in a file. Whenever you access a particular record, 
                first lock it then read/access to avoid race condition. 
 * Date: 4th Sept, 2025
============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	const int Record_Size = 50;
	const int No_Of_Record = 3;

	int fp = open(argv[1], O_RDONLY, 0666);

	int rnum;
	printf("Enter Record Num(1-3): ");
	scanf("%d", &rnum);
	rnum--;

	struct flock rdlock;
	rdlock.l_type = F_RDLCK;             // Read Lock
	rdlock.l_whence = SEEK_SET;
	rdlock.l_start = Record_Size * rnum;
	rdlock.l_len = Record_Size;

	// Acquiring lock
	printf("Acquiring Read Lock....\n");
	int msg = fcntl(fp, F_SETLK, &rdlock);
	if(msg != -1){
		printf("Read lock Acquired\n");
	}
	else{
        	printf("Error Accessing");
 	        return 1;
    	}
	
	printf("Press Enter to print content: ");	
	getchar();
	getchar();

	// Read chosen record
    	char storage[Record_Size + 1];
    	lseek(fp, Record_Size*rnum, SEEK_SET);
    	read(fp, storage, Record_Size);
    	storage[Record_Size] = '\0';   // Null-terminate for printing

    	printf("Record %d Data: %s\n", rnum+1, storage);

    	// Unlock Record
    	rdlock.l_type = F_UNLCK;
    	if(fcntl(fp, F_SETLK, &rdlock) != -1){
        	printf("Read lock Released\n");
    	}

    	close(fp);
    	return 0;
}

/*

Terminal 1:

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18b_exe ../myfile18b.txt
	Enter Record Num(1-3): 1
	Acquiring Read Lock....
	Read lock Acquired
	Press Enter to print content: 

// if reader is reading then writer is not allowed	
Terminal 2:

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18b.txt
	Enter Record Num(1-3): 1
	Acquiring Lock....
	Error Accessing


Terminal 1:

	Press Enter to print content:
	Record 1 Data: 1111111111111111111111111111111111111111111111111
        Read lock Released

*/
