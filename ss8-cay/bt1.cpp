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
    // N?u cây r?ng, t?o nút m?i
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

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d", root->data);  
        preOrder(root->left);       
        preOrder(root->right);      
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);        
        printf("%d", root->data);  
        inOrder(root->right);      
    }
}
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);      
        postOrder(root->right);    
        printf("%d", root->data); 
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {4, 2, 5, 1, 3};  
    int n = sizeof(values) / sizeof(values[0]);

 
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Duyet Tien Thu Tu: \n");
    preOrder(root); 
    printf("\n");

    printf("Duyet Trung Thu Tu: \n");
    inOrder(root);   
    printf("\n");

    printf("Duyet Hau Thu Tu: \n");
    postOrder(root); 
    printf("\n");

    return 0;
}

