#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return;
}


void void_swap(void *a, void *b, int size)
{
        void *temp;

        if((temp = malloc(size)) == NULL)
                        return -1;
        memcpy(temp, a, size);
        memcpy(a, b, size);
       memcpy(b, temp, size);
       free(temp);

        return;
}

int main(int argc, char *argv[])
{
        
        int *x;
        int *y;

        if(argc != 3)
        {
                printf("Usage: %s value_1 value_2\n", argv[0]);
                return -1;
        }

        x = atoi(argv[1]);
        printf("x =%d\n", x);

        y = atoi(argv[2]);
        printf("y =%d\n", y);
        

        swap(&x, &y);
        printf("after swapping: x = %d, y = %d\n", x, y);

        void *i;
        void *j;

        i = (int *)malloc(sizeof(int));
        j = (int *)malloc(sizeof(int));

        i = x;
        j = y;

        printf("\n swapping using void ptr's:\n");
        void_swap(&i, &j, (sizeof(int)));
        printf("after swapping: i = %d, j = %d\n", i, j);



}
