#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/riscv.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char *pageTester;
  unsigned int accessBitmap = 0;

  // Allocate memory for 32 pages.
  pageTester = malloc(32 * PGSIZE);

  if (pageTester == 0) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  // Access each of the 32 pages.
  for (int i = 0; i < 32; i++) {
    pageTester[i * PGSIZE] = 1;
  }

  // Check which pages were accessed.
  if (pgaccess(pageTester, 32, &accessBitmap) < 0) {
    printf("Error in pgaccess\n");
  } else {
    for (int i = 0; i < 32; i++) {
      printf("Page %d, accessed: %d\n",
             i, (accessBitmap & (1U << i)) != 0);
    }
  }

  // Test whether access bits were cleared.
unsigned int secondBitmap = 0;

if (pgaccess(pageTester, 32, &secondBitmap) < 0) {
  printf("Second pgaccess failed\n");
} else {
  printf("Second access bitmap: %x\n", secondBitmap);
}

  free(pageTester);
  exit(0);
}