#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

//number of files to compare
#define NUM_OF_FILES 3

/*
  -can't access file on OS X(results in "bad address" error  
  -check if this works on symbolic link's

*/
int main(int argc, char *argv[]) {
        struct stat file1;
        
        //check for input's
        if(argc != 4){
                fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        //
        if(stat(argv[1],&file1) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
        }

        printf("file accessed   %s",ctime(&file1.st_atime));

        //good exit
        return 0; 
}
