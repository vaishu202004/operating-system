#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 4

int main() {
    int arrival_time[MAX_PROCESSES] = {0, 1, 2, 4};
    int burst_time[MAX_PROCESSES] = {5, 3, 3, 1};
    int remaining_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES] = {0, 0, 0, 0};
    int turnaround_time[MAX_PROCESSES] = {0, 0, 0, 0};
    bool completed[MAX_PROCESSES] = {false, false, false, false};
    int current_time = 0;
    int completed_processes = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

 
    for (int i = 0; i < MAX_PROCESSES; i++) {
        remaining_time[i] = burst_time[i];
    }

  
    while (completed_processes < MAX_PROCESSES) {
        int shortest_process = -1;
        int shortest_time = 9999;

    
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!completed[i] && remaining_time[i] < shortest_time && arrival_time[i] <= current_time) {
                shortest_process = i;
                shortest_time = remaining_time[i];
            }
        }

        
        if (shortest_process == -1) {
            current_time++;
        }
       
        else {
            remaining_time[shortest_process]--;
            current_time++;

           
            if (remaining_time[shortest_process] == 0) {
                completed_processes++;
                completed[shortest_process] = true;
                waiting_time[shortest_process] = current_time - arrival_time[shortest_process] - burst_time[shortest_process];
                turnaround_time[shortest_process] = current_time - arrival_time[shortest_process];

               
                avg_waiting_time += waiting_time[shortest_process];
                avg_turnaround_time += turnaround_time[shortest_process];
            }
        }
    }

  
    avg_waiting_time /= MAX_PROCESSES;
    avg_turnaround_time /= MAX_PROCESSES;

  
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f ms\n", avg_waiting_time);
    printf("Average turnaround time: %.2f ms\n", avg_turnaround_time);

    return 0;
}
