/*
============================================================================================
 * Name: 30.c
 * Author: Devdeep Sarkar
 * Description: Write a program to run a script at a specific time using a Daemon process.
 * Date: 5th Sept, 2025
=============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	pid_t pid = fork();

    	if(pid > 0){
        	exit(0);
    	}

    	// Child becomes daemon
    	if(setsid() < 0){
		exit(1);
	}
    	umask(0);
    	chdir("/");

	close(STDIN_FILENO);
    	close(STDOUT_FILENO);
    	close(STDERR_FILENO);

    	// Targeted time
    	int target_hour = 18;
    	int target_min = 40;

    	while(1){
        	time_t now = time(NULL);
        	struct tm *lt = localtime(&now);

       	 	if (lt->tm_hour == target_hour && lt->tm_min == target_min) {
            		system("/home/devdeep/myscript30.sh");
            		sleep(60);
        	}
        	sleep(30);
    	}

    return 0;
}

/*

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./30_exe &
[1] 8957

devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems$ cat /tmp/daemon_log.txt
	Hello, Script executed at Fri Sep  5 06:39:20 PM IST 2025

*/
