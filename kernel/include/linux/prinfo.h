#ifndef _PTRINFO_H
#define _PTRINFO_H

#include <linux/types.h>

struct prinfo {
	pid_t parent_pid; /* process id of parent */
	pid_t pid; /* process id */
	pid_t first_child_pid; /* pid of youngest child */
	pid_t next_sibling_pid; /* pid of older sibling */
	long state;	/* current state of process */
	long uid; /* user id of process owner */
	char comm[64]; /* name of program executed */
};

int ptree(struct prinfo *buf, int *nr);

#endif
