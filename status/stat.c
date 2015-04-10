#include "status.h"

/*
  -can't access file on OS X(results in "bad address" error)=>comptability issue?  
  -check if this works on symbolic link's
  -increase granulaity by using nano-seconds ?
  -check for windows compatibility
  -what happens if inputs exceed 3 file names?
  -what happens if file doesn't exist?

*/

#define NUM_OF_FILES 3  //number of files to compare
#define VERBOSE 1       //flag for debugging 
int main(int argc, char *argv[]) {

        struct stat file1;
        struct stat file2;
        struct stat file3;
        
        //has to be unsigned long long to provide for smaller 
        //differences and larger range
        unsigned long long atime_file1;
        unsigned long long atime_file2;
        unsigned long long atime_file3;

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
        


        if((stat(argv[1], &file1) || (stat(argv[2], &file2)) || (stat(argv[3], &file3))) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
        }
        
        atime_file1 = ctime(&file1.st_atime);
        atime_file2 = ctime(&file2.st_atime);
        atime_file3 = ctime(&file3.st_atime);

#ifdef VERBOSE
        printf("atime_file1 = %llu\n", &atime_file1); 
        printf("atime_file2 = %llu\n", &atime_file2); 
        printf("atime_file3 = %llu\n", &atime_file3); 
        
        printf("%s file accessed   %s\n", argv[1], ctime(&file1.st_atime));
        printf("%s file accessed   %s\n", argv[2], ctime(&file2.st_atime));
        printf("%s file accessed   %s\n", argv[3], ctime(&file3.st_atime));
        printf("sizeof ctime = %d\n",sizeof(ctime(&file1.st_atime)));
#endif

        //comparision (can be made more complicated by 
        //using more advanced algorithms


        //good exit
        return 0; 
}
