/*
============================================================================================
 * Name: 26b.c
 * Author: Devdeep Sarkar
 * Description: Write a program to execute an executable program.
		b. pass some input to an executable program. (for example execute an executable of $./a.out name)
 * Date: 5th Sept, 2025
=============================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *args[]) {

    execvp(args[1], &args[1]);

    return 1;
}

/*

// Executable Program
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ cat ../SampleProgram.c
	
	#include <stdio.h>

	int main(int argc, char* argv[]){

		printf("Hello %s\n",argv[1]);

		return 0;
	}

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	./26b_exe ../MyProgram_exe Devdeep
	
	Hello Devdeep

*/
