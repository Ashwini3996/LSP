#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h> 
#include<dirent.h> 
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h> 

 int main(int argc, char * argv[])
 {
   
   int fdDemo =0, fdCount = 0, ret =0, count =0;
   char buffer[120]={'\0'}; 
   char buff[257]={'\0'}; 


   fdDemo = open("Demo.txt",O_RDONLY);
   if(fdDemo ==-1)
   {
      printf("Error : Unable to open Demo.txt file!");
      return -1;
   }
   
   fdCount = open("Count.txt",O_WRONLY | O_APPEND);
   if(fdCount ==-1)
   {
      printf("Error : Unable to open Count.txt file!");
      return -1;
   }
    
     while((ret = read(fdDemo, buffer, sizeof(buffer))) !=0)
     {
               for(int i=0; i<ret;i++)
               {
                  if((buffer[i]>='A') && (buffer[i] <='Z'))  
                  count++;             
               }
     }
    
    sprintf(buff,"%s %d","Capital Count:", count);    
    write(fdCount,buff, strlen(buff));     
     
    close(fdDemo);
    close(fdCount);
 return 0;
 }

