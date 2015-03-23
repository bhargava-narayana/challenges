#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

/*
  -can't access file on OS X(results in "bad address" error)=>comptability issue?  
  -check if this works on symbolic link's
  -increase granulaity by using nano-seconds ??
*/

#define NUM_OF_FILES 3  //number of files to compare
#define VERBOSE 1       //flag for debugging 

int main(int argc, char *argv[]) {

        struct stat file1;
        struct stat file2;
        struct stat file3;

        char *atime_file1;
        char *atime_file2;
        char *atime_file3;

        //declare struct based on NUM_OF_FILES flage
        /*
        int i;
        for (i = 0; i == NUM_OF_FILES; i++) {
                struct stat file_

        }
        */
        //check for input's
        if(argc != 4){
                fprintf(stderr, "Usage: %s <file1> <file2> <file3>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        //
        
        atime_file1 = stat(argv[1],&file1);
        printf("atime_file1 = %s\n",&atime_file1);

        if((stat(argv[1],&file1) || stat(argv[2],&file2) || stat(argv[3],&file3)) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
        }
        
#ifdef VERBOSE
        printf("file accessed   %s\n",ctime(&file1.st_atime));
        printf("file accessed   %s\n",ctime(&file2.st_atime));
        printf("file accessed   %s\n",ctime(&file3.st_atime));
#endif

        //good exit
        return 0; 
}
