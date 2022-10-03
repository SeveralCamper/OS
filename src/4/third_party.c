#include "third_party.h"

void init_child_process() {}

int main() {
    pid_t parent_pid, child_pid;
    parent_pid = getpid();
    printf("Parent PID is: %d\n", parent_pid);
    for (int i = 0; i < 5; i++) {
        child_pid = fork();
        printf("     Child PID is: %d\n", child_pid);
    }
    sleep(3);

    return 0;
}