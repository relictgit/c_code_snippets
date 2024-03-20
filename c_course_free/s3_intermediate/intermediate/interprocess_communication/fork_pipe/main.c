#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[2]; // creation of 1 pipe
    // fd[0] = read end
    // fd[1] = write end

    if(pipe(fd) == -1) {
        fprintf(stderr, "An error occured with opening the pipe \"fd\"\n");
        return 1;
    }

    int id = fork();

    /* while forking the file descriptors gets
     * inherited, so there are more than 2 ends to close.
     * fd[0] & fd[1] * 2.*/

    if(id < 0) {
        fprintf(stderr, "Fork has failed, check for max process count and memory\n");
        return 1;
    } else if(id == 0) {
        /* parent process */
        /* writing through pipe */
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        /* write(fd[1], &x, sizeof(x)); */
        if(write(fd[1], &x, sizeof(x)) < 0) {
            fprintf(stderr, "(PARRENT) writing to pipe has failed\n");
            return 2;
        }
        close(fd[1]);
    } else {
        /* child process */
        /* reading from pipe */
        close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(y)) < 0) {
            fprintf(stderr, "(CHILD) reading from pipe has failed\n");
            return 3;
        }
        close(fd[0]);
    }

    return 0;
}
