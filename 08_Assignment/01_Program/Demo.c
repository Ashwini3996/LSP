/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. Write a program which creates new process which is responsible to write all file names which are present on desktop
//   in demo.txt file which should be created newly.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
 

 int main(int argc, char * argv[])
 {
 
  int ret =0, pid=0, status=0;
  
     if(argc !=2)
     {
        printf("Error : Invalid Argument!\n");
        return -1;
     }
 
    if((ret=fork())==0)
    {
       printf("Child process gets created!\n");
       execl("./Process", argv[1],NULL);    
    }
    else//parent
    {
       printf("Parent Wiat ...!\n");
       pid  = wait(&status);
       
       printf("Parent Terminats!\n");
    } 
 
 return 0;
 }

