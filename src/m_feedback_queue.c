#include "schedulers.h"
#include <stdlib.h>

#define MAX_PROCESSES 10

void enqueue(Process *queue, int *rear, Process process) {
  if (*rear < MAX_PROCESSES - 1)
    queue[++(*rear)] = process;
}

Process dequeue(Process *queue, int *front) { return queue[(*front)++]; }

void displayQueue(Process *queue, int front, int rear, const char *name) {
  printf("%s Queue: ", name);
  if (rear < front) {
    printf("[empty]\n");
    return;
  }
  for (int i = front; i <= rear; i++)
    printf("[P%d (Burst: %d, Priority: %d)] ", queue[i].process_id,
           queue[i].burst_time, queue[i].priority);
  printf("\n");
}

void multilevelFeedbackQueueScheduling(Process processes[], int num_processes,
                                       int num_queues, int *time_quantums) {
  Process **queues = malloc(num_queues * sizeof(Process *));
  int *front = malloc(num_queues * sizeof(int));
  int *rear = malloc(num_queues * sizeof(int));

  for (int i = 0; i < num_queues; i++) {
    queues[i] = malloc(MAX_PROCESSES * sizeof(Process));
    front[i] = 0;
    rear[i] = -1;
  }

  printf("\n=== Starting Multilevel Feedback Queue Scheduling ===\n\n");

  for (int q = 0; q < num_queues; q++) {
    int tq = time_quantums[q];
    int current_time = 0;

    // Enqueue processes with remaining burst time
    for (int i = 0; i < num_processes; i++) {
      if (processes[i].burst_time > 0)
        enqueue(queues[q], &rear[q], processes[i]);
    }

    displayQueue(queues[q], front[q], rear[q], "Current");

    int f = front[q];
    int r = rear[q];

    while (f <= r) {
      Process p = dequeue(queues[q], &f);

      if (p.burst_time > tq) {
        p.burst_time -= tq;
        current_time += tq;

        if (q + 1 < num_queues)
          enqueue(queues[q + 1], &rear[q + 1], p);
      } else {
        current_time += p.burst_time;
        p.burst_time = 0;
      }
    }

    if (q + 1 < num_queues)
      displayQueue(queues[q + 1], front[q + 1], rear[q + 1], "Next");

    // Sync process burst times
    for (int i = 0; i < num_processes; i++) {
      if (processes[i].burst_time > 0 && q + 1 < num_queues) {
        for (int j = front[q + 1]; j <= rear[q + 1]; j++) {
          if (queues[q + 1][j].process_id == processes[i].process_id) {
            processes[i].burst_time = queues[q + 1][j].burst_time;
          }
        }
      } else if (processes[i].burst_time <= 0) {
        processes[i].burst_time = 0;
      }
    }

    printf("\n");
  }

  printf("=== Scheduling Complete ===\n");

  // Cleanup
  for (int i = 0; i < num_queues; i++)
    free(queues[i]);
  free(queues);
  free(front);
  free(rear);
}

void mfqs(int total_processes, int num_queues) {
  Process processes[total_processes];
  int *time_quantums = malloc(num_queues * sizeof(int));

  for (int i = 0; i < total_processes; i++) {
    printf("Enter process-id for process %d: ", i + 1);
    fflush(stdout);
    scanf("%d", &processes[i].process_id);

    printf("Enter burst-time for process %d: ", i + 1);
    fflush(stdout);
    scanf("%d", &processes[i].burst_time);

    printf("Enter priority for process %d: ", i + 1);
    fflush(stdout);
    scanf("%d", &processes[i].priority);
  }

  printf("\nEnter time quantum for each queue:\n");
  for (int i = 0; i < num_queues; i++) {
    printf("Queue %d time quantum: ", i + 1);
    fflush(stdout);
    scanf("%d", &time_quantums[i]);
  }

  printf("\nInitial Processes:\n");
  for (int i = 0; i < total_processes; i++)
    printf("[P%d (Burst: %d, Priority: %d)] ", processes[i].process_id,
           processes[i].burst_time, processes[i].priority);
  printf("\n\n");

  multilevelFeedbackQueueScheduling(processes, total_processes, num_queues,
                                    time_quantums);

  free(time_quantums);
}
