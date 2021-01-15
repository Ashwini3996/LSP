/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5. Write a program which is used to get thread id inside its thread function.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *fun(void *p)
 {
  
    printf("Inside thrad with Fun\n");
    printf("Fun Thread ID:%d\n", pthread_self());
  
    pthread_exit(0);
 } 
 
  
 int main(int argc, char * argv[])
 {
 
 pthread_t threadFun;
  
  int retFun =0,no=10;
 
 printf("Inside Main thread\n");
 
 retFun = pthread_create(&threadFun,
                               NULL,
                                fun,
                              NULL);
//  printf("Fun Thread ID from main:%d\n", threadFun);//wrong
   
 if(retFun !=0)
 {
    printf("Error: Unable to create threadFun\n");
 }
  
  pthread_join(threadFun,NULL);
  printf("Terminating Main thread\n");
 return 0;
 }

