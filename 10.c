/*
============================================================================================
 * Name: 10a.c 
 * Author: Devdeep Sarkar
 * Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
	        b. open the file with od and check the empty spaces in between the data.	
 * Date: 2nd sept, 2025
=============================================================================================
*/


#include <stdio.h>
#include <fcntl.h>	// for O_RDWR, O_CREAT, O_TRUNC (file control options)
#include <unistd.h>	// for write(), lseek(), close() system call


int main(){

	int fp = open("./file10.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if(fp < 0) {
		printf("Error opening file\n");
		return 1;
	}

	// writing first 10 bytes
	char store1[10] = "EXECUTABLE"; // first 10 Bytes
	int w = write(fp, store1, 10);
	if(w != 10){
		printf("Error on writing\n");
		return 1;
	}

	// moving file pointer by 10 bytes
	off_t displacement = lseek(fp, 10, SEEK_CUR); // to move pointer by 10 bytes from curr position
	if(displacement == -1){
		printf("ERROR");
		return 1;
	}
	else{
		printf("Return value of lseek after moving 10 Bytes is: %ld\n",(long)displacement);
	
	}

	// writing next 10 bytes
	char store2[10]="algorithms"; // next 10 Bytes
	int w2 = write(fp, store2, 10);
	if(w2 != 10){
		printf("Error on writing next 10 bytes\n");
		return 1;
	}


	close(fp);
	


	return 0;
}



/*
part a:

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 10.c -o 10_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./10_exe
	Return value of lseek after moving 10 Bytes is: 20

*/

/*
 part b:

 devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ od -c  ../file10a.txt
	0000000   E   X   E   C   U   T   A   B   L   E  \0  \0  \0  \0  \0  \0
	0000020  \0  \0  \0  \0   a   l   g   o   r   i   t   h   m   s
	0000036
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ od -c -w10 ../file10.txt
	0000000   E   X   E   C   U   T   A   B   L   E
	0000012  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
	0000024   a   l   g   o   r   i   t   h   m   s
	0000036

*/
