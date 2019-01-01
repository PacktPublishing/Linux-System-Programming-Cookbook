#include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>
int main()
 {
 const int BUFSIZE=100;
 char buf[BUFSIZE];
// tr is the total bytes read from the file.
ssize_t tr;
int fd = open("/root/sysprogs/cars.txt", O_RDONLY);
if( fd == -1)
 {
 perror("No need to continue as we can't open the file\n");
 return 1;
 }
tr = read(fd,buf,BUFSIZE);
 // if tr == -1, then that's an error
printf("The value of tr is: %d \n", tr);
for(int i = 0; i < tr ;i++)
 {
printf("%c",buf[i]);
 }
printf("Read File program finished Executing! \n");
return 0;
 }
