#include <stdio.h>
#include <stdlib.h>

typedef struct map_t {
    int key;
    int value;
    struct map_t * next;
} map_t;

// global definition of head
struct map_t * head = NULL;

// define the map, if it already exists return -1 else return true or 0
int defineMap(int key, int value) {
    if (head == NULL){
        head = malloc(sizeof(map_t));
        head -> next = NULL;
        head -> key = key;
        head -> value = value;
        return 0;
    }
    // initialize current and previous nodes
    struct map_t * temp = head;
    struct map_t * current = head;
    struct map_t * previous = head;

    while(current != NULL) {
        // save the previous node
        previous = current;
        if(current->key == key) return -1;

        // get the next node
        current = current->next;
    }
    // add to the list
    previous->next = malloc(sizeof(map_t));

    // initialize the next node
    previous->next->key = key;
    previous->next->value = value;
    previous->next->next = NULL;
    head = temp;
    return 0;
}

// look for the key in the map, if not found print -1 else print value
int lookUpMap(int key) {
    struct map_t * current = head;
    while(current != NULL) {
        if(current->key == key) return current->value;
        // get the next node
        current = current->next;
    }
    return -1;
}

int main() {
    defineMap(1,2);
    int output = lookUpMap(1);
    printf("should output 2 %d \n", output);
    defineMap(2,4);
    output = lookUpMap(6);
    printf("should output -1 %d \n", output);
    defineMap(6,2);
    output = lookUpMap(2);
    printf("%d", output);
    printf("should output 4 %d \n", output);

    output = lookUpMap(6);
    printf("%d", output);
    printf("should output 2 %d \n", output);
    return 0;
}