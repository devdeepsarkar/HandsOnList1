/*
============================================================================================
 * Name: 11c.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not
	c. use fcntl
 * Date: 3rd sept, 2025
=============================================================================================
*/



#include <stdio.h>
#include <unistd.h> 	// close, read, write, lseek, close --> system calls
#include <fcntl.h> 	// O_RDWR, O_CREAT, O_APPEND, O_TRUNC

int main(){
	
	// c.	use fcntl

	int fp = open("../file11b.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);
	int fpc = fcntl(fp, F_DUPFD, 0);		
	
	// writing using fp
	write(fp, "Hello World\n", 12);
	// writing using fpc which is assigned using fcntl
	write(fpc, "Hello from fcntl\n", 15);

	// Reading from file
        lseek(fpc, 0, SEEK_SET);
        char filedata[100];
        int msg = read(fpc, filedata, sizeof(filedata)-1);
        
        printf("File content after using fcntl:\n");
        printf("%s\n", filedata);
     

	close(fp);
	close(fpc);

	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 11c.c -o 11c_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./11c_exe
	File content after using fcntl:
	Hello World
	Hello from fcnt
*/

