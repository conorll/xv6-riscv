#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

void print_pstat(struct pstat *ps) {
  printf("pid, tickets, ticks\n");
  for (int i = 0; i < NPROC; i++) {
    if (ps->inuse[i])
      printf("%d %d %d\n", ps->pid[i], ps->tickets[i], ps->ticks[i]);
  }
}

int main() {
  struct pstat ps;

  if (getpinfo(&ps) < 0) {
    fprintf(2, "getpinfo failed\n");
    return 1;
  }

  print_pstat(&ps);
  return 0;
}