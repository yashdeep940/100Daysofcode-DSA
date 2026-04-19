// Q30-Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node *create() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient: ");
        scanf("%d", &newnode->coeff);
        printf("Enter exponent: ");
        scanf("%d", &newnode->exp);

        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    if(head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    printf("Polynomial: ");
    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if(temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct node* add(struct node *p1, struct node *p2) {
    struct node *result = NULL, *tail = NULL, *newnode;

    while(p1 != NULL && p2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        if(p1->exp == p2->exp) {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp) {
            newnode->coeff = p1->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
        }
        else {
            newnode->coeff = p2->coeff;
            newnode->exp = p2->exp;
            p2 = p2->next;
        }

        if(result == NULL) {
            result = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    while(p1 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = p1->coeff;
        newnode->exp = p1->exp;
        newnode->next = NULL;
        if(result == NULL) result = tail = newnode;
        else { tail->next = newnode; tail = newnode; }
        p1 = p1->next;
    }

    while(p2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = p2->coeff;
        newnode->exp = p2->exp;
        newnode->next = NULL;
        if(result == NULL) result = tail = newnode;
        else { tail->next = newnode; tail = newnode; }
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct node *poly1, *poly2, *sum;

    printf("Enter first polynomial:\n");
    poly1 = create();

    printf("Enter second polynomial:\n");
    poly2 = create();

    printf("\nFirst Polynomial:\n");
    display(poly1);

    printf("Second Polynomial:\n");
    display(poly2);

    sum = add(poly1, poly2);

    printf("Sum Polynomial:\n");
    display(sum);

    return 0;
}
