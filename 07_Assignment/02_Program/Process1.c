#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{ 
   int ret = 0, pid =0,status=0;
   
   printf("Parent of Process1 is running with PID:%d \n",getppid());
   printf("Process1 is running with PID:%d \n",getpid());

    if((ret = fork())==0)
    {
          printf("Child process2 is created by parent\n");
  	  execl("./Process2","",NULL);
    }
    else
    {
    
         while((pid = wait(&status))>0);       
             printf("Child Process2 gets terminated\n");
        
     }

      printf("Process1 gets terminates with PID:%d\n", getpid());

  
 return 0;
}
