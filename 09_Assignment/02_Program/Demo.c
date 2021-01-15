/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. Write a program which creates two thread,first thread print numbers from 1 to 500 & other thread print the numbers 
//	from 500 to 1.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 void *fun(void *p)
 {
  
    printf("Inside thrad with Fun\n");
     for(int i=1; i<=500; i++)
     {
         printf("Fun:%d\n", i);
     }
  
    pthread_exit(0);
 } 
 
 void *gun(void *p)
 {
  
    printf("Inside thrad with Gun\n");
     for(int i=500; i>=1; i--)
     {
         printf("Gun:%d\n", i);
     }
  
    pthread_exit(0);
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t threadFun;
 pthread_t threadGun;
 
 int retFun =0, retGun =0;
 
 printf("Inside Main thread\n");
 
 retFun = pthread_create(&threadFun,NULL,fun,NULL);
 
 if(retFun !=0)
 {
    printf("Error: Unable to create threadFun\n");
 }
 
 retGun = pthread_create(&threadGun,NULL,gun,NULL);
 
 if(retGun !=0)
 {
    printf("Error: Unable to create threadGun\n");
 }
       
  
  pthread_join(threadFun,NULL);
  pthread_join(threadGun,NULL);  
  printf("Terminating Main thread\n");
 return 0;
 }

