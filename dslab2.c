#include <stdio.h>
#include <stdlib.h>

// Defines values for the linked list
struct listNode {
    int value;
    struct listNode *next;
};

// This is the structure that is needed to reverse the linked list recursively
struct listNode* reverseListRecursive(struct listNode* head) {
    if (head == NULL) // If the head is NULL, then the list is empty
    {
        return NULL;
    }
    if (head->next == NULL) 
    {
        return head;  // The last node becomes the new head
    }

    // This recursively reverses the list from the second node onwards.
    // Since the size of the list was not defined at any time, we need to use recursion to reverse the list
    struct listNode* newHead = reverseListRecursive(head->next);

    // Reconnect the current node to reverse the link
    head->next->next = head;  // This line makes the next node the new head
    head->next = NULL;        // This line makes the current node the last node

    // Since the head of the list is the last node, we need to return the new head
    return newHead;
}

// This structure creates a new node for the linked list, which is needed to create new nodes for the list
struct listNode* createNode(int value) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode)); // This line allocates memory for the new node
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// This prints the linked list
void printList(struct listNode* head) 
{
    while (head != NULL) 
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// This void function frees the linked list
void freeList(struct listNode* head) 
{
    while (head != NULL) 
    {
        struct listNode* temp = head; // This line frees the memory of the node that is being removed
        head = head->next;
        free(temp);
    }
}

int main() 
{
    // Creating the linked list 1 - 5
    struct listNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);
    head = reverseListRecursive(head); // This is needed to update the head of the list

    // Prints list and frees memory
    printf("Reversed list:\n");
    printList(head);
    freeList(head);

    return 0; // Returns 0 
}
