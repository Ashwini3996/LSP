/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.Write a program which craetes one child process, and parent process waits till its child process terminates.
//Date :11-10-2020 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char * argv[])
{

int pid =0, status=0;
int ret = 0;

  if((ret = fork())==0)
  {
          printf("Child process is created by parent \n");
  	  execl("./Process","",NULL);
  }
  else
  {
    printf("Parent PID of child process:%d \n",getppid());
    
       while((pid = wait(&status))>0);       
             printf("%d child gets terminated\n",pid);
        
    
  }
  printf("Parent process terminates!\n");

return(0);
}



