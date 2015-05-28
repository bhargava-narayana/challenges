#include <stdio.h>
#include <stdlib.h>

#define NO_OF_CHARS 256
#define bool int

/*
 * Function removes duplicate characters from the string
 * This function work in-place and fills null characters
 * in the extra space left
 *
 *1. Initialize:
 *     str :              input string 
 *     input_index:       index to  keep track of location of next
 *                        character in input string 
 *     result_index:      index to  keep track of location of
 *                        next character in the resultant string 
 *     bin_hash[0..255]:  Binary hash to see if character is 
 *                        already processed or not 
 *2: Do following for each character *(str + input_index) in input string:
 *      (a) if bin_hash is not set for *(str + input_index) then
 *          if program sees the character *(str + input_index) first time
 *          (i)  Set bin_hash for *(str + input_index)
 *          (ii) Move *(str  + input_index) to the resultant string.
 *                 This is done in-place.
 *          (iii) result_index++
 *      (b) input_index++
 *3: Remove extra characters at the end of the resultant string.
 *
 */ 
char *removeDups(char *str)
{
        bool bin_hash[NO_OF_CHARS] = {0};
        int input_index;
        int result_index;
        char temp;

        input_index = result_index = 0;

        //in-place removal of duplicate characters
        while(*(str+input_index))
        {
                temp = *(str + input_index);
                if(bin_hash[temp] == 0)
                {
                        bin_hash[temp] = 1;
                        *(str + result_index) = *(str + input_index);
                        result_index++;
                }
                input_index++;
        }
        *(str + result_index) = '\0';

        return str;
}

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                fprintf(stdout, "Usage: %s \"input_string\"\n", argv[0]);
                return EXIT_FAILURE;
        }
        fprintf(stdout, "input: %s\n", argv[1]);
        fprintf(stdout, "output: %s\n", removeDups(argv[1]));

        return EXIT_SUCCESS;
}
