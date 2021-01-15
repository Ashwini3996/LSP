///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept file name and read first 
//                  5 characters from it.
//Developed By    : Ashwini Sharad Palve
//Input           : File name
//Output          : 5 charcters
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
   
   int fd=0;
   char buffer[512];
   int iCnt=0;
  
   if(argc != 3)
   {
      printf("Error:Invalid argument!\n");
      return -1;
   }
   
   if((strcmp(argv[2],"-h") ==0)|| (strcmp(argv[2],"-H") ==0))
   {
      printf("Usage: ./a.out Executable_Name File_Name");
      return 0;
   }
   
   fd = open(argv[2],O_RDONLY);
   
   if(fd==-1)
   {
      printf("Unable to open file!\n");
      return -1;
   }
   else
   {
     printf("Characters from file is:\n");
     
    read(fd,buffer,5);
    printf("%s\n",buffer);
       
   }
  
  close(fd);

return 0;
}
