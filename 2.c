/*
============================================================================================
 * Name: 2.c 
 * Author: Devdeep Sarkar
 * Description: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory. 
 * Date: 20th Aug, 2025
=============================================================================================
*/




#include <stdio.h>

int main(void){

// Infinite Loop	
start: {
       
       	goto start;

       }

	return 0;

}


/*

   	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ls /proc/5424
		arch_status         environ            maps           patch_state   statm
		attr                exe                mem            personality   status
		autogroup           fd                 mountinfo      projid_map    syscall
		auxv                fdinfo             mounts         root          task
		cgroup              gid_map            mountstats     sched         timens_offsets
		clear_refs          io                 net            schedstat     timers
		cmdline             ksm_merging_pages  ns             sessionid     timerslack_ns
		comm                ksm_stat           numa_maps      setgroups     uid_map
		coredump_filter     latency            oom_adj        smaps         wchan
		cpu_resctrl_groups  limits             oom_score      smaps_rollup
		cpuset              loginuid           oom_score_adj  stack
		cwd                 map_files          pagemap        stat
	devdeep@devdeep-VivoBook-ASUSLaptop-X515JA-X515JA:~/software_systems/handsOnList1$ ps aux | grep 2_exe
		devdeep     5423  8.1  0.0   2548  1044 pts/0    T    16:11   0:05 ./2_exe
		devdeep     5424 99.9  0.0   2548  1044 pts/0    R    16:11   0:57 ./2_exe
		devdeep     5428  0.0  0.0   9144  2332 pts/0    S+   16:12   0:00 grep --color=auto 2_exe

*/
