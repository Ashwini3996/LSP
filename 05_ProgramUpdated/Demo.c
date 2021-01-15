/////////////////////////////////////////////////////////////////////////////////////////////////////////
//5. Write a program which accept file name from user and offset, remove all the data from that offset.
//Date:26-09-2020
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{

  int fd =0, ret=0, res=0; 
  char buffer[128]={'\0'}; 
   
  if(argc != 3)
 {
    printf("Error: Inavlid Argument!\n");
    printf("Usage : Executable_Name File_Name\n");
    return -1;
 }
 
 fd =  open(argv[1], O_RDWR); 
 if(fd == -1)
 {
   printf("Error: Unable to open !");
   return -1;
 }
 
 ret = truncate(argv[1], atoi(argv[2]));
 if(ret == -1)
 {
   printf("Error: Unable to truncate !");
   return -1;
 }
 
  printf("Data after truncating:\n");
  res = read(fd, buffer, sizeof(buffer));
  write(1, buffer, res);
 
 close(fd);
 return 0;
}
