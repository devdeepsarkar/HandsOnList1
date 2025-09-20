/*
============================================================================
Name : 29.c
Author : Devdeep Sarkar
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param param;
    pid_t pid = getpid();

    // Get current scheduling policy
    policy = sched_getscheduler(pid);

    printf("Current policy: ");
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("UNKNOWN\n");

    // Set new policy to SCHED_FIFO
    param.sched_priority = 10; // any priority between min and max
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler SCHED_FIFO");
    } else {
        printf("Changed policy to SCHED_FIFO\n");
    }

    // Set new policy to SCHED_RR
    param.sched_priority = 20; // any valid priority
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler SCHED_RR");
    } else {
        printf("Changed policy to SCHED_RR\n");
    }

    return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ sudo ./29
[sudo] password for devdeep: 
Current policy: SCHED_OTHER
Changed policy to SCHED_FIFO
Changed policy to SCHED_RR
*/
