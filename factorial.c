#include <stdio.h>
#include <stdlib.h>

int factorial (int);

int main(int argc, const char* argv) {
        int n;
        printf("enter a number: ");
        scanf("%d", &n);
        printf("factorial of %d = %d\n", n, factorial(n));
        

        return EXIT_SUCCESS;
        
}
/*recursion from n to n-1 down to 1 therefore O(n) = n
 */ 
int factorial (int num) {
        if (num < 0)
                return -1;
        else if (num == 0 ) 
                return 1;
        else {
                return num * factorial(num - 1);
        }

}
