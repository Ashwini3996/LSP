///////////////////////////////////////////////////////////////////////
//Problem Statment: Write a program which accept file name from user and open that file.
//Developed By    : Ashwini Sharad Palve
//Input           : File name
//Output          : Open file
//Date            : 10-09-2020
//////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    
    int fd =0;
    
    fd = open( argv[2], O_RDONLY);
    
    if(fd==-1)
    {
       printf("Error:Unable to open file!");
    }
    else
    {
        printf("File Open Successfully with FD: %d\n", fd);
    }
    
    close(fd);
    return 0;
}