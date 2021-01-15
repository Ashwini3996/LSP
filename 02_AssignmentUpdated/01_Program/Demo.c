/////////////////////////////////////////////////////////////////////////
//1. Write a program which accept file name from user and open that file.
//Date: 13-9-2020
///////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char* argv[])
{
  int fd=0;
  
  if(argc !=2)
  {
     printf("Error : Invalid argument !");
     return -1;
  }
  
  fd = open(argv[1], O_RDONLY);
  
  if(fd ==-1)
  {
      printf("Error : Unable to open file !");
      close(fd);
      return -1;
  }
  else
  {
     printf("File open succesfully with FD:%d", fd);
     
  }
  
  close(fd);

return 0;
}
