#include <stdio.h>

#define NUM_PARTITIONS 6
#define MAX_PROCESSES 5

int main()
{
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[MAX_PROCESSES];
    int i, j, best_index;

   
    for (i = 0; i < MAX_PROCESSES; i++)
    {
        allocation[i] = -1;
    }

    
    for (i = 0; i < MAX_PROCESSES; i++)
    {
        best_index = -1;
        for (j = 0; j < NUM_PARTITIONS; j++)
        {
            if (processes[i] <= partitions[j])
            {
                if (best_index == -1 || partitions[j] < partitions[best_index])
                {
                    best_index = j;
                }
            }
        }
        if (best_index != -1)
        {
            allocation[i] = best_index;
            partitions[best_index] -= processes[i];
        }
    }

   
    printf("Process\tProcess Size\tPartition\n");
    for (i = 0; i < MAX_PROCESSES; i++)
    {
        printf("%d\t%d\t\t", i, processes[i]);
        if (allocation[i] != -1)
        {
            printf("%d\n", allocation[i]);
        }
        else
        {
            printf("Not allocated\n");
        }
    }

    return 0;
}
