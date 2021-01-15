///////////////////////////////////////////////////////////////////////////////////////////////
//4. Write a program which accept two file names from user and copy the contents of an
//	existing file into newly created file.
//Date: 17-09-2020
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{ 
  int fdRd=0, fdWr=0;
  int count =0, bytes=0; 
  char buffer[75]={'\0'};
  
  if(argc !=3)
  {
     printf("Error : Invalid argument !\n");
     return -1;
  }
    
  fdRd = open(argv[1],O_RDONLY);
  if(fdRd ==-1)
  {
     printf("Error: Unable to open file!\n");
     return -1;  
  }
  
  fdWr = open(argv[2],O_WRONLY);
  if(fdWr==-1)
  {
     printf("Error: Unable to open file!\n");
     return -1;
     
  }
  
     while((count = read(fdRd,buffer,sizeof(buffer))) !=0);    
      if(count==-1)
      {
         printf("Error: Unable to read!\n");
         close(fdRd);
         return -1;
      } 
     
      count = write(fdWr,buffer,strlen(buffer));
      if(count==-1)
      {
         printf("Error: Unable to read!\n");
         close(fdWr);
         return -1;
      }

      printf("Successfully written Data form file is:\n");
      write(1,buffer,count);
      
 
 close(fdRd);
 close(fdWr);
  
return 0;
}
