#include <stdio.h>
#include <stdlib.h>

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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void findLevel2Nodes(struct Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        if (root->left->left != NULL) printf("%d ", root->left->left->data); 
        if (root->left->right != NULL) printf("%d ", root->left->right->data);
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) printf("%d ", root->right->left->data); 
        if (root->right->right != NULL) printf("%d ", root->right->right->data); 
    }
}

void printNodes(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printNodes(root->left);
        printNodes(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }


    printf("Cac dinh: \n");
    printNodes(root);
    printf("\n");

    printf("Cac dinh lop 2: \n");
    findLevel2Nodes(root);
    printf("\n");

    return 0;
}

