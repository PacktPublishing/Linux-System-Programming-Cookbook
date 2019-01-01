#include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
int main()
 {
 const char *buf = "Don't forget to do your laundry! \n";
// tw is the total bytes written to from the file.
ssize_t tw;
int fd = open("/root/sysprogs/todo.txt", O_WRONLY | O_CREAT | O_APPEND);
if (fd == -1)
 {
 perror("Can't open the file! ... Exiting \n");
 return 1;
 }
tw = write(fd, buf, strlen(buf));
 printf("The value of tw is: %d \n", tw);
printf("Write File program finished Executing! \n");
 
 return 0;
 }
