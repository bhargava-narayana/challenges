/*
 * write a program that takes in three arguments, 
 * 1.a start temperature (in Celsius), 
 * 2.an end temperature (in Celsius) and 
 * 3.a step size. 
 * Print out a table that goes from the start temperature to the end temperature, 
 * in steps of the step size; you do not actually need to print the final end temperature 
 * if the step size does not exactly match. 
 *
 * You should perform input validation: 
 * 1. do not accept start temperatures less than a lower limit (which your code should 
 * specify as a constant) or
 * 2. higher than an upper limit (which your code should also specify). 
 * 3. You should not allow a step size greater than the difference in temperatures. 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        const int lower;
        int upper;
        int step;

        fprintf(stdout, "please give in a lower limit, limit >=0:");
        scanf("%d", &lower);
        if((lower < 0) || (lower > 50000))
        {
                printf("invlaid input. try again\n");
                scanf("%d", &lower);
        }
        
        fprintf(stdout, "please give in higher limit, %d > limit <= 50000:", lower);
        scanf("%d", &upper);
        if((upper < lower) || (upper > 50000))
        {
                printf("invlaid input. try again\n");
                scanf("%d", &upper);
        }
        
        fprintf(stdout, "please give in a step, 0 < step <= 10:");
        scanf("%d", &step);
        if((step < 0) || (step > 10))
        {
                printf("invlaid input. try again\n");
                scanf("%d", &step);
        }



}
