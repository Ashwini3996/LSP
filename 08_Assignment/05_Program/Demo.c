//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5.Write a program which is used to increase the priority by 5.
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
    printf("Default priority of Process:%d\n", prior);   
   
    prior = nice(-5);
    
    prior= getpriority(PRIO_PROCESS, getpid()); 
    printf("Change priority of Process:%d\n", prior);  

  return 0; 
 }
