/*
 *  linux/kernel/ptree.c
 *
 *  Copyright (C) 2014 Vaggelis Atlidakis, Georgios Koloventzos, Andrei Papancea
 */

#include <linux/prinfo.h>
#include <asm-generic/errno-base.h>
#include <linux/spinlock.h>

extern rwlock_t tasklist_lock;

int ptree(struct prinfo *buf, int *nr)
{
	int errno;
	int entries;
	struct prinfo kbuf;

	if (buf == NULL || nr == NULL) {
		errno = -EINVAL;
		goto error;
	}
	if (*nr < 1) {
		errno = -EINVAL;
		goto error;
	}
	entries = *nr;

	if (copy_to_user(buf, &kbuf, entries * sizeof(struct prinfo))) {
 		errno = -EFAULT;
		goto error;
	}

	read_lock(&tasklist_lock);

	/* stuff goes here */

	read_unlock(&tasklist_lock);

	errno = 0;

error:
	return errno;
}
