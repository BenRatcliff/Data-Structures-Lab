#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Defines queue size as 100 

typedef struct {
    // This is the queue data structure 
    int data[MAX_SIZE];
    int front, rear, size;
} Queue;

// Queue Operations
void queue_init(Queue *q) 
{
    // Initializes the queue 
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int queue_is_empty(Queue *q) 
{
    // Returns 1 if empty which it is not 
    return q->size == 0;
}

int queue_is_full(Queue *q) 
{
    // Returns 1 if full which it shouldn't be 
    return q->size == MAX_SIZE;
}

void queue_push(Queue *q, int x) 
{
    if (!queue_is_full(q)) 
    {
        // Pushes the value onto the queue 
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = x;
        q->size++;
    }
}

int queue_pop(Queue *q) 
{
    if (!queue_is_empty(q)) 
    {
        // Pops the value from the queue
        int value = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
        return value;
    }
    return -1; // Returns if empty
}

int queue_front(Queue *q) 
{
    // Peeks value from the queue
    if (!queue_is_empty(q))
    {
        return q->data[q->front];
    }
    return -1; // Returns if queue is empty 
}

typedef struct {
    // This is the stack data structure 
    Queue q1, q2;
} MyStack;

void myStackInit(MyStack *s) 
{
    // Initializes the stack 
    queue_init(&s->q1);
    queue_init(&s->q2);
}

void myStackPush(MyStack *s, int x) 
{
    queue_push(&s->q2, x); // Pushes to q2

    // Moves the elements to maintain a LIFO order
    while (!queue_is_empty(&s->q1)) 
    {
        queue_push(&s->q2, queue_pop(&s->q1));
    }

    // Swaps the queues 
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int myStackPop(MyStack *s) 
{
    // Pops the value from the stack 
    return queue_pop(&s->q1); 
}

int myStackTop(MyStack *s) 
{
    // Peeks the value from the stack 
    return queue_front(&s->q1);
}

int myStackEmpty(MyStack *s) 
{
    // Checks if the stack is empty 
    return queue_is_empty(&s->q1);
}

int main() {
    MyStack s;
    myStackInit(&s);

    myStackPush(&s, 1);
    myStackPush(&s, 2);
    printf("Top: %d\n", myStackTop(&s)); // Prints 2
    printf("Pop: %d\n", myStackPop(&s)); // Prints 2
    printf("Is Empty: %d\n", myStackEmpty(&s)); // Prints 0 
    printf("Pop: %d\n", myStackPop(&s)); // Prints 1
    printf("Is Empty: %d\n", myStackEmpty(&s)); // Prints 2 

    return 0;
}
