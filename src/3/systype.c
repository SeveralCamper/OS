#include "systype.h"

void oldman() {
    fprintf(stdout, "I'am not yet dead! My ID: %i\n", (int)getpid());
}

void reaction() {
    fprintf(stdout, "Who am I! My ID: %i\n", (int)getpid());
}

int main() {
    // Lab. 1 part
    // For test cases run without -Werror

    // pid_t child_pid;
    
    // First test
    /*pid_t parent_pid;
    int i = 0;
    fprintf(stdout, "Before REACTION %i\n", parent_pid=(int)getpid());

    child_pid = fork();

    while (i++ < 5) {
        if (child_pid != 0) {
            oldman();
        } else {
            reaction();
        }
    }

    // Second test

    double s = 0.0;
    FILE *fp;
    child_pid = fork();
    fp = fopen("test.dat","a+");

    if (child_pid != 0) {
        s += 3.14;
        fprintf(fp, "Child: %i s=%g & s=%lf fp=%u\n", (int)getpid(), s, s, fp);
    } else {
         s += 2.72;
        fprintf(fp, "Child: %i s=%g & s=%lf fp=%u\n", (int)getpid(), s, s, fp);        
    } */

    // Lab. 2 part

    /* pid_t child_pid;
    pid_t parent_pid;

    fprintf(stdout, "Before REACTION %i\n", parent_pid=(int)getpid());

    child_pid = fork();
    if (child_pid != 0) {
        oldman();
    }

    while(1) {

    } */

    // Lab. 3 part

    int i;
    int j;

    pid_t ppid;
    ppid = getpid();
    printf("I'm the parent, my PID is: %d\n", ppid);
    for (i = 0; i < 4; i++) {
        ppid = fork();
        if (ppid == 0) {
            printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
            for(j = 0; j < 2; j++) {
                ppid = fork();
                if (ppid == 0) {
                    printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
                    sleep(60);
                    printf("I'm process %d and I'm done\n", getpid());
                    exit(0);
                }
            }
            sleep(60);
            printf("I'm process %d and I'm done\n", getpid());
            exit(0);
        }   
    }

    return 0 ;
}