// Q29-Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *temp, *newnode;
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void rotateRight(int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return;

    struct node *temp = head, *tail;
    int length = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    tail = temp;

    tail->next = head;

    k = k % length;
    int steps = length - k;

    temp = head;
    for(int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;
}

void traverse() {
    struct node *temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    printf("Enter k (rotate right by k places): ");
    scanf("%d", &k);

    rotateRight(k);

    printf("After rotation:\n");
    traverse();

    return 0;
}