/*
 * returnArray : return local array from a function
 */

#include<stdio.h>
#include <stdlib.h>

/*Dynamically allocated memory (allocated using new or malloc())
 *remains their until we delete it using delete or free().
 So we can create a dynamically allocated array and 
 we can delete it once we come out of function
 */ 
int *dynamicArray() {
	int *array = malloc(sizeof(int[100]));
	array[0] = 1;
        array[1] = 2;
        return array;
}

/*Lifetime of a static variable is throughout the program.
 *So we can always create a local static array and return it.
 */
int *staticArray() {
        static int array[100];
        array[0] = 55;
        array[1] = 66;
        return array;
}

/*We can wrap array in a structure/class and return an 
 *instance of the struct/class. The reason for this work is,
 *array members of structures are deeply copied. In below 
 *program deep copy happens when returned 
 *instance is copied in main.
 */
struct arrayWrap {
        int array[100];
};

struct arrayWrap structArray() {
        struct arrayWrap x;
        x.array[0] = 9;
        x.array[1] = 99;
        return x;
}

int main(int argc, char* argv) {
        printf("dynamicArray\n");
        int *ptr1 = dynamicArray();
        printf("[0] = %d\n[1] = %d\n", ptr1[0], ptr1[1]);
        free(ptr1);
        
        printf("staticArray\n");
        int *ptr2 = staticArray();
        printf("[0] = %d\n[1] = %d\n", ptr2[0], ptr2[1]);
        
        printf("structArray\n");
        struct arrayWrap x = structArray();
        printf("[0] = %d\n[1] = %d\n", x.array[0], x.array[1]);


	return EXIT_SUCCESS;	
}




