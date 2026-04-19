// Q23-Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertEnd(struct node* head, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node *merged = NULL, *tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        if (l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if (merged == NULL) {
            merged = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (l1 != NULL) {
        merged = insertEnd(merged, l1->data);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        merged = insertEnd(merged, l2->data);
        l2 = l2->next;
    }

    return merged;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n1, n2, x, i;

    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    printf("Enter number of nodes in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    printf("\nList 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    merged = mergeLists(list1, list2);

    printf("Merged Sorted List: ");
    display(merged);

    return 0;
}