#include <stdio.h>
#include <stdlib.h>

// Defines values that will be important for the linked list
struct listNode {
    int value;
    struct listNode *next;
};

// This removes elements from the linked list to prevent memory leaks
struct listNode* removeElements(struct listNode* head, int value) {
    // This handles elements at the start of the list to prevent the leaks
    while (head != NULL && head->value == value) 
    {
        // the struct command here is to free the memory of the node that is being removed
        struct listNode* temp = head;
        head = head->next;
        free(temp);
    }

    // This structure is for the rest of the elements in the list. We need this because we need to check the rest of the list for the value
    struct listNode* current = head;
    while (current != NULL && current->next != NULL) 
    {
        if (current->next->value == value) 
        {
            struct listNode* temp = current->next; // Struct command is needed to free the memory for the node that is being removed
            current->next = current->next->next;
            free(temp);
        } 
        else 
        {
            current = current->next;
        }
    }
    return head;
}

// This structure creates the new node for the linked list. We need this structure because it is how we create new nodes for the list
struct listNode* createNode(int value) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// This just prints the linked list. We use a void function because we do not need to return anything from it
void printList(struct listNode* head) 
{
    // This loop prints out the list, we need a loop because the size of the list was not defined at any point
    while (head != NULL) 
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// This function frees the linked list that way we won't have to worry about memory crashes
void freeList(struct listNode* head) 
{
    // We need a loop to free the list becaues again, the size of the list was not defined
    while (head != NULL) 
    {
        struct listNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int value = 6;

    // This part creates the linked list: 1 - 6
    struct listNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original list:\n");
    printList(head);
    head = removeElements(head, value);

    // Prints list then frees the list
    printf("The updated list after removing %d:\n", value);
    printList(head);
    freeList(head);

    return 0; // Returns 0 
}
