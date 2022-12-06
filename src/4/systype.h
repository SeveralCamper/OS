#ifndef SRC_SYSTYPE_H_
#define SRC_SYSTYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void API_contract();
char *enter_PID_process(int pid, int string_length, char *string);

#endif //  SRC_SYSTYPE_H_

