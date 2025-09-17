/*
============================================================================
Name : 19.c
Author : Devdeep Sarkar
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 5th Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> // to import timeval structure and gettimeofday()
#include <fcntl.h>    // to import pid_t

int main() {
    struct timeval start, end;
    pid_t pid;
    long elapsed;

    gettimeofday(&start, NULL);

    pid = getpid();

    gettimeofday(&end, NULL);

    // Calculate elapsed time in microseconds
    elapsed = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

    printf("PID: %d\n", pid);
    printf("Time taken by getpid(): %ld ms\n", elapsed);

    return 0;
}

/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./19_exe
PID: 10275
Time taken by getpid(): 9 ms
*/
