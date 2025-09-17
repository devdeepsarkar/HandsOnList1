/*
============================================================================================
 * Name: 5.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd. 
 * Date: 22nd Aug, 2025
=============================================================================================
*/




#include <stdio.h>
#include <fcntl.h>	// for creat() system call

int main(){

	for(int i=0; i<5; i++){
		char fname[20];
		sprintf(fname, "File%d", i+1);
		printf("file%d created successfully",i);
		creat(fname, 0744);
	}	
	
	while(1);

	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./5_exe &
[5] 5505


devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ls /proc/5505/fd
0  1  2  3  4  5  6  7


devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ls -l /proc/5505/fd
total 0
lrwx------ 1 devdeep devdeep 64 Aug 20 16:26 0 -> /dev/pts/0
lrwx------ 1 devdeep devdeep 64 Aug 20 16:26 1 -> /dev/pts/0
lrwx------ 1 devdeep devdeep 64 Aug 20 16:26 2 -> /dev/pts/0
l-wx------ 1 devdeep devdeep 64 Aug 20 16:26 3 -> /home/devdeep/software_systems/handsOnList1/File1
l-wx------ 1 devdeep devdeep 64 Aug 20 16:26 4 -> /home/devdeep/software_systems/handsOnList1/File2
l-wx------ 1 devdeep devdeep 64 Aug 20 16:26 5 -> /home/devdeep/software_systems/handsOnList1/File3
l-wx------ 1 devdeep devdeep 64 Aug 20 16:26 6 -> /home/devdeep/software_systems/handsOnList1/File4
l-wx------ 1 devdeep devdeep 64 Aug 20 16:26 7 -> /home/devdeep/software_systems/handsOnList1/File5

*/
