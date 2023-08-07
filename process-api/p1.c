#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "error forking\n");
        return 1;
    }
    else if (rc == 0)
    {
        fprintf(stdout, "hello from child! x = %d\n", x);
        x = 23;
        fprintf(stdout, "hello again from child! x = %d\n", x);
    }
    else
    {
        fprintf(stdout, "hello from parent! x = %d\n", x);
        x = 87;
        fprintf(stdout, "hello again from parent! x = %d\n", x);
    }
    return 0;
}