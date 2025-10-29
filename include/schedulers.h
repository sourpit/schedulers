#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include <stdio.h>

typedef struct {
  int process_id;
  int burst_time;
  int priority;
} Process;

void round_robin(int total_processes);
void sjf(int total_processes);
void first_come_first_serve(int total_processes);
void priority(int total_processes);

void multilevel_queue(int total_processes);
void enqueue(Process *queue, int *rear, Process process);
Process dequeue(Process *queue, int *front);
void displayQueue(Process *queue, int front, int rear, const char *queueName);
void mfqs(int total_processes, int num_queues);

#endif // !SCHEDULERS_H
