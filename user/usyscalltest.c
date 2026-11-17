#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/riscv.h"
#include "kernel/memlayout.h"
#include "user/user.h"

// Structure containing the process ID.
struct usyscall {
  int pid;
};

int
main(int argc, char *argv[])
{
  // Read the PID directly from the USYSCALL page.
  struct usyscall *u = (struct usyscall *)USYSCALL;

  int shared_pid = u->pid;
  int actual_pid = getpid();

  printf("PID from USYSCALL: %d\n", shared_pid);
  printf("PID from getpid(): %d\n", actual_pid);

  if (shared_pid == actual_pid) {
    printf("USYSCALL test PASSED!\n");
  } else {
    printf("USYSCALL test FAILED!\n");
  }

  exit(0);
}