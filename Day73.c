// Q73-Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

#include <stdio.h>

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");

    return 0;
}