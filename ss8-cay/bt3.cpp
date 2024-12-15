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
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(struct Node* root, int x) {
    if (root == NULL) {
        return 0; // Not Found
    }
    
    if (root->data == x) {
        return 1; // Found
    }
    
    if (x < root->data) {
        return search(root->left, x);
    }
    else {
        return search(root->right, x);
    }
}

// Hàm in thông báo k?t qu? tìm ki?m
void printSearchResult(int result) {
    if (result) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue;

    printf("Enter value to search: ");
    scanf("%d", &searchValue);

    int result = search(root, searchValue);

    printf("Search = %d\n", searchValue);
    printSearchResult(result);

    return 0;
}



