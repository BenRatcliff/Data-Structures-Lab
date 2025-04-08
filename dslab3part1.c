#include <stdio.h>
#include <stdlib.h>

// This is the definition for a binary tree node
struct treeNode {
    int value;

    // This sets the left and right children of the node as a pointer to the next node 
    struct treeNode *left;
    struct treeNode *right;
};

// The function to create a new tree node 
struct treeNode* newNode(int value) {
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This is the function to perform the preorder traversal of the binary tree
void preorder(struct treeNode* root, int* result, int* returnSize) 
{
    if (root == NULL) return;
    
    // This stores the value of the current node in the resulting array and increments the size
    result[(*returnSize)++] = root->value;
    preorder(root->left, result, returnSize);
    preorder(root->right, result, returnSize);
}

// This is the wrapper function that initializes the result array and calls for the preorder traversal 
int* preorderTraversal(struct treeNode* root, int* returnSize) 
{
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // The range is 100
    preorder(root, result, returnSize);
    return result;
}

int main() 
{
    // This code creates a simple binary tree for testing purposes
    struct treeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    // This performs the preorder traversal and prints the result 
    int returnSize = 0;
    int* result = preorderTraversal(root, &returnSize);

    printf("The Preorder Traversal is: ");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Lastly this frees the allocated memory for the tree nodes and the result array 
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
