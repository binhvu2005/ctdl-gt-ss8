#include <stdio.h>
#include <stdlib.h>

// Cau truc node cua cay
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


void addChild(Node* parent, int leftData, int rightData) {
    if (leftData != -1) {
        parent->left = createNode(leftData);
    }
    if (rightData != -1) {
        parent->right = createNode(rightData);
    }
}


void findLevel2Nodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        if (root->left->left) printf("%d ", root->left->left->data);
        if (root->left->right) printf("%d ", root->left->right->data);
    }
    if (root->right) {
        if (root->right->left) printf("%d ", root->right->left->data);
        if (root->right->right) printf("%d ", root->right->right->data);
    }
}


void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    Node* root1 = createNode(1);
    addChild(root1, 2, 3);
    addChild(root1->left, 4, 5);
    addChild(root1->right, 6, -1);

    printf("Cac dinh lop 2 cho cay 1: ");
    findLevel2Nodes(root1);
    printf("\n");
    freeTree(root1);


    Node* root2 = createNode(1);
    addChild(root2, 2, 3);

    printf("Cac dinh lop 2 cho cay 2: ");
    findLevel2Nodes(root2);
    printf("\n");
    freeTree(root2);


    Node* root3 = createNode(1);
    addChild(root3, 2, 3);
    addChild(root3->left, 5, 6);
    addChild(root3->right, 7, 8);

    printf("Cac dinh lop 2 cho cay 3: ");
    findLevel2Nodes(root3);
    printf("\n");
    freeTree(root3);

    return 0;
}

