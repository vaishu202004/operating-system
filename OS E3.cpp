#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int burst_time[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(burst_time[i] > burst_time[j]) {
                swap(&burst_time[i], &burst_time[j]);
            }
        }
    }
}

int main() {
    int n = 4;
    int burst_time[] = {6, 8, 7, 3};
    int waiting_time[n], turnaround_time[n];
    
    sort(burst_time, n);
    
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    
    for(int i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
