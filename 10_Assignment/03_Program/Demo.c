/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3. Write a program which is used to predict the problem due to lack of synchronization.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int counter=0;
 void *ThreadProc(void *p)
 {
	unsigned long i=0;
	counter ++;  
       
        printf("Task %d started succesfully\n", counter);
        for(i=0;i<0xffffffff;i++);                         //Execution bloking loop     
        printf("Task %d finished succesfully\n", counter);
        pthread_exit(NULL);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t thread1, thread2;
 int ret =0;
 int no=11;
 
 printf("Inside Main thread\n");

  	ret = pthread_create(  &thread1,
 	                           NULL,
 	                     ThreadProc,
 	                           NULL
 	                    );
	
	ret = pthread_create(  &thread2,
 	                           NULL,
 	                     ThreadProc,
 	                           NULL
 	                    );
	
	if(ret !=0)
 	{
   	 printf("Error: Unable to create threadFun\n");
 	}
  
     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
  
   printf("Terminating Main thread\n");
  pthread_exit(NULL);
 return 0;
 }

