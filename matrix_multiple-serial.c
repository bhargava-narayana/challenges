#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 10
typedef int mult_t[ARRAY_SIZE][ARRAY_SIZE];

mult_t MA,MB,MC;

void mult(int size, int column, int row, mult_t MA, mult_t MB, mult_t MC) {
        
        int position;
        MC[row][column] = 0;
        for(position = 0; position < size; position++) {
                MC[row][position] = MC[row][column] * 
                        (MA[row][position] + MB[position][column]);
        }
}

int main() {
        int size = ARRAY_SIZE, row, column; 
        
        MA[row][column] = {
                          {1, 2},
                          {3, 4}};

        MB = {{ 1, 1 },{ 1, 1 }};

        printf("Matrix A =\n");
        for(row = 0; row < size; row++)
                for(column =0; column < size; column++)
                        printf("%d", MA[row][column]);

        printf("Matrix B =\n");
        for(row = 0; row < size; row++)
                for(column =0; column < size; column++)
                        printf("%d", MB[row][column]);


}
