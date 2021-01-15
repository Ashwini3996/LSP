/////////////////////////////////////////////////////////////////////////
//1. Write a program which accept file name and mode from user and then 
//   open that file in specified mode.
//Date: 13-9-2020
///////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
  int fd=0, mode=0; 
 
  if(argc !=3)
  {
     printf("Error : Invalid argument !\n");
     printf("Mode Type:\n 1.read \n 2.write \n 3.read_write \n 4.create \n 5.truncate\n\n");
     printf("Enter Command: make help\n");
     return -1;
  }
 
  if((strcmp(argv[2], "read")==0))
  {
      mode = O_RDONLY;
  }
  else if((strcmp(argv[2], "write")==0))
  {
      mode = O_WRONLY;
  }
  else if((strcmp(argv[2], "read_write")==0))
  {
      mode = O_RDWR;
      printf("%d", mode);
  }
   else if((strcmp(argv[2], "create")==0))
  {
      mode = O_CREAT;
  }
   else if((strcmp(argv[2], "truncate")==0))
  {
      mode = O_WRONLY | O_TRUNC;
  }
  else 
  {
     printf("Error: Invalid argument !");
     return -1;
  }
 
  fd = open(argv[1], mode);
  if(fd ==-1)
  {
      printf("Error : Unable to open file !");
      close(fd);
      return -1;
  }
  else
  {
     printf("File open succesfully with FD:%d\n", fd);
     
  }
  
  close(fd);

return 0;
}
