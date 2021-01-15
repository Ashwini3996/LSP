///////////////////////////////////////////////////////////////////////////////
//2.Write a program which accept directory name from user and print all file names
// 	and its types from that directory.
//date: 17-9-2020
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char*argv[])
{
  DIR *dir;
  struct dirent *entry; 
  struct stat sobj; 
  char fname[255]={'\0'};
  
  if(argc != 2)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }
  
  if((dir=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  
  printf("Contents of directory:\n");
  
  while((entry=readdir(dir))!= NULL)
  {
    //create absolute path
    sprintf(fname, "%s/%s",argv[1], entry->d_name);
    
    stat(fname, &sobj);
    printf("%30s:", entry->d_name);
    
    if(S_ISREG(sobj.st_mode))
      printf("Regular File\n");
   else if(S_ISDIR(sobj.st_mode)) 
      printf("Directory File\n");
    else if(S_ISLNK(sobj.st_mode)) 
      printf("Link\n"); 
  }
  
  closedir(dir);
   return 0; 
}

