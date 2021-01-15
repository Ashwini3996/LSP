/////////////////////////////////////////////////////////////////////////////////////////////
//3.Write a program which accept file name and on mode and that program check whether our
//      process can access that file in accepted mode or not.
//Date: 16-09-2020
//////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
  int fd=0, mode =0;
  
  if(argc !=3)
  {
     printf("Error : Invalid argument !\n");
     printf("Access Type:\n 1.read \n 2.write \n 3.read_write \n\n");
     printf("Command: make help");
     return -1;
  }
  
  if((strcmp(argv[2], "read")==0))
  {
      mode = R_OK;
  }
  else if((strcmp(argv[2], "write")==0))
  {
      mode = W_OK;
  }
  else if((strcmp(argv[2], "read_write")==0))
  {
      mode = X_OK;
  }
  else
  {
      printf("Error:Invalid Mode!\n");
      return -1;
  }
  
  
  if(access(argv[1],mode)<0)
  {
      printf("Error : Our process canot access this file for %s purpose!\n", argv[2]);
      return -1;
  }
  else
  {
     printf("Our process has %s access\n",argv[2]);
     
  }
  
  close(fd);

return 0;
}
