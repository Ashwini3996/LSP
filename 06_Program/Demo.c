////////////////////////////////////////////////////////////////////////////////////////////////////
//6. Write a program which accept directory name from user and create hole in file if size is less 
//	than 1kb & if it is greater than 1kb then truncate the remaining data.
//Date:26-09-2020
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define SIZE 1024

void CreateHole(char* fname)
{

 struct stat sobj;
 int fd =0, ret=0;  
 
 fd =  open(fname, O_RDWR); 
 if(fd == -1)
 {
 
   printf("Error: Unable to open !");
   return;
 }
 
 ret = lseek(fd, 1024, SEEK_END);
 printf("%d", ret);
 
 //Before writing any character into the file, file size is 883
 //After writing one character size of file became 1908 bytes 
 write(fd, " ", 1);
 
 ret = stat(fname, &sobj);
 printf("Size after truncating File is:%ld\n", sobj.st_size);
 
 close(fd); 
}

void TruncateFile(char * fname, int pos )
{
  struct stat sobj;
  int fd =0, ret=0, res=0; 
  char buffer[1024]={'\0'}; 

 fd =  open(fname, O_RDWR); 
 if(fd == -1)
 {
   printf("Error: Unable to open !");
   return;
 }
 
 ret = truncate(fname,  pos);
 if(ret == -1)
 {
   printf("Error: Unable to truncate !");
   return;
 }
 
 ret = stat(fname, &sobj);
 printf("Size after truncating File is:%ld\n", sobj.st_size);
   close(fd);
}

int main(int argc, char* argv[])
{

  DIR *dir=NULL;
  struct dirent *dip = NULL;
  struct stat sobj;
  int fdDest =0, ret=0;  
  char fname[257]={'\0'};  
   
  if(argc !=2)
 {
    printf("Error: Inavlid Argument!\n");
    printf("Usage : Executable_Name Directory_Name \n");
    return -1;
 }
 
 dir = opendir(argv[1]);
 if(dir==NULL)
 {
   printf("Error :Unable to Open Directory!");
   return -1;
 }
 
  printf("Contents from Directory are:\n");              
  while((dip =readdir(dir))!=NULL)
  {  
            
     sprintf(fname, "%s/%s", argv[1],dip->d_name);
     ret = stat(fname, &sobj);
     
     if(S_ISREG(sobj.st_mode))
     {
        
        if(sobj.st_size < SIZE) //create hole in file if size is less than 1kb 
        {
            printf("File Name:%s \n Size of File is:%ld\n", dip->d_name, sobj.st_size);
            CreateHole(fname); 
                      
        }
        else // if it is greater than 1kb then truncate the remaining data.
        {
           printf("File Name:%s \n Size of File is:%ld\n", dip->d_name, sobj.st_size);
           TruncateFile(fname, SIZE);  
           
        }	
     }    
  }

close(fdDest);
closedir(dir);
return 0;
}
