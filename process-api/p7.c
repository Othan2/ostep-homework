#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // int fd = open("./p2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "error forking\n");
        return 1;
    }
    else if (rc == 0) // child
    {
        close(STDOUT_FILENO);
        fprintf(stdout, "hello from child\n");
    }
    else // parent
    {
        int stat_loc;
        waitpid(rc, &stat_loc, WCONTINUED);
        fprintf(stdout, "status: %d\n", stat_loc);
        fprintf(stdout, "goodbye\n");
    }
    return 0;
}