/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. Write a program which is used to create simple thread by using pthread library.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *fun(void *p)
 {
    printf("Inside thrad with Fun\n");
    pthread_exit(0);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t thread;
 
 int ret =0;
 
 printf("Inside Main thread\n");
 
 ret = pthread_create(&thread,NULL,fun,NULL);
 
 if(ret !=0)
 {
    printf("Error: Unable to create thread\n");
 }
  
  pthread_join(thread,NULL);
  printf("Terminating Main thread\n");
 return 0;
 }

