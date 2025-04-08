#include <stdio.h>
#include <stdlib.h>

// This is the definition for a binary tree node
struct treeNode {
    int value;

    // This sets the left and right children of the node as a pointer to the next node just like part 1
    struct treeNode *left;
    struct treeNode *right;
};

// This is a helper function to create a new node
struct treeNode* newNode(int value) {
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// The recursive inorder traversal is: Left -> Root -> Right 
void inorder(struct treeNode* root, int* result, int* returnSize) 
{
    if (root == NULL) return;

    // This is the recursive call to the left child of the node
    inorder(root->left, result, returnSize);
    result[(*returnSize)++] = root->value;
    inorder(root->right, result, returnSize);
}

// This is the wrapper function that initializes the result array and calls the recursive function 
int* inorderTraversal(struct treeNode* root, int* returnSize) 
{
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // The size is 100
    inorder(root, result, returnSize);
    return result;
}

int main() 
{
    // This creates a simple binary tree for testing
    struct treeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    int returnSize = 0;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // This frees all of the memory 
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
