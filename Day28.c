// Q28- Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first = NULL, *last = NULL;

void create(int n) {
    struct node *temp, *newnode;
    int i;

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if(first == NULL) {
            first = newnode;
            last = newnode;
            newnode->next = first;
        }
        else {
            last->next = newnode;
            last = newnode;
            last->next = first;
        }
    }
}

void traverse() {
    if(first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = first;
    printf("Circular Linked List elements are:\n");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("(back to first)\n");
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);
    traverse();

    return 0;
}