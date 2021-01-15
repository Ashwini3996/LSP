//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//4. Write a program which creates single thread and it accept one value from user and it return some value to the caller thread.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *fun(void *p)
 {
    
    printf("Inside thrad with Fun\n");
    printf("Fun parameter value:%ld\n", (int)p);
  
    pthread_exit((int)p+10);
 } 
 
  
 int main(int argc, char * argv[])
 {
 
 pthread_t threadFun;
  
   int retFun =0,no=10,res=0;
 
 printf("Inside Main thread\n");
 
 retFun = pthread_create(&threadFun,
                               NULL,
                                fun,
                              (void*)no);
 
 if(retFun !=0)
 {
    printf("Error: Unable to create threadFun\n");
 }
  
  pthread_join(threadFun,&res);
  printf("Return value from thread fun is:%d\n",res);
  printf("Terminating Main thread\n");
 return 0;
 }

