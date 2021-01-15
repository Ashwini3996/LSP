////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//6.Write a program which accept two directory name from user and move all files from source directory to destination directory.
//date: 17-9-2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[])
{
  DIR *dirSource, *dirDest;
  struct dirent *entry; 
  char SrcName[257]={'\0'};
  char DstName[257]={'\0'};
  int iret=0;
   
  if(argc != 3)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }
  
  if((dirSource=opendir(argv[1]))==NULL)
  {
     printf("Error: Unable to open source directory!\n ");
     return -1;
  } 
  
  if((dirDest=opendir(argv[2]))==NULL)
  {
     printf("Error: Unable to open destination directory!\n ");
     return -1;
  } 
     
   //reading directory files
   while((entry=readdir(dirSource))!= NULL)
   {
        
     // curent and parent directory not going to disply
     if((strcmp(entry -> d_name,"." )==0) || (strcmp(entry -> d_name,".." )==0))
          continue; 
  
    
     //create absolute path for oldpath
     sprintf(SrcName, "%s/%s",argv[1], entry -> d_name);
     printf("SrcName :%s\n",SrcName);
     
     //create absolute path for oldpath
     sprintf(DstName, "%s/%s",argv[2], entry -> d_name);
     printf("DstName :%s\n",DstName);
      
      //int rename(const* char oldpath, const* char newpath)
      iret = rename(SrcName, DstName); 
     }
   
   printf("\n");
   if(iret == 0)
      printf("Succesfully moved file destination directory !");
   else
      printf("Failed to moved file into destination directory !");
   
   
   closedir(dirDest);
   closedir(dirSource);
   
   return 0; 
}






    

