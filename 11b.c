/*
============================================================================================
 * Name: 11b.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not
	b. use dup2
 * Date: 2nd sept, 2025
=============================================================================================
*/



#include <stdio.h>
#include <unistd.h> 	// dup, close, read, write, lseek, close --> system calls
#include <fcntl.h> 	// O_RDWR, O_CREAT, O_APPEND, O_TRUNC

int main(){
	
	// b.	use dup2

	int fp = open("./file11b.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);
	int fpb = dup2(fp, 10);		
	
	// writing using fp
	write(fp, "Hello World\n", 12);
	// writing using fpb which is assigned using dup2
	write(fpb, "Hello from dup2\n", 15);

	// Reading from file
        lseek(fp, 0, SEEK_SET);
        char filedata[100];
        int msg = read(fp, filedata, sizeof(filedata)-1);
        
        printf("File content after using dup2:\n");
        printf("%s\n", filedata);
     

	close(fp);

	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ vi 11b.c
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 11b.c -o 11b_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./11b_exe
	File content after using dup2:
	Hello World
	Hello from dup2

*/
