#include <stdio.h>
#include <stdlib.h>

#define BUFFER 10

int smallest(int list[])
{
        int smallest;
        int index;

        smallest = list[0];
        
        index = 0;
        
        for(index = 0; index <= (sizeof(list) / sizeof(int)); index++)
        {
                if(list[index] < smallest)
                {
                        smallest = list[index];
                }
        }

        return smallest;
}

int main(int argc, char *argv[])
{
        int size;
        int list[BUFFER];
        int count;
        fprintf(stdout, "enter list size: ");
        scanf("%d", &size);

        if(size <2)
        {
                fprintf(stdout, "size is too small\n");
                return EXIT_FAILURE;                
        }

        printf ("enter list of numbers:\n");
        for(count = 0; count < size; count++)
        {
                scanf("%d", &list[count]);
        }

        fprintf(stdout, "list: ");
        for(count = 0; count < size; count++)
        {
                fprintf(stdout, "%d ", list[count]);
        }
        fprintf(stdout, "\nsmallest number in the list is: %d\n", smallest(list));

        return EXIT_SUCCESS;
              
}
