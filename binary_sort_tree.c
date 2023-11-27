#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct BINARYSORTTREENODE_STRU {
    DataType value;
    struct BINARYSORTTREENODE_STRU* left;
    struct BINARYSORTTREENODE_STRU* right;
} BINARYSORTTREENODE;

BINARYSORTTREENODE* findMinNode(BINARYSORTTREENODE* binarySortTree)
{
    if (binarySortTree->left == NULL) {
        return binarySortTree;
    } else {
        return findMinNode(binarySortTree->left);
    }
}

BINARYSORTTREENODE* findMaxNode(BINARYSORTTREENODE* binarySortTree)
{
    if (binarySortTree->right == NULL) {
        return binarySortTree;
    } else {
        return findMaxNode(binarySortTree->right);
    }
}

BINARYSORTTREENODE* insertNode(BINARYSORTTREENODE* binarySortTree, DataType value)
{
    if (binarySortTree = NULL) {
        binarySortTree = (BINARYSORTTREENODE*)malloc(sizeof(BINARYSORTTREENODE));
        binarySortTree->value = value;
        return binarySortTree;
    }
    if (binarySortTree->value > value) {
        binarySortTree->left = insertNode(binarySortTree->left, value);
    }
    if (binarySortTree->value < value) {
        binarySortTree->right = insertNode(binarySortTree->right, value);
    }
    return binarySortTree;
}

BINARYSORTTREENODE* deleteNode(BINARYSORTTREENODE* binarySortTree, DataType value)
{
    if (binarySortTree == NULL) {
        return binarySortTree;
    }
    if (binarySortTree->value > value) {
        binarySortTree->left = deleteNode(binarySortTree->left, value);
    } else if (binarySortTree->value < value) {
        binarySortTree->right = deleteNode(binarySortTree->right, value);
    } else {
        if (binarySortTree->left == NULL || binarySortTree->right == NULL) {
            BINARYSORTTREENODE* temp = binarySortTree->right == NULL ? binarySortTree->left : binarySortTree->right;
            free(binarySortTree);
            return temp;
        }
        BINARYSORTTREENODE* temp = findMaxNode(binarySortTree->left);
        binarySortTree->value = temp->value;
        binarySortTree->left = deleteNode(binarySortTree->left, temp->value);
    }
    return binarySortTree;
}

void preorder(BINARYSORTTREENODE* binarySortTree)
{
    if (binarySortTree == NULL)
        return;
    // print binarySortTree->value;
    preorder(binarySortTree->left);
    preorder(binarySortTree->right);
}

void inorder(BINARYSORTTREENODE* binarySortTree)
{
    if (binarySortTree == NULL)
        return;
    inorder(binarySortTree->left);
    // print binarySortTree->value;
    inorder(binarySortTree->right);
}

void postorder(BINARYSORTTREENODE* binarySortTree)
{
    if (binarySortTree == NULL)
        return;
    postorder(binarySortTree->left);
    postorder(binarySortTree->right);
    // print binarySortTree->value;
}