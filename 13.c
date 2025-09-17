/*
============================================================================
Name : 13.c
Author : Devdeep Sarkar
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 3rd Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
	fd_set readfds;
	struct timeval timeout;
	int ret;

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	// wait for 10 sec
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	printf("Taking input for 10 sec: ");
	fflush(stdout);

	ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

	if (ret == -1) {
		perror("select");
		exit(EXIT_FAILURE);
	} else if (ret == 0) {
		printf("Data Unavailable for 10 seconds.\n");
	} else {
		if (FD_ISSET(STDIN_FILENO, &readfds)) {
			printf("Data:\n");

			char buffer[100];
			if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
				printf("%s",buffer);
			}
		}
	}

	return 0;
}


/*
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./13_exe
Teking Input for 10 sec: Hello from Devdeep!
Data:
Hello from Devdeep!
*/
