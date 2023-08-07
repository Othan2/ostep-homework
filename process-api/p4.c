#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // int fd = open("./p2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    // close(STDOUT_FILENO);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "error forking\n");
        return 1;
    }
    else if (rc == 0) // child
    {
        fprintf(stdout, "child here, gonna echo:\n");
        char *cmd = "/bin/echo";
        char *argv[3];
        argv[0] = "/bin/echo";
        argv[1] = "echo echo";
        argv[2] = NULL;
        execvp(cmd, argv);
    }
    
    return 0;
}