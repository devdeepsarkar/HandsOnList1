/*
============================================================================
Name : 27c.c
Author : Devdeep Sarkar
Description : Write a program to execute ls -Rl by the following system calls.
		c. execle
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import execle()

int main() {
    char *envp[] = {"PATH=/bin:/usr/bin", NULL};

    printf("c. Using execle: \n");

    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execle failed");

    return 1;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./27c_exe
c. Using execle: 
.:
total 408
-rw-rw-r-- 1 devdeep devdeep  2318 Sep  7 03:18 10.c
-rw-rw-r-- 1 devdeep devdeep  1348 Sep  7 03:22 11a.c
-rw-rw-r-- 1 devdeep devdeep  1520 Sep  7 03:23 11b.c
-rw-rw-r-- 1 devdeep devdeep  1454 Sep  7 03:24 11c.c
-rw-rw-r-- 1 devdeep devdeep  1364 Sep  7 03:49 12.c
-rwxrwxr-x 1 devdeep devdeep 16096 Sep  7 04:18 27c_exe
*/
