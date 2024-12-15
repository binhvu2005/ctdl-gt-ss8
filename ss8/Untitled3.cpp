#include <stdio.h>
#include <stdlib.h>

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

int search(Node* root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;
    if (target < root->data) return search(root->left, target);
    return search(root->right, target);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    freeTree(root);
    return 0;
}

