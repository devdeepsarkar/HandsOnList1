/*
============================================================================================
 * Name: 18a.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to perform Record locking.
		a. Implement write lock

		Create three records in a file. Whenever you access a particular record, first lock it then modify/accesscto avoid race condition. 
 * Date: 4th Sept, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	const int Record_Size = 50;
	const int No_Of_Record = 3;

	int fp = open(argv[1], O_RDWR, 0666);
	
	int rnum;
	printf("Enter Record Num(1-3): ");
	scanf("%d", &rnum);
	rnum--;

	struct flock wrlock;
	wrlock.l_type = F_WRLCK;
	wrlock.l_whence = SEEK_SET;
	wrlock.l_start = Record_Size * rnum;
	wrlock.l_len = Record_Size;

	// Acquiring lock
	printf("Acquiring Lock....\n");
	int msg = fcntl(fp, F_SETLK, &wrlock);
	if(msg != -1){
		printf("Write lock Acquired\n");
	}
	else{
		printf("Error Accessing\n");
		return 1;
	}

	// Modify Chosen Record
	char storage[Record_Size];
	printf("Enter New Data: ");
	getchar();
	fgets(storage, sizeof(storage), stdin);

	lseek(fp, Record_Size*rnum, SEEK_SET);
	write(fp, storage, Record_Size);

	printf("Record Updated.\n");

	// Unlock Record
	wrlock.l_type = F_UNLCK;
	if(fcntl(fp, F_SETLK, &wrlock) != -1){
                printf("Write lock Released\n");
        }
        
	close(fp);

	return 0;
}

/*

// File content before modifying
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ cat ../myfile18a.txt
11111111111111111111111111111111111111111111111112222222222222222222222222222222222222222222222222233333333333333333333333333333333333333333333333333

// Acquiring Lock on record 1
Terminal 1:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18a.txt
		Enter Record Num(1-3): 1
		Acquiring Lock....
		Write lock Acquired
		Enter New Data:

// Accssing already locked Record 1 then Acquiring lock on record 2
Terminal 2:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18a.txt
		Enter Record Num(1-3): 1
		Acquiring Lock....
		Error Accessing
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18a.txt
		Enter Record Num(1-3): 2
		Acquiring Lock....
		Write lock Acquired

// Accessing already locked Record 2 and then acquiring lock on record 3 and releasing lock.
Terminal 3:
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18a.txt
		Enter Record Num(1-3): 2
		Acquiring Lock....
		Error Accessing
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./18a_exe ../myfile18a.txt
		Enter Record Num(1-3): 3
		Acquiring Lock....
		Write lock Acquired
		Enter New Data: 99999999999999999999999999999999999999999999999999
		Record Updated.
		Write lock Released

// Entering new data and releasing lock on Record 1
Terminal 1:
		Enter New Data: 11111111111111111111111111111111111111111111111111
		Record Updated.
		Write lock Released

// Entering newdata and releasing lock on record 2
Terminal 2:
		Enter New Data: 77777777777777777777777777777777777777777777777777
		Record Updated.
		Write lock Released

// checking file content after modifying
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ cat ../myfile18a.txt
111111111111111111111111111111111111111111111111177777777777777777777777777777777777777777777777779999999999999999999999999999999999999999999999999
*/
