#include<stdio.h>
#include<stdlib.h>
// d?nh nghia 1 nút
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// T?o nút m?i 
Node *createNode(int data){
    // c?p phát b? nh?
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// chèn 1 nút vào cây
Node *insertNode(Node *node, int data){
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data<node->data)
    {
        node->left = insertNode(node->left, data);
    }else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}
// duy?t cây theo phuong pháp ti?n th? t?
void preoderTraversal(Node *node){
    if(node!=NULL){
        printf("%d \t", node->data);
        preoderTraversal(node->left);
        preoderTraversal(node->right);
    }
}

// trai goc phai
void tgp(Node *node){
    if(node!=NULL){
        preoderTraversal(node->left);
		printf("%d \t", node->data);
        preoderTraversal(node->right);
    }
}
void tpg (Node *node){
    if(node!=NULL){
    preoderTraversal(node->left);
	preoderTraversal(node->right);	
	printf("%d \t", node->data);
    }
}
int main(){
    Node *tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 1);
    tree = insertNode(tree, 3);
//    preoderTraversal(tree);
//    tgp(tree);
   tpg(tree);
    return 0;
}
