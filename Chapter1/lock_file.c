#include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <sys/file.h>
 
 
 int main(int argc, char const *argv[])
 {
 int fd;
 char *buff = "File is locked";
 
 fd = open("hello.txt", O_CREATE | O_WRONLY);
 
 write(fd,buff,strlen(buff));
 
 if (flock(fd, LOCK_EX| LOCK_NB) < 0) {
 printf("file is locked\n");
 return 0;
 }
 sleep(10);
 flock(fd, LOCK_UN);
 close(fd);
 return 0;
 }
