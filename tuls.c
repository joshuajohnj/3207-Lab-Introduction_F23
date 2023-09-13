#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>

enum result {
    SUCCESS,
    FAILURE
} result;

void listFiles()
{
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0)
        perror("tuls: cannot open directory");
        printf("tuls error: %s", strerror(errno));
    for(int i= 0; i<n; i++)
    {
        printf("%s\n", namelist[i]->d_name);
        free(namelist[i]);
    }
    
}
int isDirectory(char * directoryName)
{
    struct stat check;

    if(stat(directoryName,&check)!= 0)
    {
        return FAILURE;
    }
    else{   
        return SUCCESS;
    }
    
    
}

// function to print Directory recursively
int recursivelyPrint(char* directoryName, int tabCount)
{
    
    // open directory with param
    DIR *dir = opendir(directoryName);
    if(dir == NULL)
    {
        printf("opendir error: %s, with %s \n", strerror(errno), directoryName);
        exit(EXIT_FAILURE);
    }
    // init dirent struct
    struct dirent *entry;
    // create a previous directory path, to be used later
    DIR * prevdir;
 
    // iterate through out each entry in the directory
    
    while((entry = readdir(dir)) != NULL)
    {
        // if were in the recurisive function print a tab for each file
        if(tabCount == 1)
        {
            printf("   ");
        }
        // else if were in the intial directory print without tab
        puts(entry->d_name);

        if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
        {
        /*
            we've found a directory!
            now construct the path and call the function recursively
        */
            char path[1024] = {0};
            strcat(path,directoryName);
            strcat(path,"/");
            strcat(path,entry->d_name);
            recursivelyPrint(path,1);
        }
        // go back to the intial directory and read it 
        prevdir = opendir("..");
        entry = readdir(prevdir);
    }

    closedir(dir);
    closedir(prevdir);
    return SUCCESS;
}
//main

int main(int argc, char*argv[])
{
    //printf("%d\n", isDirectory(argv[1]));
    // if there is more than one params exit code
    if(argc > 2)
    {
        printf("tuls: too many arguments\nError: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // if there is no params
    if(argc == 1) {listFiles(); exit(EXIT_SUCCESS);}

    // if there is 2 commands
    else {recursivelyPrint(argv[1],0); exit(EXIT_SUCCESS);}
}
