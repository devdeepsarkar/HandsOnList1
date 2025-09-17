/*
============================================================================================
 * Name: 12.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to find out the opening mode of a file. Use fcntl.
 * Date: 3rd Sept, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


int main(){

	int fp1 = open("./file12.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	int mode1 = fcntl(fp1, F_GETFL);	// to get file status flag
	int access_mode = mode1 & O_ACCMODE; 	// O_ACCMODE gives access mode bits of (O_RDONLY, O_WRONLY, O_RDWR)
	
	switch(access_mode){
		case O_RDONLY:	/*0...0000*/
			printf("Access mode: O_RDONLY(Read only)\n");
			break;
		case O_RDWR:	/*0...0001*/
			printf("Access mode: O_RDWR(Read Write)\n");
			break;
		case O_WRONLY:	/*0...0010*/
			printf("Access mode: O_WRONLY(Write Only)\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	close(fp1);
	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ vi 12.c
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 12.c -o 12_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./12_exe
	Access mode: O_RDWR(Read Write)

*/
