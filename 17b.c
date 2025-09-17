/*
============================================================================
Name : 17b.c
Author : Preet Chandrakar
Description : Write a program to simulate online ticket reservation. Implement write lock.
		b. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 5th Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;   // write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          // lock entire file

    // apply lock (wait if necessary)
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("fcntl: write lock");
        close(fd);
        exit(1);
    }

    int ticket;

    // read current ticket number
    if (read(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("read");
        close(fd);
        exit(1);
    }

    ticket++;  // increment ticket
    printf("Reserved ticket number: %d\n", ticket);

    // move file pointer to start before writing
    lseek(fd, 0, SEEK_SET);

    // write updated ticket back
    if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("write");
        close(fd);
        exit(1);
    }

    // unlock file
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./17a_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./17b_exe
Reserved ticket number: 19
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./17b_exe
Reserved ticket number: 20
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./17b_exe
Reserved ticket number: 21
*/
