#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{ 
   int ret = 0, pid =0,status=0;
   
   printf("Parent of Process2 is running with PID:%d \n",getppid());
   printf("Process2 is running with PID:%d \n",getpid());

    if((ret = fork())==0)
    {
          printf("Child process3 is created by parent \n");
  	  execl("./Process3","",NULL);
    }
    else
    {
    
         while((pid = wait(&status))>0);       
     }
       printf("Process2 gets terminates with PID:%d\n", getpid());

  
 return 0;
}
