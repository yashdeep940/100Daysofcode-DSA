// Q3-Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Key found at position %d\n", i + 1);
            printf("Number of comparisons: %d\n", comparisons);
            return 0;
        }
    }

    printf("Key not found\n");
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
