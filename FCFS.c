#include <stdio.h>

void FindwaitingTime(int processes[], int n , int bt[], int wt[]) {
    wt[0] = 0;   // First process has zero waiting time

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void FindturnAroundTime(int processes[], int n , int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];   // TAT = BT + WT
}

void findavgTime(int processes[], int n , int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Calculate WT & TAT
    FindwaitingTime(processes, n, bt, wt);
    FindturnAroundTime(processes, n, bt, wt, tat);

    printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");

    // Print per process data and compute totals
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Print averages
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {5, 3, 8, 6};

    findavgTime(processes, n, burst_time);

    return 0;
}
