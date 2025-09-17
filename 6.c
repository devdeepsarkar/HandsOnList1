/*
============================================================================================
 * Name: 6.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to take input from STDIN and display on STDOUT. Use only read/		      write system calls 
 * Date: 22nd Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>	// for O_CREAT, O_WRONLY file control options
#include <unistd.h>	// for write() and close() system call
#include <string.h>	// for strlen()

int main(){

	// writing into file
	
	int fp1 = open("samplefile.txt", O_CREAT | O_WRONLY, 0664);
	
	if(fp1 == -1) {
		printf("Error opening file samplefile.txt");
		return 1;
	}
	
	char data[] = "Hello this is handsonlist 6th que";
	int msg1 = write(fp1, data, strlen(data));
	if(msg1 == -1) {
		printf("Error writing on file\n");
		return 1;
	}
	else{
		printf("Successfully written on file samplefile.txt\n");
	}
	close(fp1);


	// Reading from file
	int fp2 = open("samplefile.txt", O_RDONLY, 0664);
	lseek(fp2, 0, SEEK_SET);
	if(fp2 == -1){
		printf("Error opening file for reading\n");
		return 1;
	}

	char filedata[100];
	int msg2 = read(fp2, filedata, sizeof(filedata)-1);
	if(msg2 == -1){
		printf("Error reading from file\n");
		return 1;
	}
	else{
		printf("Successfully read from file.\n File content:\n");
		printf("%s\n", filedata);
	}
	close(fp2);		

	return 0;
}


/*
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ vi 6.c
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 6.c -o 6_exe
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./6_exe
	Successfully written on file samplefile.txt
	Successfully read from file.
 	File content:
	Hello this is handsonlist 6th que
*/
