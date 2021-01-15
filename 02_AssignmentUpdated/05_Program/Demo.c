///////////////////////////////////////////////////////////////////////////////////////////////
//5.Write a program which accept file name and number of bytes from user and read that
//      number of bytes from file.
//Date: 16-09-2020
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{ 
  int fd=0;
  int count =0, bytes=0; 
  char buffer[256];
  
  if(argc !=3)
  {
     printf("Error : Invalid argument !\n");
     return -1;
  }
    
  fd = open(argv[1],O_RDONLY);
  if(fd==-1)
  {
     printf("Error: Unable to open file!\n");
     return -1;     
  }
  else
  {
  
      bytes = atoi(argv[2]);
      count = read(fd,buffer,bytes);
      if(count==-1)
      {
         printf("Error: Unable to read!\n");
         close(fd);
         return -1;
      }
      
      printf("Read Data is: %s", buffer);
      close(fd);
  }
  
return 0;
}
