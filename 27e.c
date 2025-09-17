/*
============================================================================
Name : 27e.c
Author : Devdeep Sarkar
Description : Write a program to execute ls -Rl by the following system calls.
		e.execvp
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import execvp()

int main() {
    char *argv[] = {"ls", "-Rl", NULL};

    printf("e. Using execvp: \n");

    execvp("ls", argv);  // searches PATH
    perror("execvp failed");

    return 1;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./27e_exe
e. Using execvp: 
.:
total 440
-rw-rw-r-- 1 devdeep devdeep  2318 Sep  7 03:18 10.c
-rw-rw-r-- 1 devdeep devdeep  1348 Sep  7 03:22 11a.c
-rw-rw-r-- 1 devdeep devdeep  1520 Sep  7 03:23 11b.c
-rw-rw-r-- 1 devdeep devdeep  1454 Sep  7 03:24 11c.c
-rw-rw-r-- 1 devdeep devdeep   961 Sep  7 04:24 27e.c
-rwxrwxr-x 1 devdeep devdeep 16096 Sep  7 04:24 27e_exe
*/
