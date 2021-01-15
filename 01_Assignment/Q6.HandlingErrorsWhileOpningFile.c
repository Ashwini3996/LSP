///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept file name from user and open that file and  
//                  file is not opened properly then display error message properly.
//Developed By    : Ashwini Sharad Palve
//Input           : File name
//Output          : Open file
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main( int argc, char* argv[0])
{
  int fd=0;
  
  if(argc !=3)
  {
      printf("Invalid number of argument!");
      return -1;
  }
  
  if((strcmp(argv[2],"-h")==0)||(strcmp(argv[2],"-H")==0))
  {
       printf("Usage: ./a.out Executable_Name File_Name");
       return 0;
  }
  
 fd=open(argv[2],O_RDONLY);
 if(fd==-1)
 {
    printf("Unable to open file!");
 }
 else
 {
    printf("File gets successfully Opend with FD:%d", fd);
 }
 
 close(fd);
 
return 0;
}
