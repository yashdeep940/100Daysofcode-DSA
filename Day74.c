// Q74-Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.


#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char names[1000][50];

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int count[1000] = {0};

    for (int i = 0; i < n; i++) {
        if (count[i] == -1) continue;

        count[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count[i]++;
                count[j] = -1;
            }
        }
    }

    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < n; i++) {
        if (count[i] == -1) continue;

        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("Winner: %s %d\n", winner, maxVotes);

    return 0;
}