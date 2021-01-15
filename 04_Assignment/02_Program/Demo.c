///////////////////////////////////////////////////////////////////////////////
//2. Write a aprogram which accept directory name from user and create new 
//	directory of that name.
//date: 24-9-2020
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char*argv[])
{
  DIR *dir;
  struct dirent *entry;
  char buffer[128];
  
  if(argc != 2)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }
  
  strcpy(buffer,argv[1]);   

  //opendir(): system call opens directory and returns pointer to DIR structure  
  if((dir=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  else
   {
      //cheak if user supplied '/' at the end of dorectory name
      //based on it create conitaining path to new directory name 'newDir'
      if(buffer[strlen(buffer)-1]=='/')
      { 

         strncpy(buffer+strlen(buffer), "newDir/",7);
         printf("if part path:%s\n", buffer);
      }
      else
      {
           strncpy(buffer+strlen(buffer), "/newDir/",8);
           printf("else part path:%s\n", buffer);
      }
  }

  printf("creating new directory in %s \n", buffer);
  mkdir(buffer,S_IRWXU|S_IRWXG|S_IRWXO);
  
  printf("Contents of directory:\n");  
  while((entry=readdir(dir))!= NULL)
  {
    printf("Name %s\t\t\t Inode:%ld\n", entry->d_name, entry->d_ino);
  }
  
  closedir(dir);
   return 0; 
}

