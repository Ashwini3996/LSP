///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept name from command line 
//                  argument and display it on screen.
//Developed By    : Ashwini Sharad Palve
//Input           : strings from command line
//Output          : strings
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////

#include<stdio.h>

int main(int argc, char *argv[])
{
    int iCnt=0;
    //printf("command Line argument argv[0] is:%s\n",argv[0]);
    //printf("command Line argument argv[1] is:%s\n",argv[1]);
    
    printf("Name from command line is :\n");
    for(iCnt = 2; iCnt < argc; iCnt++)
    {
        printf("%s ",argv[iCnt]);
    }
    return 0;
}