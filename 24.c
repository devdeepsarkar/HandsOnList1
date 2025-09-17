/*
============================================================================================
 * Name: 24.c
 * Author: Devdeep Sarkar
 * Description: Write a program to create an orphan process.
 * Date: 5th Sept, 2025
============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Child creation failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(1);  // Sleep so that parent can exit
        printf("Child parent PID after parent exit: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent PID: %d, Child PID = %d\n", getpid(), pid);
        exit(0);  
    }

    return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./24_exe
	Parent PID: 10625, Child PID = 10626
	Child PID: 10626, Parent PID: 10625
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ 	Child parent PID after parent exit: 2090
*/
