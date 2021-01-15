////////////////////////////////////////////////////////////////////////////////////////////////////////
// 7. Write a program which accept directory name from user and delete all empty files.
//date: 17-9-2020
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char*argv[])
{
  DIR *dir;
  struct dirent *entry; 
  struct stat sobj; 
  char fname[257]={'\0'};
  int iret, icnt =0;
  
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
  
  //reading directory files
  while((entry=readdir(dir))!= NULL)
  {        
     // curent and parent directory not going to disply
     if((strcmp(entry -> d_name,"." )==0) || (strcmp(entry -> d_name,".." )==0))
          continue; 
  
    //create absolute path
    sprintf(fname,"%s/%s",argv[1], entry->d_name);
          
    //pass that absolute path to the stat fun to display file info     
    stat(fname, &sobj);
    printf("%10s\t  Size: %d\n", entry->d_name, (int)sobj.st_size);   
   
    // if regular directory
    if(S_ISREG(sobj.st_mode))
    {
         if((int)sobj.st_size == 0)
         {
            iret = remove(fname);
             icnt++;
         }
     }                                    
  }
 
  if(iret == 0 && icnt !=0)
  	printf("Succesfuly deleted empty files!\n"); 
  else if(iret == -1)
      printf("Error : Unable to deleted empty files!\n"); 
  else if(icnt == 0)
      printf("No Empty files present in directory!\n");   
  
  closedir(dir);
   return 0; 
}

