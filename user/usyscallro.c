#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/riscv.h"
#include "kernel/memlayout.h"
#include "user/user.h"

struct usyscall {
  int pid;
};

int
main(void)
{
  struct usyscall *u = (struct usyscall *)USYSCALL;

  printf("Original PID: %d\n", u->pid);
  printf("Attempting to modify USYSCALL...\n");

  // This write should cause a user-mode page fault.
  u->pid = 999;

  // We should never reach this line.
  printf("FAILED: USYSCALL was writable!\n");

  exit(0);
}