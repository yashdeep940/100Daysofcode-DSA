// Q19_Given an array of integers, find two elements whose sum is closest to zero.
// Input:
// - First line: integer n
// - Second line: n space-separated integers


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("Two elements whose sum is closest to zero are: %d and %d\n", num1, num2);

    return 0;
}
