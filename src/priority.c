#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void priority(int total_processes) {
  int n = total_processes;

  /* b is array for burst time, p for priority and index for processes id */
  int b[n], p[n], index[n];
  for (int i = 0; i < n; i++) {
    printf("Enter Burst Time and priority Value for process %d (e.g 20 30): \n",
           i + 1);
    scanf("%d %d", &b[i], &p[i]);
    index[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    int a = p[i], m = i;

    /* Finding out highest priority element and placing it at its desired
     * position */
    for (int j = i; j < n; j++) {
      if (p[j] > a) {
        a = p[j];
        m = j;
      }
    }

    swap(&p[i], &p[m]);
    swap(&b[i], &b[m]);
    swap(&index[i], &index[m]);
  }

  /* T stores the starting time of processes */
  int t = 0;

  /* Printing scheduled process */
  puts("Order of process Execution is\n");
  for (int i = 0; i < n; i++) {
    printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
    t += b[i];
  }

  puts("\n");
  puts("Process ID\t Burst Time\t Wait Time\t Turnaround Time\n");
  int wait_time = 0;
  for (int i = 0; i < n; i++) {
    printf("P%d\t\t %d\t\t %d\t\t %d\n", index[i], b[i], wait_time,
           wait_time + b[i]);
    wait_time += b[i];
  }
}
