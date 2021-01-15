/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. Write a program which creates multiple threads and sets its thread attributes accordingly.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// function to be considerd as thread
 void *ThreadProc(void *p)
 {
    long tid;
    tid=(long)p;
    sleep(1);
    
    printf("Sleeping in thread\n");
    printf("Thread with id %ld\n", tid);     
    pthread_exit(NULL);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t thread[4];
 int ret =0;
 int i=0, status=0;
 pthread_attr_t attr; 
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

 printf("Inside Main thread\n");

  //Initialized thread attribute
  pthread_attr_init(&attr);
        

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
   
    //We can free the attributes as
    pthread_attr_destroy(&attr);
  
  for(i=0;i<4;i++)
  {  	 
     pthread_join(      thread[i],//thread id 
                   (void**)&status//Location of thread
                 );
   printf("Mian:Completted thread id  %d existing status %d\n", i, status);

  }     

   printf("Terminating Main thread\n");
  pthread_exit(NULL);//turminating running thread
 return 0;
 }

