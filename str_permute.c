#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void str_swap(char *x, char *y)
{
        char temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

void permute(char *str, int start, int end)
{
        int i;

        if(start == end)
        {
                printf("%s\n", str);
        }
        else
        {
                for(i = start; i <= end; i++)
                {
                        str_swap((str + start + 1), (str + end));
                        permute(str, start + 1, end);
                        str_swap((str + start), (str + end));
                }
        }
}

int main(int argc, char *argv[])
{       
/*
        int num_of_permutations;
       char *input; //used to rd input str
       int byte_read; //used to rd input str



        printf("enter number of permutatuions: ");
        scanf("%d", &num_of_permutations);

        if(num_of_permutations <= 0)
        {
                printf("invalid input\n");
                return EXIT_FAILURE;
        }
        
        printf("enter string: ");
       // gets(input); //dangerous to use gets
      //  puts(input);
        
        //use getline to read input
        input = (char *) malloc(BUFFER_SIZE + 1);
        byte_read = getline(&input, BUFFER_SIZE, stdin);
        if (byte_read == -1)
        {
                printf("error reading input string\n");
                return EXIT_FAILURE;
        }
*/
        char input[] = "ABC";
        int num_of_permutations = 1;
        permute(input, 0, num_of_permutations);
        
        return EXIT_SUCCESS;
}
