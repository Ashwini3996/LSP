///////////////////////////////////////////////////////////////////////////////////////
//5. Write a program which accept directory name and from user and copy first 10 byest 
//	from all regular files into newly created file named as Demo
//date: 17-9-2020
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

void ReadNewFile(char* newFile)
{
  int fdNew=0, ret=0;
 char buffer[128]={'\0'};
  
   fdNew = open(newFile, O_RDONLY);
   if(fdNew ==-1)
   {
      printf("Error:Unable to open new file!");
      return;
   }  
   
   ret =  read(fdNew, buffer, sizeof(buffer));
   if(ret ==-1)
   {
      printf("Error:Unable to read directory file!");
      close(fdNew);
      return;
   } 
   
    printf("Data from file is:\n");
    write(1, buffer, ret); 
    
    close(fdNew);  
}

void DirectoryFileCopy(char* path, char* newFile)
{
   int fdDir = 0, fdNew=0;
   char buffer[128]={'\0'};
   int ret =0;

   fdNew = open(newFile, O_WRONLY | O_APPEND);
   if(fdNew ==-1)
   {
      printf("Error:Unable to open new file!");
      return;
   }    
     
   fdDir = open(path, O_RDONLY);
   if(fdDir ==-1)
   {
      printf("Error:Unable to open directory file!");
      return;
   }   

   ret =  read(fdDir, buffer, 10);
   if(ret ==-1)
   {
      printf("Error:Unable to read directory file!");
      close(fdDir);
      return;
   }   
 
   write(fdNew, buffer, ret);
  
    
 close(fdDir);
 close(fdNew);
}

int main(int argc, char*argv[])
{
  DIR *dir;
  struct dirent *entry; 
  struct stat sobj; 
  char fname[257]={'\0'};
  int iret=0, fd=0;
   
  if(argc != 3)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }
       
   fd = creat(argv[2], 0777);
   if(fd ==-1)
   {
      printf("Error:Unable to create file!");
      return -1;
   }      
    
  if((dir=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  
   //reading directory files
   while((entry=readdir(dir))!= NULL)
   {
        
     // curent and parent directory not going to disply
     if((strcmp(entry -> d_name,"." )==0) || (strcmp(entry -> d_name,".." )==0))
          continue; 
  
    //create absolute path
    sprintf(fname, "%s/%s",argv[1], entry->d_name);
    stat(fname, &sobj);  
    printf("Directory File :%s\n", entry->d_name);   
          
     //if regular directory
     if(S_ISREG(sobj.st_mode))
         DirectoryFileCopy(fname, argv[2]);                  	           
   }
    ReadNewFile(argv[2]);  
   closedir(dir);
   return 0; 
}






    

