#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 
 int main(int argc, char const *argv[])
 {
 int fd, ret, b;
 int a[5] = {1, 2, 3, 4, 5};
 
 fd = open("numbers.txt", O_CREAT | O_APPEND | O_RDWR); /* open example.txt */
 if (fd < 0) { /* check if file opened successfully */
 perror("Can not open a file");
 exit(1);
 }
 
 ret = write(fd, (void ) a, sizeof(a)); /* write the a[] array to the file */
 
 if (ret < 0) { 
 perror("Can not write to a file");
 close(fd);
 exit(1);
 }
 
 ret = lseek(fd, 3*sizeof(int), SEEK_SET);  /* move the cursor 12 byte after start of file*/

 if (ret< 0) {
 perror("Can not move cursor");
 close(fd);
 exit(1);
 }
 
 ret = read(fd, &b, sizeof(int)); /* read 4 byte from a file and assign it to variable b */
 
 if (ret < 0) {
 perror("Can not read from file");
 close(fd);
 exit(1);
 }
 
 printf(" b = %d\n", b); /* print the value of b*/
 close(fd);
 
 return 0;
 }
