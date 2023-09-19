TULS

Tuls contains 3 functions:

    isDirectory():
        Takes in string param, and checks it using stat() to see if is a directory. Returns 1 on SUCCESS and 0 on FAILURE.

    listFiles():
        A void function that uses scandir() to iterate throughout the current working directory, which it then prints to standard output.
    recursivelyPrint():
        Takes in a directory/path to directory and an int called tabCount. It opens up the directory entered and uses readdir() and opendir() to open and iterate throughout the directory (similiar to listFiles()).

        If the entry in the directory is a file:
            We print to the screen
        If the entry is a sub directory:
            We call the function recursively to print out its elements. Also make the tabCount 1, which prints out a tab for each entry, when the function is called recursively, for format.

Issues faced:
    Handling "." and ".." when recursing. This took awhile to figure out. Each directory contains "." and  ".." so when the recursive function is called it recurses through these directoories infinitely until a trace trap. So I created 2 condtionals to go along with the recursing condtion. This makes the function see "." and ".." as files and only prints them out once.

    Random undefined error when tuls has 0 args, however it still works so im confused :'

----------------------------------------------------------------------------------------------------------------------------------------------------

TUCP

Tucp contains 2 functions:

    isDirectory():
        Takes in string param, and checks it using stat() to see if is a directory. Returns 1 on SUCCESS and 0 on FAILURE. (taken from tuls)

    copyFiles()
        Takes in a source file and a destination file. This function uses open(), read(), and write() to open up each file's file descriptors and 
        writes the contents of the to its destination.

        On the occurence that the destination file doesn't exist a copy is created witht he same name as the sourcefile.

        On the occurence that the destination file is a directory then we copy that file into thaat directory by constructing a path in main.
Issues face:
    Forgot that i should make a path to send to the function or ill have an error with isDirectory()
    When using write() keeping the byte sizes small is VERY important, even just increasing it to 10 made it copy a bunch of garbage characters to      the destination. Seems write() doesn't terminate the momemnt it hits an EOF character it goes beyond it with its size in bytes param and fills      it with nonsense since there is nothing there.
