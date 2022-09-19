#ifndef SRC_DOUBLY_LINKED_LISTS_H_
#define SRC_DOUBLY_LINKED_LISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


typedef struct node {
    char *name;
    int *grades;
    struct node *next;
    struct node *prev; 
} node_t;

typedef struct list {
    size_t size;
    node_t *head;
    node_t *tail; 
} list_t;

list_t* create_list();

void pop_back(list_t *list);
void push_back(list_t *list, char *name_new, int *grades_new);

void delete_list(list_t *list);

#endif //  SRC_DOUBLY_LINKED_LISTS_H_
