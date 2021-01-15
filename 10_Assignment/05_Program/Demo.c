//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5. Write a program which creates two threads by using pthread API, where one thread count number of capital characters from demo.txt 
//file and other threads count number of small characters from same file.
//Date : 15-10-2020
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>

 void *fun(void *p)
 {
    int fd =0, ret =0, count = 0;
    char buffer[120]={'\0'}; 
    printf("Inside thrad with Fun\n");
    
   fd = open("Demo.txt",O_RDONLY);
   if(fd ==-1)
   {
      printf("Error : Unable to open Demo.txt file!");
      return;
   }
   
   
    while((ret = read(fd, buffer, sizeof(buffer))) !=0)
    {
        for(int i=0; i<ret;i++)
        {
           if((buffer[i]>='A') && (buffer[i] <='Z'))  
            count++;             
        }
     }
      
    pthread_exit(count);
 } 
 
 void *gun(void *p)
 {
  
    printf("Inside thrad with Gun\n");
    
    int fd =0, ret =0, count = 0;
    char buffer[120]={'\0'}; 
    
   fd = open("Demo.txt",O_RDONLY);
   if(fd ==-1)
   {
      printf("Error : Unable to open Demo.txt file!");
      return;
   }
   
   
    while((ret = read(fd, buffer, sizeof(buffer))) !=0)
    {
        for(int i=0; i<ret;i++)
        {
           if((buffer[i]>='a') && (buffer[i] <='z'))  
            count++;             
        }
     }
      
    pthread_exit(count);     
 } 
 
 int main(int argc, char * argv[])
 {
 
 pthread_t threadFun;
 pthread_t threadGun;
 
 int retFun =0, retGun =0, countCap =0 , countSmall =0;
 
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
        
  pthread_join(threadFun,&countCap);
  pthread_join(threadGun,&countSmall);
  
  printf("Capital Count:%d\n",countCap);
  printf("Small Count:%d\n",countSmall);


  printf("Terminating Main thread\n");
 return 0;
 }

