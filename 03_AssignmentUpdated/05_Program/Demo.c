///////////////////////////////////////////////////////////////////////////////
//5. Write a program which accept directory name and file name from user and 
//	check whether that file is present in that directory or not.
//date: 17-9-2020
///////////////////////////////////////////////////////////////////////////////

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
  char FileName[257]={'\0'};
  int iret=0;
   
  if(argc != 3)
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
    sprintf(fname, "%s/%s",argv[1], entry->d_name);
     
     
    //pass that absolute path to the stat fun to display file info     
    stat(fname, &sobj);
    printf("%10s\t   Size: %d\n", entry->d_name, (int)sobj.st_size);
  
     //if regular directory
     if(S_ISREG(sobj.st_mode))
     {
         memset(FileName,0,sizeof(FileName));
            
         //store name 
         strcpy(FileName, entry->d_name);    
         iret=strcmp(entry -> d_name, argv[2]); 
       
        if(iret==0)
         break;
     }
   }
 
   if(iret==0)
   {
    printf("\nFile %s Present in given directory!\n", FileName); 
   }
   else
   {
     printf("\nFile %s File %s is not Present\n", FileName); 
   }
   closedir(dir);
   return 0; 
}






    

