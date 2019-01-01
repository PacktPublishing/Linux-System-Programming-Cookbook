#include <stdio.h>
 // fcntl.h - file control options
 #include <fcntl.h>
int main()
 {
 int fd = open("/root/sysprogs/testfile1", O_RDONLY);
 printf("The fd returned for testfile1: %d \n", fd);
 
 // if the value returned from fd is -1 then this means there is an error.
int fd2 = open("/root/sysprogs/testfile2", O_RDWR | O_CREAT);
 printf("The fd returned for testfile2: %d \n", fd2);
int fd3 = open("/root/sysprogs/testfile3", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
 printf("The fd retuned for testfile3: %d \n", fd3);
printf("Open File program finished Executing!\n");
return 0;
 }
