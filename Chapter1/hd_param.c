#include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <linux/hdreg.h>
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
 
 int main(int argc, char *argv[])
 {
 int fd;
 
 static struct hd_driveid hd;
 
 if ((fd=open("/dev/sda", O_RDONLY|O_NONBLOCK))<0) {
 fprintf(stderr,"ERROR: Cannot open device /dev/sda\n");
 
 }
 
 if (!ioctl(fd, HDIO_GET_IDENTITY, &hd)) {
 
 fprintf(stderr,"Hard Disk Model: %.40s\n", hd.model);
 fprintf(stderr,"Serial Number: %.20s\n", hd.serial_no);
 
 close(fd);
 }
 else if (errno == -ENOMSG) {
 fprintf(stderr,"No hard disk identification information available\n");
 close(fd);
 } else {
 perror("IOCTL");
 }
 
 return 0;
 }
