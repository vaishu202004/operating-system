#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 3
#define MAX_RESOURCES 3

int main() {
    int max_matrix[MAX_PROCESSES][MAX_RESOURCES] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available_resources[MAX_RESOURCES] = {1, 2, 0};
    bool marked[MAX_PROCESSES] = {false, false, false};
    bool can_be_allocated = true;
    bool deadlock_detected = false;

 
    int need_matrix[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
        }
    }

    while (true) {
        bool found = false;

        
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!marked[i]) {
                can_be_allocated = true;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (need_matrix[i][j] > available_resources[j]) {
                        can_be_allocated = false;
                        break;
                    }
                }

                if (can_be_allocated) {
                    found = true;
                    marked[i] = true;
                    for (int j = 0; j < MAX_RESOURCES; j++) {
                        available_resources[j] += allocation_matrix[i][j];
                    }
                }
            }
        }

       
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!marked[i]) {
            deadlock_detected = true;
            printf("Deadlock detected. Process P%d is deadlocked.\n", i + 1);
        }
    }
    
    if (!deadlock_detected) {
        printf("No deadlock detected.\n");
    }

    return 0;
}
