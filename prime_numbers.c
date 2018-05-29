/*
 * find prime numbers <= n
 *
 * Eratosthenes method:
 * 
 * 1. Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
 *
 * 2. Initially, let p equal 2, the first prime number.
 * 
 * 3. Starting from p, count up in increments of p and mark each of these 
 * numbers greater than p itself in the list. These numbers will be 
 * 2p, 3p, 4p, etc.; note that some of them may have already been marked.
 * 
 * 4. Find the first number greater than p in the list that is not marked.
 * If there was no such number, stop. Otherwise, let p now equal this 
 * number (which is the next prime), and repeat from step 3.
 * 
 *
 * When the algorithm terminates, all the numbers in the list that 
 * are not marked are prime
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//marks all multiples of 'a'; >a and <=n
void markMultiples(bool arr[], int a, int n)
{
        int i, num;

        i = 2;

        while((num = i * a) <= n)
        {
                arr[num-1] = 1; //-1 because index starts at 0
                ++i;

        }

}

/*
 * Most efficient
 * Assume all numbers are prime
 * Take the first prime number and removes all of its multiples;
 * repeat
 */
void sieveOfEratosthenes(int n)
{
        //no prime numbers less then 2
        if(n >= 2)
        {
                //create an array of size n and init all
                //elements to 0
                bool arr[n];
                memset(arr, 0, sizeof(arr));

                /*
                 * following property is maintained in the loop below
                 * 1. arr[i] == 0 => i+1 is prime
                 * 2. arr[i] == 1 => 1+1 is NOT a prime
                 */ 
                int i;
                for(i = 1; i < n; ++i)
                {
                        if(arr[i] == 0)
                        {
                                fprintf(stdout, "%d, ", i+1);
                                markMultiples(arr, i+1, n);
                        }
                }
        }

        return;
}

/*
 * ineffiecent because we need to call the method square root 
 * of the number times
 */
bool isPrime(int n) 
{
        if (n<=1) return false;
        if (n==2) return true;
        if (n%2==0) return false;
        double m=sqrt(n);
        for (int i=3; i<=m; i+=2)
                if (n%i==0)
                        return false;
        return true;        
}
int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                fprintf(stdout, "Usage: %s <value_of_n>\n", argv[0]);
                return EXIT_FAILURE;
        }

        int n = atoi(argv[1]);

        fprintf(stdout, "prime numbers less then %d is : ", n);
        sieveOfEratosthenes(n);
        fprintf(stdout, "\n");
        int x=isPrime(n);
        fprintf(stdout, "isPrime: %s\n", x ? "true":"false"); 

        return EXIT_SUCCESS;
}
