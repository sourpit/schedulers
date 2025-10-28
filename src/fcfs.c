#include "schedulers.h"

void first_come_first_serve(int total_processes) {
  int pid[15];
  int bt[15];

  puts("Enter process id of all the processes:");
  for (int i = 0; i < total_processes; i++)
    scanf("%d", &pid[i]);

  puts("Enter burst time of all the processes:");
  for (int i = 0; i < total_processes; i++)
    scanf("%d", &bt[i]);

  int i, wt[total_processes];
  wt[0] = 0;

  /* calculating waiting time of each process */
  for (i = 1; i < total_processes; i++)
    wt[i] = bt[i - 1] + wt[i - 1];

  puts("Process ID\t Burst Time\t Waiting Time\tTurnaround Time\n");
  float twt = 0.0;
  float tat = 0.0;
  for (i = 0; i < total_processes; i++) {
    printf("%d\t\t %d\t\t %d\t\t", pid[i], bt[i], wt[i]);

    /* calculating and printing turnaround time of each process */
    printf("%d\t\n", bt[i] + wt[i]);

    /* for calculating total waiting time */
    twt += wt[i];

    /* for calculating total turnaround time */
    tat += (wt[i] + bt[i]);
  }
  float att, awt;

  /* for calculating average waiting time */
  awt = twt / total_processes;

  /* for calculating average turnaround time */
  att = tat / total_processes;

  printf("Avg. waiting time = %f\n", awt);
  printf("Avg. turnaround time = %f\n", att);
}
