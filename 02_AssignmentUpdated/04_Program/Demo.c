///////////////////////////////////////////////////////////////////////////////////////////////
//4.Write a program which accept file name from user and print all information about that file.
//Date: 16-09-2020
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[])
{
 
  struct stat sobj;
  struct tm dt;
  int ret;
  
  if(argc !=2)
  {
     printf("Error : Invalid argument !\n");
     return -1;
  }
    
  ret = stat(argv[1],&sobj);
  if(ret)
  {
    printf("Error: stat function fail\n");
     return -1;
  }  
  
  printf("File: %s\n",argv[1]);
  printf("ID Device: %ld \n",sobj.st_dev); 
  printf("Inode: %ld \t",sobj.st_ino); 
  printf("Link : %ld \t",sobj.st_nlink); 
  printf("Uid :%d \n",sobj.st_uid); 
  printf("Gid :%d \t",sobj.st_gid); 
  printf("Size :%ld \t",sobj.st_size); 
  printf("IO Blocks :%ld \n",sobj.st_blksize); 
  printf("Blocks :%ld \t",sobj.st_blocks); 
  
  dt=*(gmtime(&sobj.st_atime));
  printf("\nLast Access  :%d-%d-%d %d:%d:%d",dt.tm_mday, dt.tm_mon, dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec); 
  
  dt=*(gmtime(&sobj.st_mtime));
  printf("\nLast Modification :%d-%d-%d %d:%d:%d",dt.tm_mday, dt.tm_mon, dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec); 
  
  dt=*(gmtime(&sobj.st_ctime));
  printf("\nStatus change time: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year+1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
  
   printf("File Permissions: \t");

	printf( (S_ISDIR(sobj.st_mode)) ? "d" : "-");
	printf( (sobj.st_mode & S_IRUSR) ? "r" : "-");
	printf( (sobj.st_mode & S_IWUSR) ? "w" : "-");
	printf( (sobj.st_mode & S_IXUSR) ? "x" : "-");
	printf( (sobj.st_mode & S_IRGRP) ? "r" : "-");
	printf( (sobj.st_mode & S_IWGRP) ? "w" : "-");
	printf( (sobj.st_mode & S_IXGRP) ? "x" : "-");
	printf( (sobj.st_mode & S_IROTH) ? "r" : "-");
	printf( (sobj.st_mode & S_IWOTH) ? "w" : "-");
	printf( (sobj.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
  
return 0;
}
