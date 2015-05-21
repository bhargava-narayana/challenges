#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_palindrome(int value)
{
        int reverse;
        int temp;
        int reminder;
        int count = 1;

        temp = value;

        while(temp != 0)
        {
                
                reminder = temp % 10;
                printf("%d reminder = %d ", count, reminder);
                reverse = reverse * 10 + reminder;
                printf("reverse = %d ", reverse);
                temp /= 10;
                printf("temp = %d\n", temp);
                count++;
        }

        if(reverse == value)
                return true;               
        else
                return false;
}

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                fprintf(stdout, "Usage: %s <input_value>\n", argv[0]);
                return EXIT_FAILURE;
        }

        if(is_palindrome(atoi(argv[1])))
        {
                fprintf(stdout, "%s is a palindrome\n", argv[1]);
        }
        else
        {
                fprintf(stdout, "%s is not a palindrome\n", argv[1]);
        }

        return EXIT_SUCCESS;
}
