/*
* arrayLength has to be within main; if a function is used we will have only the pointer/array head as reference
* O(n) = O(N)
*/
#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10
void reverse(int *, int);


int main(int argc, const char *argv) {
        int myArray[] = { 0, 1, 2, 3, 4};
        int arrayLength = sizeof(myArray) / sizeof(int);
        int i;
        
        printf("original array = ");
        for(i = 0; i < arrayLength; i++) {
                printf("%d, ", myArray[i]);
        }
        printf("\n");
        
//        printf("length = %d\n", arrayLength);

        reverse(myArray, arrayLength);
        printf("reversed array = ");
        for(i = 0; i < arrayLength; i++) {
                printf("%d, ", myArray[i]);
        }
        printf("\n");

        return EXIT_SUCCESS;
}


void reverse(int array[SIZE], int length) {
        for(int i = 0; i < length / 2; i++) {
        int other =  length - i - 1;
        int temp = array[i];
        array[i] = array[other];
        array[other] = temp;
       }
}

