#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h> 
#include<dirent.h> 
#include<sys/types.h>
#include<sys/stat.h>

 int main(int argc, char * argv[])
 {
                
   int fd =0, ret = 0, cnt=1 ;
   DIR *dir;
   struct stat sobj;
   struct dirent *dobj; 
   char buff[257]={'\0'}; 
   char fname[257] = {'\0'};    

   if((dir = opendir(argv[0])) == NULL)
   {
      printf("Error : Unable to open Directory!");
      return -1;
   }
   
   while((dobj = readdir(dir))!=NULL)
   {
     sprintf(fname, "%s/%s",argv[0], dobj->d_name);
     stat(fname, &sobj);  
     sprintf(buff, "%s/%d.%s",argv[0], cnt, "txt");
     
     if(S_ISREG(sobj.st_mode))
     {
             ret = rename(fname, buff) ;
              if(ret == -1)
              printf("Unable to rename");
             else
               cnt++;
     }    
   }       
     
    closedir(dir);
    close(fd);
 return 0;
 }

