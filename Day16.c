// Q16-Given an array of integers, count the frequency of each distinct element and print the result.
// Input:
// - First line: integer n (size of array)
// - Second line: n integers

#include <stdio.h>
int main() {
    int a[100], n, i, j, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        count = 1;

        if(a[i] == -1) 
            continue;

        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                a[j] = -1;
            }
        }

        printf("%d occurs %d times\n", a[i], count);
    }

    return 0;
}
