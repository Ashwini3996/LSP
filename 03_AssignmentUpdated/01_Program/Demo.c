///////////////////////////////////////////////////////////////////////////////
//1. Write a program which accept directory name from user and print all file 
//      names from that directory.
//date: 17-9-2020
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char*argv[])
{
  DIR *dir;
  struct dirent *entry;
  
  if(argc != 2)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }
  
  //opendir(): system call opens directory and returns pointer to DIR structure
  
  if((dir=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  
  printf("Contents of directory:\n");
  
  while((entry=readdir(dir))!= NULL)
  {
    printf("Name %s\t Inode:%ld\n", entry->d_name, entry->d_ino);
  }
  
  closedir(dir);
   return 0; 
}

