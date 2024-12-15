#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc c?a nút cây
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->data) {
        insertNode(&(*root)->left, value);
    } else {
        insertNode(&(*root)->right, value);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {4, 2, 5, 1, 3};
    

    for (int i = 0; i < 5; i++) {
        insertNode(&root, values[i]);
    }


    printf("Duyet Tien Thu Tu: ");
    preOrder(root);
    printf("\n");

    printf("Duyet Trung Thu Tu: ");
    inOrder(root);
    printf("\n");


    printf("Duyet Hau Thu Tu: ");
    postOrder(root);
    printf("\n");

    return 0;
}


