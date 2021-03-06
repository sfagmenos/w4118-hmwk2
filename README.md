Implementations of a DFS proc tree info utility for Android.
==
Copyright (C) 2014 V. Atlidakis, G. Koloventzos, A. Papancea

COMS-W4118 Columbia University

## MODIFIED/ADDED FILES:

- kernel/arch/arm/include/asm/unistd.h
  defined syscall at position 223

- kernel/arch/arm/kernel/calls.S
  added syscall to syscall table at position 223

- kernel/include/linux/prinfo.h
  defined prinfo struct

- kernel/kernel/Makefile
  added ptree binary to the kernel compilation

- kernel/kernel/ptree.c
  our ptree syscall implementation

- tests/Makefile
  Makefile for test program

- tests/list.c
  list manipulation helper functions for test program

- tests/list.h
  header file for list manipulation functions

- tests/prinfo.c
  test program that uses ptree

- tests/prinfo.h
  header file for the test program

- written.txt
  answers to exercise 4

## RESOURCES USED:

1. Linux Cross Reference
   http://lxr.free-electrons.com

## TEST PROGRAM OUTPUT:
```
w4118@w4118:tests(master)> adb shell /data/test_ptree
Allocated a buffer of size: 1
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 2
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 4
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 8
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 16
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 32
Total number of processes running: 63
Re-allocating a larger buffer

Allocated a buffer of size: 64
Total number of processes running: 63


swapper, 0, 0, 0, 2, 0, 0
	init, 1, 1, 0, 463, 2, 0
		ueventd, 32, 1, 1, 0, 43, 0
		healthd, 43, 1, 1, 0, 44, 0
		servicemanager, 44, 1, 1, 0, 45, 1000
		vold, 45, 1, 1, 0, 47, 0
		netd, 47, 1, 1, 0, 48, 0
		debuggerd, 48, 1, 1, 0, 49, 0
		rild, 49, 1, 1, 0, 50, 1001
		surfaceflinger, 50, 1, 1, 0, 51, 1000
		zygote, 51, 1, 1, 989, 52, 0
			system_server, 376, 1, 51, 0, 470, 1000
			d.process.media, 470, 1, 51, 0, 516, 10005
			putmethod.latin, 516, 1, 51, 0, 528, 10029
			m.android.phone, 528, 1, 51, 0, 538, 1001
			ndroid.launcher, 538, 1, 51, 0, 581, 10008
			d.process.acore, 581, 1, 51, 0, 592, 10002
			id.printspooler, 592, 1, 51, 0, 658, 10039
			ndroid.systemui, 658, 1, 51, 0, 746, 10007
			externalstorage, 746, 1, 51, 0, 769, 10006
			ndroid.settings, 769, 1, 51, 0, 784, 1000
			m.android.music, 784, 1, 51, 0, 864, 10032
			.android.dialer, 864, 1, 51, 0, 885, 10004
			viders.calendar, 885, 1, 51, 0, 903, 10001
			com.android.mms, 903, 1, 51, 0, 929, 10009
			ndroid.calendar, 929, 1, 51, 0, 952, 10016
			droid.deskclock, 952, 1, 51, 0, 969, 10020
			m.android.email, 969, 1, 51, 0, 989, 10024
			ndroid.exchange, 989, 1, 51, 0, 0, 10025
		drmserver, 52, 1, 1, 0, 53, 1019
		mediaserver, 53, 1, 1, 0, 54, 1013
		installd, 54, 1, 1, 0, 55, 1012
		keystore, 55, 1, 1, 0, 56, 1017
		qemud, 56, 1, 1, 0, 59, 0
		sh, 59, 1, 1, 0, 60, 2000
		adbd, 60, 1, 1, 1028, 463, 0
			test_ptree, 1028, 0, 60, 0, 0, 0
		sdcard, 463, 1, 1, 0, 0, 1023
	kthreadd, 2, 1, 0, 67, 0, 0
		ksoftirqd/0, 3, 1, 2, 0, 4, 0
		kworker/0:0, 4, 1, 2, 0, 5, 0
		kworker/u:0, 5, 1, 2, 0, 6, 0
		khelper, 6, 1, 2, 0, 7, 0
		sync_supers, 7, 1, 2, 0, 8, 0
		bdi-default, 8, 1, 2, 0, 9, 0
		kblockd, 9, 1, 2, 0, 10, 0
		rpciod, 10, 1, 2, 0, 12, 0
		kswapd0, 12, 1, 2, 0, 13, 0
		fsnotify_mark, 13, 1, 2, 0, 14, 0
		crypto, 14, 1, 2, 0, 25, 0
		mtdblock0, 25, 1, 2, 0, 26, 0
		mtdblock1, 26, 1, 2, 0, 27, 0
		mtdblock2, 27, 1, 2, 0, 28, 0
		kworker/u:1, 28, 1, 2, 0, 29, 0
		binder, 29, 1, 2, 0, 30, 0
		mmcqd/0, 30, 1, 2, 0, 31, 0
		deferwq, 31, 1, 2, 0, 34, 0
		jbd2/mtdblock0-, 34, 1, 2, 0, 35, 0
		ext4-dio-unwrit, 35, 1, 2, 0, 38, 0
		flush-31:1, 38, 1, 2, 0, 40, 0
		jbd2/mtdblock1-, 40, 1, 2, 0, 41, 0
		ext4-dio-unwrit, 41, 1, 2, 0, 67, 0
		kworker/0:2, 67, 1, 2, 0, 0, 0
```
