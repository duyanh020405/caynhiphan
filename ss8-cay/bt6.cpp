#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isBST(struct Node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

void checkBST(struct Node* root) {
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("Cay la cay nhi phan tim kiem (BST)\n");
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem (BST)\n");
    }
}

int main() {
    struct Node* root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(15);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->left = createNode(12);
    root1->right->right = createNode(20);
    
    printf("Cay 1:\n");
    checkBST(root1);

    struct Node* root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2->left->left = createNode(6);
    root2->left->right = createNode(7);
    root2->right->left = createNode(12);
    root2->right->right = createNode(20);
    
    printf("Cay 2:\n");
    checkBST(root2);

    struct Node* root3 = NULL;
    printf("Cay 3:\n");
    checkBST(root3);

    return 0;
}

