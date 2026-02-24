// Q15 Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

#include <stdio.h>
int main() {
    int n, i, j, sum = 0;
    int a[10][10];

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < n; i++)
        sum += a[i][i];

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
