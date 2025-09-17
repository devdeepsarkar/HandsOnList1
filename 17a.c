/*
============================================================================
Name : 17a.c
Author : Devdeep Sarkar
Description : Write a program to simulate online ticket reservation. Implement write lock.
		a. Write a program to open a file, store a ticket number and exit.
Date: 4th Sept, 2025.
============================================================================
*/


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket.txt", O_WRONLY | O_CREAT, 0644); // open or create file
    if (fd < 0) exit(1); // exit if file can't be opened

    int ticket = 18; // initial ticket number
    write(fd, &ticket, sizeof(ticket)); // store ticket

    close(fd);
    return 0;
}

