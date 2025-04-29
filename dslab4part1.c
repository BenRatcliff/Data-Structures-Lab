#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This is the definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// This function checks if two trees are mirror images of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) // We use the bool type to return true or false
{
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
}

// Then we check if the tree is symmetric by comparing it to itself 
bool isSymmetric(struct TreeNode* root) 
{
    return isMirror(root, root);
}

// This funtion creates a new tree node with the given value 
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This function frees the memory allocated for the binary tree
void freeTree(struct TreeNode* root) 
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() 
{
    // This is the symmettric tree I'm using for this part of the lab
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    printf("%s\n", isSymmetric(root) ? "True" : "False");

    // Frees the memory allocated for the tree 
    freeTree(root);

    return 0;
}
