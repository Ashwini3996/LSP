/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3. Write a program which creates three diffrent processess internally as process2, process3, process4.
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
          printf("Child process2 is created by parent \n");
  	  execl("./Process2","",NULL);
  }
  else
  {
     if((ret = fork())==0)
     {
          printf("Child process3 is created by parent \n");
  	  execl("./Process3","",NULL);
     }

     if((ret = fork())==0)
     {
          printf("Child process4 is created by parent \n");
  	  execl("./Process4","",NULL);
     }

      while((pid = wait(&status))>0)
      {       
             printf("%d child gets terminated\n",pid);  
      }      
    
  }
  printf("Parent process terminates!\n");

return(0);
}



