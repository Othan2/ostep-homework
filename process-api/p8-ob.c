#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int fds[2];
    char read_buf[80];
    pid_t rc;

    pipe(fds);

    if ((rc = fork()) < 0) {
        perror("error forking");
        exit(1);
    }

    // what happens if I don't close file descriptors?
    // "On a technical note, the EOF will never be returned if the unnecessary ends of the pipe are not explicitly closed."

    if (rc == 0) {
        // lets send a message
        // don't need to read pipe output, let's close it
        close(fds[0]);
        char msg[] = "message from child process!";
        write(fds[1], msg, sizeof(msg));

        fprintf(stdout, "fds: %d, %d\n", fds[0], fds[1]);
        exit(0);
    }
    else {
        // lets read a message
        // don't need to input anything to pipe, let's close that
        close(fds[1]);
        read(fds[0], &read_buf, sizeof(read_buf));


        fprintf(stdout, "fds: %d, %d\n", fds[0], fds[1]);
        printf("got message via pipe: %s\n", read_buf);
    }

    return 0;
}