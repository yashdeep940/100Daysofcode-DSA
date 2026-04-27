// Q36-Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(i = 0; i < m; i++) {
        front = (front + 1) % n;
        rear = (rear + 1) % n;
    }

    int count = 0;
    int index = front;

    while(count < n) {
        printf("%d ", queue[index]);
        index = (index + 1) % n;
        count++;
    }

    free(queue);
    return 0;
}