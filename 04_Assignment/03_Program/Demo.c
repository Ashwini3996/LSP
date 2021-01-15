///////////////////////////////////////////////////////////////////////////////
//3. Write a program which accept two file names from user and check whether 
//	contents of that two files are equal are not.
//date: 17-9-2020
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int ChkContaints(char* FirstFile, char* SecondFile)
{

  char bufferOne[128]={'\0'};
  char bufferTwo[128]={'\0'};  
    
  int fdFirst = 0, fdSecond=0;
  int iRetOne= 0, iRetTwo = 0, iret=0;
    
  fdFirst = open(FirstFile, O_RDONLY);
  if(fdFirst == -1)
  {
    printf("Error: Unable to open!");
    return -1;   
  }  
  
  fdSecond = open(SecondFile, O_RDONLY);
  if(fdSecond == -1)
  {
    printf("Error: Unable to open!");
    return -1;   
  }  
   
  while((iRetOne= read(fdFirst, bufferOne, sizeof(bufferOne)))!=0);
  if(iRetOne == -1)    
  {
      printf("Error: Unble to read!"); 
      close(fdFirst);
      return -1;    
  }  

  
  while((iRetTwo= read(fdSecond, bufferTwo, sizeof(bufferTwo)))!=0);
  if(iRetTwo == -1)    
  {
      printf("Error: Unble to read!"); 
      close(fdSecond);
      return -1;    
  }  

   iret = strcmp(bufferOne, bufferTwo);

return iret;
}

int main(int argc, char*argv[])
{
  int iret=0;
         
  if(argc != 3)
  {
     printf("Error: Not sufficient argumnet!\n");
     return -1;
  }

  iret = ChkContaints(argv[1], argv[2]);
  if(iret == 0)
     printf("Contains are same!");
  else
    printf("Containts are not same!") ;  
  
   return 0; 
}

