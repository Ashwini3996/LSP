#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    sleep(3);       
   printf("Process2 is running with PID:%d \n",getpid());
 
 return 0;
}
