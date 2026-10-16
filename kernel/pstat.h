#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
  int inuse[NPROC];     // Whether process slot is in use (1 or 0)
  int pid[NPROC];       // Process ID
  int runtime[NPROC];
  int pass[NPROC];
  int passTotal;   // Number of times each process has run
};

#endif // _PSTAT_H_
