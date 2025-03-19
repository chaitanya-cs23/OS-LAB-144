#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n, system_count, user_count;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of system processes: ");
    scanf("%d", &system_count);

    int bt_system[system_count];
    for (i = 0; i < system_count; i++) {
        printf("\nEnter Burst Time for System Process %d: ", i + 1);
        scanf("%d", &bt_system[i]);
    }

    printf("Enter the number of user processes: ");
    scanf("%d", &user_count);

    int bt_user[user_count];
    for (i = 0; i < user_count; i++) {
        printf("\nEnter Burst Time for User Process %d: ", i + 1);
        scanf("%d", &bt_user[i]);
    }

    wt[0] = 0;
    for (i = 1; i < system_count; i++) {
        wt[i] = wt[i - 1] + bt_system[i - 1];
    }

    for (i = 0; i < system_count; i++) {
        tat[i] = wt[i] + bt_system[i];
    }

    printf("\nSystem Process Scheduling (FCFS):\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < system_count; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
        printf("S%d\t%d\t\t%d\t\t%d\n", i + 1, bt_system[i], wt[i], tat[i]);
    }

    int start_time = wt[system_count - 1] + bt_system[system_count - 1];
    for (i = 0; i < user_count; i++) {
        wt[system_count + i] = start_time;
        start_time += bt_user[i];
    }

    for (i = 0; i < user_count; i++) {
        tat[system_count + i] = wt[system_count + i] + bt_user[i];
    }

    printf("\nUser Process Scheduling (FCFS):\n");
    for (i = 0; i < user_count; i++) {
        avgwt += wt[system_count + i];
        avgtat += tat[system_count + i];
        printf("U%d\t%d\t\t%d\t\t%d\n", i + 1, bt_user[i], wt[system_count + i], tat[system_count + i]);
    }

    avgwt /= (system_count + user_count);
    avgtat /= (system_count + user_count);

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}
