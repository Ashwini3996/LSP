/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. Write a program which create three level process hierarchy where process 1 creates
//	process 2 and it internally creates process 3.
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
          printf("Child process1 is created by parent \n");
  	  execl("./Process1","",NULL);
  }
  else
  {
    
         while((pid = wait(&status))>0);       
             printf("Child Process1 gets terminated\n");
        
    
  }
  printf("Main Process gets terminates with PID:%d\n", getpid());

return(0);
}






