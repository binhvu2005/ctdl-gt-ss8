#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

int isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int values[] = {10, 5, 15, 3, 7, 12, 20};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    if (isBST(root)) {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    } else {
        printf("Cay khong la cay nhi phan tim kiem (BST).\n");
    }

    freeTree(root);
    return 0;
}

