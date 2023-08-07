#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open("./p2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    close(STDOUT_FILENO);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "error forking\n");
        return 1;
    }
    else if (rc == 0)
    {
        write(fd, "hello from child!\n", 19);
        write(fd, "hello from child!\n", 19);
        write(fd, "hello from child!\n", 19);
    }
    else
    {        
        write(fd, "hello from parent!\n", 20);
        write(fd, "hello from parent!\n", 20);
        write(fd, "hello from parent!\n", 20);
    }
    return 0;
}