/*
============================================================================================
 * Name: 6.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to take input from STDIN and display on STDOUT. Use only read/		      write system calls 
 * Date: 22nd Aug, 2025
=============================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char buffer[100];
	write(1, "Enter any string: ", 17);
	int size = read(0, buffer, sizeof(buffer)-1);
	
	if(size > 0) {
		buffer[size] = '\0';
		char c[] = "\nReading content from stdin: \n";

		write(1, c, sizeof(c));
		write(1, buffer, size);
	}

	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./6_exe
Enter any string: Hello Linux!!!!

Reading content from stdin: 
Hello Linux!!!!
*/
