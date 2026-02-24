// Q18-Given an array of integers, rotate the array to the right by k positions.
// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k


#include <stdio.h>
int main()
{
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    for(i = k; i < n; i++)
        temp[i] = arr[i - k];

    for(i = 0; i < n; i++)
        arr[i] = temp[i];

    printf("Array after rotation:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
