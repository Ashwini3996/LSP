///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which is used to add two numbers.
//Developed By    : Ashwini Sharad Palve
//Input           : Two integers from command line
//Output          : Sum of two integers
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////



#include<stdio.h>

int main(int argc, char *argv[])
{
    int iSum=0;
    printf("command Line argument argv[0] is:%s\n",argv[0]);
    printf("command Line argument argv[1] is:%s\n",argv[1]);
    printf("command Line argument argv[2] is:%s\n",argv[2]);
    printf("command Line argument argv[3] is:%s\n",argv[3]);
    
    iSum = atoi(argv[2])+atoi(argv[3]);
    printf("Sum of command Line argument is:%d",iSum);
    return 0;
}