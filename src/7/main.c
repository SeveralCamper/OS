#include "stdio.h"
#include "../1/doubly_linked_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int main() {
    list_t *list = create_list();
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 0;
    printf("!!! PART I: PUSH BACK\n");
    for (int i = 0; i < 10; i++) {
        push_back(list, "ABCDE", arr, 5, 10);
        printf("\n");
        print_list(list, 10);
        printf("\n");
        for (int j = 0; j < 10; j++) {
            arr[j] = count + i;
            count++;
        }
    }
    pid_t pid_1;
    pid_1 = fork();
    printf("%d\n", pid_1);
    while(1) {

    }

    printf("!!! PART II: POP BACK\n");
    for (int i = 0; i < 10; i++) {
        pop_back(list);
        printf("\n");
        print_list(list, 10);
        printf("\n");
    }

    printf("!!! PART III: PUSH FRONT\n");
    for (int i = 0; i < 10; i++) {
        push_front(list, "ABCDE", arr, 5, 10);
        printf("\n");
        print_list(list, 10);
        printf("\n");
        for (int j = 0; j < 10; j++) {
            arr[j] = count + i;
            count++;
        }
    }  

    printf("!!! PART IV: POP FRONT\n");
    for (int i = 0; i < 10; i++) {
        pop_front(list);
        printf("\n");
        print_list(list, 10);
        printf("\n");
    }

    return 0;
}
