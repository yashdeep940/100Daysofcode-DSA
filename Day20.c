// Q20-Given an array of integers, count the number of subarrays whose sum is equal to zero.
// Input:
// - First line: integer n
// - Second line: n integers

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int countZeroSumSubarrays(int arr[], int n)
{
    int prefix = 0;
    int count = 0;

    int *freq = (int *)calloc(2 * MAX + 1, sizeof(int));

    int offset = MAX;

    freq[offset] = 1;

    for(int i = 0; i < n; i++)
    {
        prefix += arr[i];

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    free(freq);
    return count;
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = countZeroSumSubarrays(arr, n);
    printf("Number of subarrays with sum = :%d\n", result);

    return 0;
}