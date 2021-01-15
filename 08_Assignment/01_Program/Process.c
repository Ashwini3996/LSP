#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char*argv[])
{
  DIR *dir = NULL;
  struct dirent *entry; 
  struct stat sobj; 
  char fname[272]={'\0'};
  char buff[272]={'\0'};
  char buffer[120]={'\0'};
  int fd=0, ret=0;   

  fd = open("Demo.txt", O_RDWR | O_CREAT |O_APPEND ,0777);
  if(fd ==-1)
  {
     printf("Error: Unable to create file!\n ");
     return -1;
  } 
  
  if((dir=opendir(argv[0]))==NULL)
  {
     printf("Error: Unable to open specified directory!\n ");
     return -1;
  } 
  
  while((entry=readdir(dir))!= NULL)
  {
    //create absolute path
    sprintf(fname, "%s/%s",argv[0], entry->d_name);  
    stat(fname, &sobj);
    
    if(S_ISREG(sobj.st_mode))
      sprintf(buff, "%s:%s","Regular File", entry->d_name);
   else if(S_ISDIR(sobj.st_mode)) 
       sprintf(buff, "%s:%s","Directory File", entry->d_name);
    else if(S_ISLNK(sobj.st_mode)) 
        sprintf(buff, "%s:%s","Link File", entry->d_name);

   write(fd, buff, strlen(buff));
  }
 printf("Contains gets Succesfully writern into the file!");
  
  closedir(dir);
   close(fd);
   return 0; 
}

