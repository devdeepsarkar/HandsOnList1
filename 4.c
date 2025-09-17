/*
============================================================================================
 * Name: 4.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 * Date: 20th Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <fcntl.h>	// for O_RDWR, O_CREAT, open(), O_EXCL
#include <unistd.h>	// for close() system call, SEEK_SET
#include <string.h>

int main(void){
	
	int fp = open("mmyyffiillee.txt", O_RDWR | O_CREAT, 0666);
	if(fp == -1){
		printf("Error creating file\n");
	       	return 1;
	}
	else{
	       	printf("File successfully created\n");
	}

	// writing to file
	char file_data[] = "Hello, this is me!!";
	int b = write(fp, file_data, strlen(file_data));

	if(b == -1){
		printf("Error writing\n");
		return 1;
	}
	else{
		printf("Successfully written\n");
	}

	// Reading from file
	char store[100];
	lseek(fp, 0, SEEK_SET);
	int br = read(fp, store, sizeof(store)-1);

	if(br == -1){
		printf("Error Reading\n");
		return 1;
	}
	else{
		store[br] = '\0';
		printf("%s \n", store);
	}
	close(fp);
	
	// with O_EXCL flag
	int fp2 = open("mmyyffiillee.txt", O_RDWR | O_CREAT | O_EXCL, 0666);

	if(fp2 == -1){
		printf("Error on o_excl\n");
		return 1;
	}
	else{
		printf("File created successfully\n");
	}
	close(fp);


	return 0;
}

/*
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./4_exe
		File successfully created
		Successfully written
		Hello, this is me!! 
		Error on o_excl
*/
