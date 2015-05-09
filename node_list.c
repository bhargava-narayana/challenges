#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT {
        int info;
        struct NodeT *next;
} Node;


int insert_node(Node *pointer, int val) {
        
        int node_count = 0;
        while(pointer->next != NULL) {
                pointer = pointer->next;
        }
        pointer->next = (Node *)malloc(sizeof(Node));
        pointer = pointer->next;
        pointer->info = val;
        pointer->next = NULL;
       
        return ++node_count;
        
}

int find(Node *pointer, int key) {
        pointer = pointer->next;
        while(pointer != NULL) {
                if(pointer->info == key) {
                        return 1;
                }
                pointer = pointer->next;
        }

        return 0;
        
}

int remove_node(Node *pointer, int val) {
        while((pointer->next != NULL) && (pointer->next->info != val))
                pointer = pointer->next;
        if(pointer->next == NULL) {
                printf("value not found\n");
                return;
        }
        Node *temp;
        temp = pointer->next;
        pointer->next = temp->next;
        free(temp);

        return 0;
}

void print_list(Node *head) {
        if(head == NULL) {
                return;
        }
        printf("%d->",head->info);
        print_list(head->next);
}

int main(int argc, char *argv[]) {
        
        Node *head;
        Node *node;
        if((head = (Node *)malloc(sizeof(Node))) == NULL)
                return -1;

        int node_count = 0;

        node_count += insert_node(head, 5);
        node_count += insert_node(head, 6);
        node_count += insert_node(head, 4);
        print_list(head);
        printf("\n");
        printf("node count: %d\n", node_count);

        int result;
        result =  find(head, 6);
        if (result != 1)
                printf("key not found\n");
        else
                printf("key exists\n");
        result =  find(head, 7);
        if (result != 1)
                printf("key not found\n");
        else
                printf("key exists\n");
        if (remove_node(head, 5) == 0) 
                --node_count;
        if(remove_node(head, 7) == 0)
                --node_count;
         
        print_list(head);
        printf("\n");
        printf("node count: %d\n",node_count);


        return EXIT_SUCCESS;
}


