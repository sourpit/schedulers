#include "schedulers.h"

int main(void) {
  int input = 0;
  int total_processes = 0;
  int num_queues = 0;

  puts("Enter the number of processes:\n");
  scanf("%d", &total_processes);

  int loop = 1;
  while (loop) {
    puts("\nSchedulers\n"
         "1. Round Robin\n"
         "2. First Come First Serve\n"
         "3. Shortest Job First\n"
         "4. Priority Queue\n"
         "5. Multilevel Queue\n"
         "6. Multilevel Feedback Queue\n"
         "0. Exit\n\n"
         "Choose a number: ");
    scanf("%d", &input);

    switch (input) {
    case 1:
      round_robin(total_processes);
      break;

    case 2:
      first_come_first_serve(total_processes);
      break;

    case 3:
      sjf(total_processes);
      break;

    case 4:
      priority(total_processes);
      break;

    case 5:
      multilevel_queue(total_processes);
      break;

    case 6:
      printf("Enter number of queues: \n");
      scanf("%d", &num_queues);

      if (num_queues <= 0) {
        printf("Invalid queue count.\n");
        return 1;
      }

      mfqs(total_processes, num_queues);
      break;

    case 0:
      puts("Bye\n");
      loop = 0;
      break;

    default:
      puts("Can't use that!");
    }
  }
}
