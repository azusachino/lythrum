#include <lythrum.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

#define MAX_READ 20

int main(int argc, char *argv[], char **env_)
{
    read_from_terminal();
    _exit(0);
}

void copy(int argc, char *argv[])
{

    int input_fd, output_fd, open_flags;
    mode_t file_perms;
    ssize_t num_read;
    char buf[BUF_SIZE];

    if (argc != 3)
    {
        printf("fail to check params\n");
        _exit(-1);
    }

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
    {
        printf("fail to open file\n");
        _exit(-1);
    }

    open_flags = O_CREAT | O_WRONLY | O_TRUNC;
    // rw-rw-rw-
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    output_fd = open(argv[2], open_flags, file_perms);
    if (output_fd == -1)
    {
        printf("fail to open file\n");
        _exit(-1);
    }

    while ((num_read = read(input_fd, buf, BUF_SIZE)) > 0)
    {
        if (write(output_fd, buf, num_read) != num_read)
        {
            printf("fail to write the whole buffer");
        }
    }
    if (num_read == -1)
    {
        _exit(-1);
    }

    close(input_fd);
    close(output_fd);
}

void read_from_terminal()
{
    char buf[MAX_READ];
    if (read(STDIN_FILENO, buf, MAX_READ) == -1)
    {
        _exit(-1);
    }
    printf("the input data is: %s\n", buf);
}

void read_from_terminal1()
{
    char buf[MAX_READ + 1];
    ssize_t num_read;

    num_read = read(STDIN_FILENO, buf, MAX_READ);

    if (num_read == -1)
    {
        _exit(-1);
    }
    buf[num_read] = '\0';
    printf("the input data is: %s\n", buf);
}