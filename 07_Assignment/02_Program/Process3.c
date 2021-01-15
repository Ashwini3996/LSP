#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
   printf("Parent of Process3 is running with PID:%d \n",getppid());
   sleep(4);   
   printf("Process3 is running with PID:%d \n",getpid());
   printf("Child Process3 gets terminated with PID: %d\n",getpid());
        
   return 0;
}
