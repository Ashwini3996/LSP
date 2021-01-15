/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. Write a program which creates two processess. Process 1 count number of capital characters from demo.txt file.
// And process 2 count number of capital characters from hello.txt file. Both the processess writes its count in count.txt file.
//Date : 15-10-2020
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
 

 int main(int argc, char * argv[])
 {
 
   int retP1 =0, retP2=0, pid=0, status=0;
  
    if((retP1 =fork())==0)
    {
       printf("Child process1 gets created!\n");
       execl("./Process1", "",NULL);    
    }
    else//parent
    {
       if((retP2 =fork())==0)
       {
          printf("Child process2 gets created!\n");
           execl("./Process2", "",NULL);    
       }

       pid  = wait(&status); 
       printf("Parent Terminats!\n");
    } 
 
 return 0;
 }

