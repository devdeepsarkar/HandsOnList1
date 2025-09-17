/*
============================================================================
Name : 27b.c
Author : Devdeep Sarkar
Description : Write a program to execute ls -Rl by the following system calls.
		b. execlp
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import execlp()

int main() {
    printf("b. Using execlp: \n");

    execlp("ls", "ls", "-Rl", NULL);  // searches PATH
    perror("execlp failed");

    return 1;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./27b_exe
b. Using execlp: 
.:
total 392
-rw-rw-r-- 1 devdeep devdeep  2318 Sep  7 03:18 10.c
-rw-rw-r-- 1 devdeep devdeep  1348 Sep  7 03:22 11a.c
-rw-rw-r-- 1 devdeep devdeep  1520 Sep  7 03:23 11b.c
-rw-rw-r-- 1 devdeep devdeep  1454 Sep  7 03:24 11c.c
-rwxrwxr-x 1 devdeep devdeep 16048 Sep  7 04:16 27b_exe
*/
