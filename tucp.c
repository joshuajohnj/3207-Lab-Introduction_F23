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
/// @brief Copies source files' contents to another file or makes a copy of it
/// @param sourceFile 
/// @param destFile 
/// @return returns a 1 on success 0 on failure
int copyFiles(char * sourceFile, char * destFile){

    // initalize both file descriptors
    int source_fd, r, dest_fd;
    source_fd = open(sourceFile, O_RDONLY, S_IRUSR);
    dest_fd = open(destFile, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR, S_IWUSR);

    // init buffer
    char buffer[100];

    // read throughout source file 
    while((r = read(source_fd,&buffer,1)))
    {
        // error handling
        if( r < 0)
        {
            printf("error when reading the source file: %s\n", strerror(errno));
            return 0;
        }
        // write it to the destination
        write(dest_fd,&buffer,1);
    }

    // close file descriptors
    close(source_fd);
    close(r);
    close(dest_fd);
    return 1;
}


/// @brief isDirectory() from tuls takes in a directory and checks if it is one
/// @param directoryName 
/// @return returns 1 if it is a directory, 0 if not

int isDirectory(const char *directoryName)
{
   struct stat statbuf;
   if (stat(directoryName, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

int main(int argc, char *argv[])
{
    // if the command is called with no args return error
    if(argc <= 1)
    {
        printf("Not enough args: %s\n",strerror(errno));
    }
    // if the last element is a directory call copyFiles() for each sourcefile
    if(isDirectory(argv[argc-1]) != 0)
    {
        for(int i =1; i <argc-1; i++)
        {
            char * path = malloc(sizeof(char *));
            strcpy(path,argv[argc-1]);
            strcat(path,"/");
            strcat(path, argv[i]);
            copyFiles(argv[i], path);
            free(path);
        }
    }
    else
    {
        if(argc > 3)
        {
            printf("tucp: too many args %s", strerror(errno));
        }
        copyFiles(argv[1],argv[2]);
    }
    return 0;
}