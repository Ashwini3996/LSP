///////////////////////////////////////////////////////////////////////////////////////////////////////
//5.Write a program which accept file name and position from user and read 20 bytes from that position.
//Date: 13-9-2020
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
  int fd=0, ret=0;
  char buffer[128]={'\0'};
  
  if(argc !=3)
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

  lseek(fd,atoi(argv[2]), SEEK_SET);
  ret = read(fd, buffer, 20);
  if(ret ==-1)
  {
      printf("Error : Unable to read file !");
      close(fd);
      return -1;
  } 
    
  printf("Data from file is:\n");  
  write(1, buffer, ret);   
  close(fd);

return 0;
}
