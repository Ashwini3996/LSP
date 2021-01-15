//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//7. Write a program which is used to print home directory and login user name.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char*argv[])
{
  DIR *dir = NULL;
  struct dirent *entry; 
  struct stat sobj; 
  char fname[272]={'\0'};

   char * len;


  if((dir=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  
  while((entry=readdir(dir))!= NULL)
  {
    //create absolute path
    sprintf(fname, "%s/%s",argv[1], entry->d_name);  
    stat(fname, &sobj);
    
    if(S_ISREG(sobj.st_mode))
      printf("Regular File: %s\n", entry->d_name);
   else if(S_ISDIR(sobj.st_mode)) 
       printf("Derectory File: %s\n", entry->d_name);
    else if(S_ISLNK(sobj.st_mode)) 
       printf("Link: %s\n", entry->d_name);
    }

   
if((len = getlogin())==NULL)
{
   printf("Failed to get user informetion\n");
}
else
{
  printf("User Name is:%s\n", len);
}  
  closedir(dir);
   return 0; 
}

