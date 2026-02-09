// Q9-A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char codeName[100];

    printf("Enter the code name: ");
    scanf("%s", codeName);

    reverseString(codeName);

    printf("Mirror format code name: %s\n", codeName);

    return 0;
}
