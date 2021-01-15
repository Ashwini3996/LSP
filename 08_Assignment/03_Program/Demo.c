/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3. Write a program which creates one process which accept one directory name. That process will rename all names of 
//regular files with sequential number. (1.txt, 2.txt,3.txt, 4.txt etc).
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

