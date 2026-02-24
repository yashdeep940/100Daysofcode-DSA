// Q14 Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

#include <stdio.h>
int main() {
    int n, i, j, flag = 1;
    int a[10][10];

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                flag = 0;
            if(i != j && a[i][j] != 0)
                flag = 0;
        }
    }

    if(flag == 1)
        printf("Matrix is an Identity Matrix");
    else
        printf("Matrix is NOT an Identity Matrix");

    return 0;
}
