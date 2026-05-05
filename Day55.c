// Q55-Print the nodes visible when the binary tree is viewed from the right side.
// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* q[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (front == -1) front = 0;
    q[++rear] = node;
}

struct Node* dequeue() {
    struct Node* temp = q[front];
    if (front == rear) front = rear = -1;
    else front++;
    return temp;
}

int isEmpty() {
    return front == -1;
}

struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (!isEmpty() && i < n) {
        struct Node* temp = dequeue();

        if (i < n && arr[i] != -1) {
            temp->left = newNode(arr[i]);
            enqueue(temp->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = newNode(arr[i]);
            enqueue(temp->right);
        }
        i++;
    }
    return root;
}

void rightView(struct Node* root) {
    if (!root) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front + 1;

        for (int i = 1; i <= size; i++) {
            struct Node* temp = dequeue();

            if (i == size)
                printf("%d ", temp->data);

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    printf("Right View: ");
    rightView(root);

    return 0;
}