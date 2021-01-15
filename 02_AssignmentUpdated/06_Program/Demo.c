///////////////////////////////////////////////////////////////////////////////////////////////
//6.Write a program which accept file name from user and read whole file.
//Date: 16-09-2020
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{ 
  int fd=0, count =0; 
  char buffer[512];
  
  if(argc !=2)
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
      count = read(fd,buffer,sizeof(buffer));
      if(count==-1)
      {
         printf("Error: Unable to read!\n");
         close(fd);
         return -1;
      }
      
      printf("Data is:\n %s", buffer);
      close(fd);
  }
  
return 0;
}
