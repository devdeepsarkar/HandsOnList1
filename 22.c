/*
============================================================================================
 * Name: 22.c
 * Author: Devdeep Sarkar
 * Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
 * Date: 5th Sept, 2025
============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int fp = open("./file22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    	pid_t pid = fork();

    	if(pid < 0) {
       		printf("Fork Creation failed");
        	close(fp);
        	return 1;
    	}

    	if(pid == 0) {
        	// Child process
        	char *child = "Hello World from Child process\n";
        	write(fp, child, strlen(child));
   	} 
    	else {
        	// Parent process
        	char *parent = "Hello from Parent process\n";
        	write(fp, parent, strlen(parent));
        	wait(NULL);
    	}

    	close(fp);
    	return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	./22_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	cat ../file22.txt
	Hello from Parent process
	Hello World from Child process
*/

