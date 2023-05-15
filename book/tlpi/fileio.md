# File I/O

All system calls for performing I/ O refer to open files using a file descriptor, a (usually small) nonnegative integer.

```c
fd = open(pathname, flags, mode)
num_read = read(fd, buffer, count)
num_written = write(fd, buffer, count)
status = close(fd)
```

how to use lseek.

```c
// start of file
lseek(fd, 0, SEEK_SET);
// next byte after the end of the file
lseek(fd, 0, SEEK_END);
// last byte of the file
lseek(fd, -1, SEEK_END);
// ten bytes prior to the current location
lseek(fd, -10, SEEK_CUR);
// 10001 bytes past last byte of file
lseek(fd, 10000, SEEK_END);
```
