#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bool isCompleteBinaryTree(Node* root) {
    if (root == NULL) return true;
    Queue* q = createQueue();
    enqueue(q, root);
    bool mustBeLeaf = false;

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current->left) {
            if (mustBeLeaf) {
                freeQueue(q);
                return false;
            }
            enqueue(q, current->left);
        } else {
            mustBeLeaf = true;
        }

        if (current->right) {
            if (mustBeLeaf) {
                freeQueue(q);
                return false;
            }
            enqueue(q, current->right);
        } else {
            mustBeLeaf = true;
        }
    }
    freeQueue(q);
    return true;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    if (isCompleteBinaryTree(root)) {
        printf("Cay la cay nhi phan hoan chinh.\n");
    } else {
        printf("Cay khong phai la cay nhi phan hoan chinh.\n");
    }

    freeTree(root);
    return 0;
}

