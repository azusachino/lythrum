# lythrum

Lythrum リスラム 禊荻（千屈菜）

## Description

Where I learn Linux and C.

## Progress

Now reading APUE.

## Setup apue.h environment

**Important**:

if encountered this problem below, you need to install `libbsd` and `libbsd-devel` (centos)

```sh
gcc -ansi -I../include -Wall -DLINUX -D_GNU_SOURCE  barrier.c -o barrier  -L../lib -lapue -pthread -lrt -lbsd
/tmp/cczvZtnw.o: In function `thr_fn':
barrier.c:(.text+0x80): undefined reference to `heapsort'
collect2: error: ld returned 1 exit status
make[1]: *** [barrier] Error 1
make[1]: Leaving directory `/home/APUE/apue.3e/threads'
make: *** [all] Error 1
```

1. download apue src [package](http://www.apuebook.com/src.3e.tar.gz)
2. run `make`
3. copy `apue.h` to `/usr/include/` (I don't know, my make procedure failed)
