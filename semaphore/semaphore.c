#include <semaphore.h>
typedef sem_t Semaphore;

typedef struct {
    int *array;
    int length;
    int next_in;
    int next_out;
    Semaphore *mutex;
    Semaphore *items;
    Semaphore *spaces;
} Queue;


Semaphore *make_semaphore(int value) {
    Semaphore *sem = check_malloc(sizeof(Semaphore));

    // returns 0 if succeeds and -1 if it goes wrong
    int n = sem_init(sem, 0 , value);
    if (n != 0) perror_exit("sem_init failed");
    return sem;
}

void semaphore_wait(Semaphore *sem) {
    // decrements one and waits when the sem is 0 or less
    int n = sem_wait(sem);
    if (n != 0 ) perror_exit("sem_wait failed");
}

void semaphore_signal(Semaphore *sem) {
    // increments the semaphore value
    int n = sem_post(sem);
    if (n != 0 ) perror_exit("sem_wait failed");
}

Queue *make_queue(int length) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->length = length;
    queue->array = (int *) malloc(length*sizeof(int));
    queue->next_in = 0;
    queue->next_out = 0;
    // used to guarantee exclusive access to this queue; the initial value is 1: mutex is unlocked
    queue->mutex = make_semaphore(1);
    // number of items in the queue = number of consumer threads that can execute queue_pop without blocking
    queue->items = make_semaphore(0);
    // number of empty spaces in the queue = number of producer threads that can execute queue_push without blocking
    queue->spaces = make_semaphore(length-1);

    return queue;
}

void queue_push(Queue *queue, int item) {
    // decrement one and wait the semaphore
    semaphore_wait(queue->spaces);
    // lock the queue for adding content
    semaphore_wait(queue->mutex);

    // pushing to the next of the queue
    queue->array[queue->next_in] = item;
    queue->next_in = queue_incr(queue, queue->next_in);

    // increments the mutex and items by one
    semaphore_signal(queue->mutex);
    semaphore_signal(queue->items);
}

int queue_pop(Queue *queue) {
    // decrement the item and lock mutex
    semaphore_wait(queue->items);
    semaphore_wait(queue->mutex);

    int item = queue->array[queue->next_out];
    queue->next_out = queue_incr(queue, queue->next_out);

    // increments the mutex and items by one
    semaphore_signal(queue->mutex);
    semaphore_signal(queue->spaces);
}

int main(){
    Semaphore *mutex = make_semaphore(1);

    return 0;
}