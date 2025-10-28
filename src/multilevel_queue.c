#include <stdio.h>

void multilevel_queue(int total_processes) {
  int n = total_processes;

  int p[30], bt[30], su[30], wt[30], tat[30];
  float waiting_avg, turnaround_avg;
  int tr;
  int csource = 0;
  int cuser = 0;
  int btsource[30], btuser[30], puser[30], psource[30];

  for (int i = 0; i < n; i++) {
    puts("System process/User process (Choose 0 or 1):");
    scanf("%d", &tr);
    printf("Enter the Burst Time of Process %d: \n", i + 1);
    if (tr == 1) {
      scanf("%d", &btuser[cuser]);
      puser[cuser] = i;
      cuser++;
    } else if (tr == 0) {
      scanf("%d", &btsource[csource]);
      psource[csource] = i;
      csource++;
    }
  }
  for (int i = 0; i < csource; i++) {
    p[i] = psource[i];
    bt[i] = btsource[i];
    su[i] = 0;
  }
  for (int i = 0; i < cuser; i++) {
    p[i + csource] = puser[i];
    bt[i + csource] = btuser[i];
    su[i + csource] = 1;
  }

  waiting_avg = wt[0] = 0;
  turnaround_avg = tat[0] = bt[0];

  for (int i = 0; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    waiting_avg += wt[i];
    turnaround_avg += tat[i];
  }

  puts("\nProcess\t System/User\t Burst Time\t Waiting Time\t "
       "Turnaround Time");

  for (int i = 0; i < n; i++)
    printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", p[i], su[i], bt[i], wt[i], tat[i]);

  printf("Average Waiting Time: %f\n", waiting_avg / n);
  printf("Average Turnaround Time: %f\n", turnaround_avg / n);
}
