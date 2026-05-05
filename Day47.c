/*Q47-Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order input
struct Queue {
    struct Node* data;
    struct Queue* next;
};

struct Queue *front = NULL, *rear = NULL;

// Enqueue
void enqueue(struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = node;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue
struct Node* dequeue() {
    if (front == NULL)
        return NULL;

    struct Queue* temp = front;
    struct Node* node = temp->data;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

// Create new node
struct Node* createNode(int value) {
    if (value == -1)  // -1 means no node
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from user input
struct Node* buildTree() {
    int value;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &value);

    struct Node* root = createNode(value);
    if (root == NULL)
        return NULL;

    enqueue(root);

    while (front != NULL) {
        struct Node* current = dequeue();

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftVal);
        current->left = createNode(leftVal);
        if (current->left != NULL)
            enqueue(current->left);

        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightVal);
        current->right = createNode(rightVal);
        if (current->right != NULL)
            enqueue(current->right);
    }

    return root;
}

// Height function
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// Main
int main() {
    struct Node* root = buildTree();

    int h = height(root);
    printf("\nHeight of Binary Tree = %d\n", h);

    return 0;
}