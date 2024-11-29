#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(2, "usage: tickettest tickets\n");
    return -1;
  }
  
  int tickets = atoi(argv[1]);
  if (settickets(tickets) == -1) {
    fprintf(2, "error: ticket count must be greater than 0\n");
    return -1;
  }

  printf("ticket count for the tickettest process has been set to %d\n", tickets);
  printf("process will now sleep indefinitely\n");
  printf("press ^p to view ticket counts\n");
  printf("append & to this command to run it in the background\n");
  printf("background usage: tickettest tickets &\n");

  while (1) {
    sleep(10);
  }

  return 0;
}