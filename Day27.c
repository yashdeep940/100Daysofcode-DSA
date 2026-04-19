// Q27-Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
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

struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

struct node* insertEnd(struct node* head, int val) {
    struct node* newnode = createNode(val);

    if(head == NULL)
        return newnode;

    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

// Find intersection by common value
int findIntersection(struct node* head1, struct node* head2) {
    struct node* p1 = head1;
    while(p1 != NULL) {
        struct node* p2 = head2;
        while(p2 != NULL) {
            if(p1->data == p2->data)
                return p1->data;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return -1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int n, m, val;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for(int i=0; i<m; i++) {
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No intersection found\n");
    else
        printf("Intersection point data = %d\n", result);

    return 0;
}