#include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
int main()
 {
int fd = open("/root/sysprogs/cars.txt", O_RDWR | O_APPEND);
if( fd == -1)
 {
 perror("No need to continue as we can't open the file\n");
 return 1;
 }
ssize_t tw1,tw2;
const char *buf1 = "Jaguar\n";
 const char *buf2 = "Tesla\n";
tw1 = write(fd,buf1,strlen(buf1));
if(tw1 == -1)
 {
 perror("Can't add Jaguar! \n");
 }
close(fd);
tw2 = write(fd,buf2,strlen(buf2));
if(tw2 == -1)
 {
 perror("Can't add Tesla! \n");
 }
 return 0;

 }
