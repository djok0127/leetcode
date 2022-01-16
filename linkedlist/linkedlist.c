// A simple C program to introduce
// a linked list
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};

void createNode(struct Node* head) {
    struct Node *current = head;
    for (int i = 1; i < 10; i++){
        current->next = (struct Node*)malloc(sizeof(struct Node));
        current->next->data = i;
        printf("creation current %d \n",current->data);
        current = current->next;
    }
    current-> next = NULL;
}

void printAllNodes(struct Node * head) {
    struct Node * current = head;
    while (current != NULL){
        printf("current %x %d \n", current,current->data);
        current = current->next;
    }
}

void deleteNode(struct Node * head, int position) {
    struct Node * current = head;
    struct Node * previous = NULL;
    int counter = 0;
    while (current) {
        if (position == 0) {
            if (head->next){
                printf("deleting memory %x value %d\n",current,current->data);
                struct Node* temp = head;
                head = head->next;
                free(temp);
            }
            else {
                printf("deleting memory %x value %d\n",current,current->data);
                head = NULL;
            }
            break;
        }
        if (counter == position - 1) {
            printf("deleting memory %x value %d\n",current,current->next->data);
            // delete the node
            // current  current's next next
            previous->next = current->next->next;
            break;
        }   
        // increment
        current = current->next;
        previous = current;
        counter++;
    }
}

int main() {
    printf("start\n");
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    printf("%x\n", head);
    head->data = 0;
    printf("create node\n");
    createNode(head);
    printf("prints all nodes\n");
    printAllNodes(head);
    deleteNode(head, 6);
    printf("prints all nodes\n");
    printAllNodes(head);
    deleteNode(head, 0);
    printf("prints all nodes\n");
    printAllNodes(head);
    deleteNode(head, 1);
    printf("prints all nodes\n");
    printAllNodes(head);
    return 0;
}

