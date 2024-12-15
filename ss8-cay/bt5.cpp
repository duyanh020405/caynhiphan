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

int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void printSearchResult(int found) {
    if (found) {
        printf("Gia tri ton tai trong cay.\n");
    } else {
        printf("Gia tri khong ton tai trong cay.\n");
    }
}

int main() {
    struct Node* root = NULL;

    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Duyet cay theo thu tu inorder: ");
    inorder(root);
    printf("\n");

    int searchValue = 7;
    printf("Tim kiem gia tri %d: ", searchValue);
    int found = search(root, searchValue);
    printSearchResult(found);

    searchValue = 8;
    printf("Tim kiem gia tri %d: ", searchValue);
    found = search(root, searchValue);
    printSearchResult(found);

    return 0;
}

