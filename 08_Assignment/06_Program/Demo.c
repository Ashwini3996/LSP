//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//6. Write a program which is used to display Environment of our running process.
//Date : 15-10-2020
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

 extern char ** environ;

int main(int argc, char * argv[])
{

	char ** env = environ;
	printf("Envirment veriables are:\n");


	while( *env !=NULL)
	{
   		printf("----------------------------------------\n")  ; 
   		printf("%s\n",*env);
   		   env++ ;    		
	}       
  return 0; 
 }
