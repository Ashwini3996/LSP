//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//4.Write a program which is used to print priority of current process.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
  
  int main(int argc, char * argv[])
 {

    int prior = 0;
    prior= getpriority(PRIO_PROCESS, getpid()); 

    printf("Current priority of Process:%d", prior);   
   
    
  return 0; 
 }
