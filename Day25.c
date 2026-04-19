// Q25-Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, val;

    printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &val);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int countOccurrences(struct node *head, int key) {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, key;
    struct node *head;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Enter element to count: ");
    scanf("%d", &key);

    printf("Occurrences of %d = %d\n", key, countOccurrences(head, key));

    return 0;
}