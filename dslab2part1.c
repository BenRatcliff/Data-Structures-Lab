#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // This defines the max size of the stack

typedef struct {
    // Here is the stack data structure
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    // This is the queue data structure
    Stack input;
    Stack output;
} MyQueue;

// Stack Operations
void stack_init(Stack *s) 
{
    // Initializes the stack
    s->top = -1;
}

int stack_is_empty(Stack *s) 
{
    // Returns 1 if empty which it isn't
    return s->top == -1;
}

int stack_push(Stack *s, int value) 
{
    // Pushes the value onto the stack
    // Returns 0 if the stack is full, otherwise 1
    if (s->top >= MAX_SIZE - 1) return 0;  // Stack Overflow
    s->data[++s->top] = value;
    return 1;
}

int stack_pop(Stack *s, int *value) 
{
    // Pops the value from the stack
    if (stack_is_empty(s)) return 0;  // Stack Underflow
    *value = s->data[s->top--];
    return 1;
}

int stack_peek(Stack *s, int *value) 
{
    // Peeks the value from the stack
    if (stack_is_empty(s)) return 0;
    *value = s->data[s->top];
    return 1;
}

// Queue Operations
void myQueueInit(MyQueue *q) 
{
    // Initializes the queue 
    stack_init(&q->input);
    stack_init(&q->output);
}

void myQueuePush(MyQueue *q, int x) 
{
    // Pushes the value onto the queue 
    stack_push(&q->input, x);
}

int myQueuePop(MyQueue *q) 
{
    int value;

    // Transfer input stack to output stack if empty
    if (stack_is_empty(&q->output)) 
    {
        while (!stack_is_empty(&q->input)) 
        {
            stack_pop(&q->input, &value);
            stack_push(&q->output, value);
        }
    }

    // Pops the value from the output stack
    if (stack_pop(&q->output, &value))
    {
        return value;
    }

    return -1;  // Queue is empty
}

int myQueuePeek(MyQueue *q) 
{
    // We have int value here again because we need to return the value 
    int value;

    // Transfer input stack to output stack if empty
    if (stack_is_empty(&q->output)) 
    {
        while (!stack_is_empty(&q->input)) 
        {
            stack_pop(&q->input, &value);
            stack_push(&q->output, value);
        }
    }

    // Peeks the value from the output stack 
    if (stack_peek(&q->output, &value))
    {
        return value;
    }

    return -1;  // Queue is empty
}

int myQueueEmpty(MyQueue *q) 
{
    // This function checks if the queue is empty 
    return stack_is_empty(&q->input) && stack_is_empty(&q->output);
}

// Main function to test the implementation
int main() 
{
    // This is the main function to test the implementation
    MyQueue q;
    myQueueInit(&q);

    myQueuePush(&q, 1);
    myQueuePush(&q, 2);
    printf("Peek: %d\n", myQueuePeek(&q)); // Prints 1
    printf("Pop: %d\n", myQueuePop(&q));   // Prints 1
    printf("Is Empty: %d\n", myQueueEmpty(&q)); // Prints 0
    printf("Pop: %d\n", myQueuePop(&q));   // Prints 2
    printf("Is Empty: %d\n", myQueueEmpty(&q)); // Prints 1

    return 0;
}
