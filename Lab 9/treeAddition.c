//
// Created by SURFACE on 07/12/2020.
//

#include "treeAddition.h"
#include "treePublic.h"
#include "treePrivate.h"

void CountNode(node_t* root, int *arr) // Exercise 03 A
{
    if (root==NULL) {
        return;
    }
    if (root->left==NULL && root->right==NULL) {
        arr[0]++;
    }
    if ((root->left!=NULL && root->right==NULL) ||
        (root->left==NULL && root->right!=NULL)) {
        arr[1]++;
    }
    if (root->left!=NULL && root->right!=NULL) {
        arr[2]++;
    }
    CountNode(root->left, arr);
    CountNode(root->right, arr);

    return;
}

void CountLevel (node_t *root, int *arr, int l) // Exercise 03 B
{
    if(root!=NULL) {
        arr[l-1]++;
        CountLevel (root->left, arr, l-1);
        CountLevel (root->right, arr, l-1);
    }

    return;
}

void CountPath (node_t *root, int *np, int *length) // Exercise 03 C
{
    if (root==NULL) {
        return;
    }
    *length = *length + 1;
    if (root->left==NULL && root->right==NULL) {
        *np = *np + 1;
        return;
    }
    CountPath (root->left, np, length);
    CountPath (root->right, np, length);

    return;
}
