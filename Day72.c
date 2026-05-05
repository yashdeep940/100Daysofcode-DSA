// Q72-Given a string s consisting of lowercase letters, find the first repeated character in the string. 
// A character is considered repeated if it appears more than once, and among all such characters, 
// the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.


#include <stdio.h>

int main() {
    char s[1000];

    // take input
    printf("Enter string: ");
    scanf("%s", s);

    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (seen[idx]) {
            printf("First repeated character: %c\n", s[i]);
            return 0;
        }

        seen[idx] = 1;
    }

    printf("-1\n");
    return 0;
}