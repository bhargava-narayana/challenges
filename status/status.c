/*
 * AUTHOR BHARGAVA NARAYANA
 * 
 * Comiple: gcc status.c -o status
 * Execute: ./status <filename> <filename> <filename>
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

/*
  -Compatible on linux; fails on Windows/BSD
  -fails for symbolic links
  -fails if file doesn't exist
`
*/

}
int main(int argc, char *argv[]) {

        int count;
        struct stat file_1;
        struct stat file_2;
        struct stat file_3;
        
        //has to be unsigned long long to provide for granuality
        //and range
         unsigned long long atime_file_1;
         unsigned long long atime_file_2;
         unsigned long long atime_file_3;

        //check for input's
        if(argc < 4){
                fprintf(stderr, "Usage: %s <file1> <file2> <file3>\n", argv[0]);
                exit(EXIT_FAILURE);
        } else if (argc > 4){
                fprintf(stderr, "Usage: %s <file1> <file2> <file3>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        //check for file existance;
        //BUG: Is not case senstive
        if(access(argv[1],F_OK) || access(argv[2],F_OK) || access(argv[3],F_OK) == -1) {
                fprintf(stderr,"File not found");
                exit(EXIT_FAILURE);
        }
        if((stat(argv[1], &file_1)) || (stat(argv[2], &file_2)) ||  (stat(argv[3], &file_3)) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
        }
        
        //has to be volatile to ensure we read the latest value
        atime_file1 = volatile ctime(&file_1.st_atime);
        atime_file2 = volatile ctime(&file_2.st_atime);
        atime_file3 = volatile ctime(&file_3.st_atime);

        //comparision can be made more complicated by 
        //using more advanced algorithms
        if ((atime_file_1 > atime_file_2) && (atime_file_1 > atime_file_3)) {
                printf("%s\n", argv[1]);
        } else if (atime_file_2 > atime_file_3){
                printf("%s\n", argv[2]);
        } else {
                printf("%s\n", argv[3]);
        }

        //good exit
        return 0; 
}
