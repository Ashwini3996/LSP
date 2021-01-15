///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept file name from user and read whole file.
//Developed By    : Ashwini Sharad Palve
//Input           : File name
//Output          : All file containts
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
   
   int fd=0;
   char buffer[30];
   int ret=0, offset=0;
  
  
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
      ret = read(fd,buffer,sizeof(buffer));
     
      if(ret != 20)
      {
		printf("Unable to read contents\n");
      }

       printf("Read contents are :%s\n",buffer);

      // After reading 20 bytes current offset is changed by 20 bytes

	offset = lseek(fd,0,SEEK_CUR);
	printf("After reading 20 bytes current byte offset is %d\n",offset);     
   }
  
  close(fd);

return 0;
}
