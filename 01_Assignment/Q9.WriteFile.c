///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept filename and string from 
//		    user and write that string into file.
//Developed By    : Ashwini Sharad Palve
//Input           : File name
//Output          : String Written into file
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
   
   int fd=0, ret;
   char buffer[20];
   
   if(argc != 4)
   {
      printf("Error:Invalid argument! \n");
      printf("Command for help: ./a.out Executable_Name -h \n");
      return -1;
   }
   
   
   if((strcmp(argv[2],"-h") ==0)|| (strcmp(argv[2],"-H") ==0))
   {
      printf("Usage: ./a.out Executable_Name File_Name String_To_Write_On_File");
      return 0;
   }
   
   // If file is opened in write mode we can read the contents from 0 byte offset	
   fd = open(argv[2],O_RDWR);
   
   if(fd==-1)
   {
      printf("Unable to open file!\n");
      return -1;
   }
   else
   {
 	strcpy(buffer,argv[3]);        
        ret = write(fd,buffer,strlen(buffer));// read system call returns no of bytes successfully write.
                                              // It returns -1 if it fails to write   
                                           
       if(ret != strlen(buffer))
	{
		printf("Unable to write contents\n");
	}
	
      ret = read(fd,buffer,sizeof(buffer)); 
      printf("Written contents are : %s\n",buffer);     
	 
      close(fd);
      close(ret);                                             
   }
    
  
return 0;
}















