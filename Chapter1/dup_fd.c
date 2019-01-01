#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
 
int main(int argc, char **argv)
{
    int fd, nfd;
 

 
    /* opening the file in write-only mode */
    if ((fd = open("dup.txt", O_WRONLY)) < 0) {
        printf("Problem in opening the file");
        exit(1);
    }
 
    /* duplicating fd with nfd */
    if ((nfd = fcntl(fd, F_DUPFD, 0)) == -1) {
        printf("Problem in duplicating fd");
        exit(1);
    }
    write(nfd,"This will be output to the file named dup.txt\n", 46);

    printf("Fd %d duplicated with %d\n", fd, nfd);

    close(fd);
    close(nfd);
}
