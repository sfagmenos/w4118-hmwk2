#include <stdio.h>
#include <sys/types.h>

struct prinfo {
	pid_t parent_pid;/* process id of parent */
	pid_t pid;/* process id */
	pid_t first_child_pid;  	/* pid of youngest child */
	pid_t next_sibling_pid;  	/* pid of older sibling */
	long state;/* current state of process */
	long uid;/* user id of process owner */
	char comm[64];	/* name of program executed */
};

int main(char *argsv, int argsc)
{
	struct prinfo p[2];
	int nr = 2;

	syscall(223, &p, &nr);

	printf("%s,%d,%ld,%d,%d,%d,%d\n", p[0].comm, p[0].pid, p[0].state,
				p[0].parent_pid, p[0].first_child_pid, p[0].next_sibling_pid, p[0].uid);
	printf("%s,%d,%ld,%d,%d,%d,%d\n", p[1].comm, p[1].pid, p[1].state,
				p[1].parent_pid, p[1].first_child_pid, p[1].next_sibling_pid, p[1].uid);

}