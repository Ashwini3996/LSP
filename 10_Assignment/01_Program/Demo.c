/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. Write a program which creates 4 number of threads and our main thread waits till all the thread terminates.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *ThreadProc(void *p)
 {
    printf("Inside thrad with id %ld and data %d\n", pthread_self(),(int)p);     
    pthread_exit(NULL);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t thread[4];
 int ret =0;
 int i=0;
 
 printf("Inside Main thread\n");

  for(i=0;i<4;i++)
  { 
 	ret = pthread_create(&thread[i],
 	                           NULL,
 	                     ThreadProc,
 	                       (void*)i
 	                    );
	if(ret !=0)
 	{
   	 printf("Error: Unable to create threadFun\n");
 	}
    }
   
  
  
  for(i=0;i<4;i++)
  {  	 
     pthread_join(thread[i],NULL);
  }     

   printf("Terminating Main thread\n");
  pthread_exit(NULL);
 return 0;
 }

