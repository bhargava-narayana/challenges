#include <stdio.h>
void move_disks(int, char, char, char);

void move_disks(int count, char peg_A, char peg_B, char peg_C) {
        if(count == 1) {
                printf("\nmove disk 1 from %c to %c", peg_A, peg_C);
                return;
        }
        move_disks(count-1, peg_A, peg_B, peg_C);
        printf("\nmove disk %d from %c to %c", count, peg_A, peg_B); 
        move_disks(count-1, peg_C, peg_B, peg_A);

}
int main(int argc, char *argv[]) {
        int num_of_disks = 0;
        printf("enter number of disk's: ");
        scanf("%d", &num_of_disks);
        move_disks(4, 'A', 'B', 'C');
        printf("\n\n");
        return 0;
}
