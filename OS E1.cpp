#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int claim[4][3] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[4][3] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int resource[3] = {9, 3, 6};
    int available[3] = {0, 0, 0};
    bool finish[4] = {false, false, false, false};
    int safe_sequence[4];
    int count = 0;

    
    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += allocation[i][j];
        }
        available[j] = resource[j] - sum;
    }

    
    while (count < 4) {
        bool found = false;
        for (int i = 0; i < 4; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < 3; j++) {
                    if (claim[i][j] - allocation[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == 3) {
                    for (int k = 0; k < 3; k++) {
                        available[k] += allocation[i][k];
                    }
                    safe_sequence[count] = i;
                    count++;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("The system is in an unsafe state\n");
            return 0;
        }
    }

    
    printf("The system is in a safe state\n");
    printf("Safe sequence: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
