/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3. Write a program which creates single thread and we have to pass parameter to that thread from main thread.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *fun(void *p)
 {
  
    printf("Inside thrad with Fun\n");
    printf("Fun parameter value:%ld\n", (int)p);
  
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
                              (void*)no);
 
 if(retFun !=0)
 {
    printf("Error: Unable to create threadFun\n");
 }
  
  pthread_join(threadFun,NULL);
  printf("Terminating Main thread\n");
 return 0;
 }

