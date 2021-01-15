////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//4. Write a program which creates two thread, and by using appropriate synchronization technique avoid the scheduling problem.
//Date : 15-10-2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int counter=0;
pthread_mutex_t lock;

//function to be considerd as thread
 void *ThreadProc(void *p)
 {
       pthread_mutex_lock(&lock); //lock lavlyamule serialy exicution hotay thread ch mhanjech at a time one thread only
	
	//cretical section part stats from hear
	
	unsigned long i=0;
	counter ++;  
        printf("Task %d started succesfully\n", counter);
        for(i=0;i<0xffffffff;i++);                         //Execution bloking loop     
       
        printf("Task %d finished succesfully\n", counter);
       
       //cretical section parts ends hear
       
       pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t thread1, thread2;
 int ret =0;

  if(pthread_mutex_init(&lock,NULL) !=0)
  {
       printf("Error: Unable to create mutex\n");
  }
 
 printf("Inside Main thread\n");

  	ret = pthread_create(  &thread1,
 	                           NULL,
 	                     ThreadProc,
 	                           NULL
 	                    );

	
	if(ret !=0)
 	{
   	 printf("Error: Unable to create thread1\n");
 	}
	
	ret = pthread_create(  &thread2,
 	                           NULL,
 	                     ThreadProc,
 	                           NULL
 	                    );
	
	if(ret !=0)
 	{
   	 printf("Error: Unable to create thread2\n");
 	}
  
   pthread_join(thread1,NULL);
   pthread_join(thread2,NULL);
  
   printf("Terminating Main thread\n");

  pthread_exit(NULL);
  pthread_mutex_destroy(&lock);
 return 0;
 }

