include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 
 
 int main(int argc, char const *argv[])
 {
 char name[100] = "myTmp-XXXXXX";
 
 int fd;
 
 fd = mkstemp(name);
 sleep(10); 
 unlink(name);
 return 0;
 }
