/*
============================================================================================
 * Name: 11a.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
	a. use dup
 * Date: 2nd sept, 2025
=============================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	
	// a.	use dup

	int fp = open("./file11a.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);
	
	int fpa =dup(fp);

	
	// writing using fp
	write(fp, "Hello World\n", 12);
	// writing using fpa which is assigned using dup
	write(fpa, "Hello from dup\n", 15);

	// Reading from file
        lseek(fp, 0, SEEK_SET);
        char filedata[100];
        int msg2 = read(fp, filedata, sizeof(filedata)-1);
      
        printf("File content after using dup:\n");
        printf("%s\n", filedata);
  

	close(fp);
	close(fpa);

	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 11a.c -o 11a_exe

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./11a_exe
	File content after using dup:
	Hello World
	Hello from dup

*/
