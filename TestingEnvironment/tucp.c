#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>

#define size 10

int copyFiles(char * sourceFile){

    // initalize a the file descriptors
    int source, r, dest;
    source = open(sourceFile,O_RDONLY);
    dest = open(dest, O_CREAT | O_WRONLY | O_APPEND);

    // init buffer
    char buffer[1024];

    // read throughout source file 
    while((r = read(source,buffer,size)) != NULL)
    {
        // write it to the destination
        write(dest,buffer,size);
    }
}

int main(int argc, char *argv[])
{
    // argc must be greater than to equal to 2
    if(argc > 2) 
    {
        printf("Too many arguements.");
    }
    return 0;
}