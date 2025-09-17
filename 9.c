/*
============================================================================================
 * Name: 9.c
 * Author: Devdeep Sarkar
 * Description: Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
 * Date: 26th Aug, 2025
=============================================================================================
*/



#include <stdio.h>
#include <sys/stat.h>	// defines the struct stat data structure
#include <unistd.h>	// for stst() function call
#include <time.h>	// for ctime() --> converts time_t values into human redable string
#include <string.h>

int main(){
	
	struct stat fs;
	char *fp = "./file9.txt";
	
	if(stat(fp, &fs) < 0){
		printf("Error");
		return 1;
	}

	long  inode_no = (long) fs.st_ino;
	long n_links = (long) fs.st_nlink;
	int uid = fs.st_uid;
	int gid = fs.st_gid;
	long size = (long) fs.st_size;
	long bs = (long) fs.st_blksize;
	long nb = (long) fs.st_blocks;
	char *at = ctime(&fs.st_atime);
	char *mt = ctime(&fs.st_mtime);
	char *ct = ctime(&fs.st_ctime);

	printf("Inode Number: %ld\n", inode_no);
	printf("No. of links:  %ld\n", n_links);
	printf("UID: %d\n", uid);
	printf("GID: %d\n", gid);
	printf("Size: %ld\n", size);
	printf("Block size: %ld\n", bs);
        printf("No. of Blocks: %ld\n", nb);
        printf("Last Access time: %s\n", at);
        printf("Last Modification: %s\n", mt);
        printf("Last status change: %s\n", ct);
	


	return 0;
}


/**
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ vi 9.c
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ gcc 9.c -o 9_exe
devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ./9_exe
	Inode Number: 2392076
	No. of links:  1
	UID: 1000
	GID: 1000
	Size: 1323
	Block size: 4096
	No. of Blocks: 8
	Last Access time: Sat Aug 23 15:20:40 2025

	Last Modification: Sat Aug 23 15:20:40 2025

	Last status change: Sat Aug 23 15:20:40 2025

 */
