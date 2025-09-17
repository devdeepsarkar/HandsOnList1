/*
============================================================================================
 * Name: 1c.c 
 * Author: Devdeep Sarkar
 * Description: 1. Create the following types of a files using (i) shell command (ii) system call
		c. FIFO (mkfifo Library Function or mknod system call) 
 * Date: 26th Aug, 2025
=============================================================================================
*/




#include <sys/types.h>	//	data tpye definitions
#include <sys/stat.h>	//	for mkfifo() system call	
#include <stdio.h>

int main(void) {
	
	int msg = mkfifo("../fifoo", 0666);
	if(!msg) printf("Fifo created successfully!");
	else{
		printf("Error");
		return 1;
	}

	return 0;
}

/*
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./1_c_exe
	Fifo created successfully!

	Terminal 1:
		devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems$ cat fifoo
		hello world



	Terminal 2:
		devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems$ echo "hello world" > fifoo
	

	
*/
