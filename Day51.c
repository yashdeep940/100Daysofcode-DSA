// Q51-Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    struct Node* root = NULL;
    int n, value, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter first node: ");
    scanf("%d", &n1);

    printf("Enter second node: ");
    scanf("%d", &n2);

    struct Node* res = LCA(root, n1, n2);

    if (res)
        printf("LCA: %d\n", res->data);
    else
        printf("LCA not found\n");

    printf("Time Complexity (Best/Average): O(log n)\n");

    return 0;
}