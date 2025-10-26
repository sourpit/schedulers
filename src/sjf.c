#include <stdio.h>

void sjf(int total_processes) {
  int n = total_processes;
  int bt[20], p[20], wt[20], tat[20], total = 0, totalT = 0, pos, temp;
  float avg_wt, avg_tat;

  puts("\nEnter Burst Time: \n");
  for (int i = 0; i < n; i++) {
    printf("p%d:", i + 1);
    scanf("%d", &bt[i]);
    p[i] = i + 1;
  }

  /* Sorting of burst time */
  for (int i = 0; i < n; i++) {
    pos = i;
    for (int j = 1 + 1; j < n; j++) {
      if (bt[j] < bt[pos])
        pos = j;
    }

    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] = temp;

    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;
  }

  wt[0] = 0;

  /* finding the waiting time of all the processes */
  for (int i = 1; i < n; i++) {
    wt[i] = 0;
    for (int j = 0; j < i; j++)
      /* individual WT by adding BT of all previous completed processes */
      wt[i] += bt[j];

    /* total waiting time */
    total += wt[i];
  }

  /* average waiting time */
  avg_wt = (float)total / n;

  puts("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
  for (int i = 0; i < n; i++) {
    /* Turnaround time of individual processes */
    tat[i] = bt[i] + wt[i];

    /* Total turnaround time */
    totalT += tat[i];
    printf("\np%d\t %d\t %d\t %d\n", p[i], bt[i], wt[i], tat[i]);
  }

  /* Average turnaround time */
  avg_tat = (float)totalT / n;
  printf("\n\nAverage Waiting Time: %f", avg_wt);
  printf("\n\nAverage Turnaround Time: %f", avg_tat);
}
