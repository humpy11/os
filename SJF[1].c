#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n], is_completed[n];

    for (i = 0; i < n; i++) {
        is_completed[i] = 0;
    }

    printf("Enter the arrival times and burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival time for process P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    int current_time = 0, completed = 0;
    double total_turnaround_time = 0, total_waiting_time = 0;

    while (completed != n) {
        int shortest = -1;
        for (i = 0; i < n; i++) {
            if (!is_completed[i] && arrival_time[i] <= current_time) {
                if (shortest == -1 || burst_time[i] < burst_time[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            current_time++;
        } else {
            completion_time[shortest] = current_time + burst_time[shortest];
            turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];

            total_turnaround_time += turnaround_time[shortest];
            total_waiting_time += waiting_time[shortest];

            is_completed[shortest] = 1;
            completed++;
            current_time = completion_time[shortest];
        }
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);

    return 0;
}